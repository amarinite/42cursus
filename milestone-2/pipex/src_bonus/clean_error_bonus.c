/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <amarquez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 13:10:29 by amarquez          #+#    #+#             */
/*   Updated: 2025/08/24 13:10:31 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	args_error(int argc, char **argv)
{
	int	i;

	if (argc <= 4)
	{
		perror("Program takes at least 4 parameters: infile cmd1 cmd2 outfile");
		exit(EXIT_FAILURE);
	}
	i = 1;
	while (i < argc)
	{
		if (!argv[i] || argv[i][0] == '\0')
		{
			perror("Empty argument detected");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	clean_paths(t_pipex *pipex)
{
	int	i;

	if (pipex->paths)
	{
		i = 0;
		while (pipex->paths[i])
		{
			free(pipex->paths[i]);
			i++;
		}
		free(pipex->paths);
		pipex->paths = NULL;
	}
}

void	clean_cmd_flags(t_pipex *pipex)
{
	int	i;

	if (pipex->cmd_flags)
	{
		i = 0;
		while (pipex->cmd_flags[i])
		{
			free(pipex->cmd_flags[i]);
			i++;
		}
		free(pipex->cmd_flags);
		pipex->cmd_flags = NULL;
	}
}

void	cleanup(t_pipex *pipex)
{
	close(pipex->infile);
	close(pipex->outfile);
	if (pipex->heredoc)
		unlink("tmp");
	clean_paths(pipex);
	clean_cmd_flags(pipex);
	if (pipex->cmd)
		free(pipex->cmd);
	if (pipex->pipe)
		free(pipex->pipe);
	if (pipex->child_pids)
		free(pipex->child_pids);
}

void	cleanup_child(t_pipex *pipex)
{
	clean_cmd_flags(pipex);
	if (pipex->heredoc)
		unlink("tmp");
	if (pipex->cmd)
		free(pipex->cmd);
	clean_paths(pipex);
	if (pipex->pipe)
		free(pipex->pipe);
	if (pipex->child_pids)
		free(pipex->child_pids);
}
