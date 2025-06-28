/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <amarquez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:47:02 by amarquez          #+#    #+#             */
/*   Updated: 2025/06/04 16:05:18 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif



static int	read_and_store(int fd, t_buffer **stash)
{
	char		*buffer;
	ssize_t		bytes_read;
	t_buffer	*new_node;
	t_buffer	*current;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(buffer);
		return (0);
	}
	buffer[bytes_read] = '\0';
	new_node = malloc(sizeof(t_buffer));
	if (!new_node)
	{
		free(buffer);
		return (0);
	}
	new_node->content = ft_strdup(buffer);
	new_node->next = NULL;
	free(buffer);
	if (!new_node->content)
	{
		free(new_node);
		return (0);
	}
	if (!*stash)
		*stash = new_node;
	else
	{
		current = *stash;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
	return (1);
}

static char	*extract_line_and_trim(t_buffer **stash)
{
	int			line_len;
	t_buffer	*current;
	char		*newline_pos;
	char		*line;
	t_buffer	*last;
	char		*s;
	int			i;
	char		*newline;
	t_buffer	*new_node;
	char		*remaining;

	line_len = 0;
	current = *stash;
	newline_pos = NULL;
	if (!*stash)
		return (NULL);
	while (current && !newline_pos)
	{
		newline_pos = ft_strchr(current->content, '\n');
		if (newline_pos)
			line_len += (newline_pos - current->content) + 1;
		else
		{
			s = current->content;
			while (*s)
			{
				line_len++;
				s++;
			}
		}
		current = current->next;
	}
	line = malloc(line_len + 1);
	if (!line)
		return (NULL);
	i = 0;
	current = *stash;
	while (current && i < line_len)
	{
		s = current->content;
		while (*s && i < line_len)
		{
			line[i++] = *s++;
			if (line[i - 1] == '\n')
				break ;
		}
		current = current->next;
	}
	line[i] = '\0';
	last = *stash;
	while (last->next)
		last = last->next;
	newline = ft_strchr(last->content, '\n');
	if (newline && *(newline + 1))
	{
		remaining = ft_strdup(newline + 1);
		clear_stash(stash);
		if (remaining && *remaining)
		{
			new_node = malloc(sizeof(t_buffer));
			if (new_node)
			{
				new_node->content = remaining;
				new_node->next = NULL;
				*stash = new_node;
			}
			else
				free(remaining);
		}
		else
			free(remaining);
	}
	else
		clear_stash(stash);
	return (line);
}

char	*get_next_line(int fd)
{
	static t_buffer	*stash = NULL;
	t_buffer		*current;
	int				has_newline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		current = stash;
		has_newline = 0;
		while (current && !has_newline)
		{
			if (ft_strchr(current->content, '\n'))
				has_newline = 1;
			current = current->next;
		}
		if (has_newline)
			break ;
		if (!read_and_store(fd, &stash))
		{
			if (!stash)
				return (NULL);
			break ;
		}
	}
	return (extract_line_and_trim(&stash));
}
/*
int	ft_open(char *filename)
{
	int	fd_to_read;

	fd_to_read = open(filename, O_RDONLY);
	if (fd_to_read == -1)
	{
		printf("Couldn't open file.\n");
		return (-1);
	}
	return (fd_to_read);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("file.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
*/
