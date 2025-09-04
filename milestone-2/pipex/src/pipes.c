/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <amarquez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 11:08:18 by amarquez          #+#    #+#             */
/*   Updated: 2025/08/25 11:08:21 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static void	allocate_pipes(t_pipex *pipex)
{
	pipex->num_pipe_fds = (pipex->num_cmds - 1) * 2;
	pipex->pipe = malloc(pipex->num_pipe_fds * sizeof(int));
	if (!pipex->pipe)
	{
		perror("Memory allocation failed for pipes");
		exit(EXIT_FAILURE);
	}
	pipex->pipe_idx = 0;
}

static void	create_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < (pipex->num_cmds - 1))
	{
		if (pipe(pipex->pipe + 2 * i) < 0)
		{
			perror("Pipe creation failed");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

static void	allocate_child_pids(t_pipex *pipex)
{
	pipex->child_pids = malloc(pipex->num_cmds * sizeof(pid_t));
	if (!pipex->child_pids)
	{
		perror("Memory allocation failed for child_pids");
		exit(EXIT_FAILURE);
	}
}

void	set_pipes(t_pipex *pipex)
{
	allocate_pipes(pipex);
	create_pipes(pipex);
	allocate_child_pids(pipex);
}

void	close_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < (pipex->num_pipe_fds))
	{
		close(pipex->pipe[i]);
		i++;
	}
}
