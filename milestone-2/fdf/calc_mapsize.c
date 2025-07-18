/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_mapsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <amarquez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 11:20:34 by amarquez          #+#    #+#             */
/*   Updated: 2025/07/17 11:20:36 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	skip_whitespace(char **p)
{
	while (**p == ' ' || **p == '\t' || **p == '\n' || **p == '\r')
		(*p)++;
}

static int	calc_columns(char *line)
{
	char	**line_splitted;
	int		i;
	int		len;
	int		cols;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	line_splitted = ft_split(line, ' ');
	cols = 0;
	while (line_splitted[cols])
		(cols)++;
	i = 0;
	while (line_splitted[i])
	{
		free(line_splitted[i]);
		i++;
	}
	free(line_splitted);
	return (cols);
}

static int	check_col_count(char *line)
{
	int		cols;
	int		len;
	char	*ptr;

	if (!line)
		return (0);
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	cols = 0;
	ptr = line;
	while (*ptr)
	{
		skip_whitespace(&ptr);
		if (*ptr)
		{
			cols++;
			while (*ptr && *ptr != ' ' && *ptr != '\t')
				ptr++;
		}
	}
	return (cols);
}

static int	calc_rows(int fd, char *line, int expected_columns)
{
	int		rows;
	int		current_columns;

	rows = 0;
	while (line != NULL)
	{
		current_columns = check_col_count(line);
		if (current_columns != expected_columns)
		{
			free(line);
			return (perror("Inconsistent row size in map"), ERROR);
		}
		rows++;
		free(line);
		line = get_next_line(fd);
	}
	return (rows);
}

int	calc_mapsize(char *mapname, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(mapname, O_RDONLY);
	if (fd < 0)
		return (perror("Error opening file"), ERROR);
	line = get_next_line(fd);
	if (line != NULL)
	{
		map->columns = calc_columns(line);
		map->rows = calc_rows(fd, line, map->columns);
		if (map->rows == ERROR)
		{
			close(fd);
			return (ERROR);
		}
	}
	close(fd);
	return (0);
}
