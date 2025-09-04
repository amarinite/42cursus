/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <amarquez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 11:00:01 by amarquez          #+#    #+#             */
/*   Updated: 2025/08/24 11:00:09 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

static void	read_heredoc_input(int tmp_file, char *delimiter)
{
	char	*line;
	int		len;

	while (1)
	{
		write(1, "> ", 2);
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		if (ft_strcmp(line, delimiter) == 0)
		{
			free(line);
			break ;
		}
		line[len - 1] = '\n';
		write(tmp_file, line, ft_strlen(line));
		free(line);
	}
}

void	heredoc(char **argv, t_pipex *pipex)
{
	int		tmp_file;
	char	*delimiter;

	pipex->heredoc = 1;
	delimiter = argv[2];
	tmp_file = open("tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (tmp_file < 0)
		perror("Error creating here_doc");
	read_heredoc_input(tmp_file, delimiter);
	close(tmp_file);
	pipex->infile = open("tmp", O_RDONLY);
	if (pipex->infile < 0)
	{
		unlink("tmp");
		perror("Error opening here_doc");
	}
}

void	set_infile(char *filename, t_pipex *pipex)
{
	pipex->infile = open(filename, O_RDONLY);
	if (pipex->infile < 0)
		perror("Invalid infile");
}

void	set_outfile(char *filename, t_pipex *pipex)
{
	if (pipex->heredoc)
		pipex->outfile = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		pipex->outfile = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->outfile < 0)
		perror("Invalid outfile");
}
