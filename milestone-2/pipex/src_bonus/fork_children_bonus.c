/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_children.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <amarquez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 16:15:17 by amarquez          #+#    #+#             */
/*   Updated: 2025/08/24 16:15:18 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

static void	setup_first_cmd_fds(t_pipex *pipex)
{
	if (pipex->infile < 0)
	{
		perror("Input file error");
		cleanup_child(pipex);
		exit(EXIT_FAILURE);
	}
	dup2(pipex->infile, 0);
	dup2(pipex->pipe[1], 1);
}

static void	setup_middle_cmd_fds(t_pipex *pipex)
{
	int	read_fd;
	int	write_fd;

	read_fd = pipex->pipe[2 * (pipex->pipe_idx - 1)];
	write_fd = pipex->pipe[2 * pipex->pipe_idx + 1];
	dup2(read_fd, 0);
	dup2(write_fd, 1);
}

static void	setup_last_cmd_fds(t_pipex *pipex)
{
	dup2(pipex->pipe[2 * (pipex->num_cmds - 2)], 0);
	if (pipex->outfile >= 0)
		dup2(pipex->outfile, 1);
	else
		close(1);
}

static void	setup_child_fds(t_pipex *pipex)
{
	if (pipex->pipe_idx == 0)
		setup_first_cmd_fds(pipex);
	else if (pipex->pipe_idx == pipex->num_cmds - 1)
		setup_last_cmd_fds(pipex);
	else
		setup_middle_cmd_fds(pipex);
}

void	fork_children(char **argv, t_pipex *pipex, char **envp)
{
	pipex->pid = fork();
	pipex->child_pids[pipex->pipe_idx] = pipex->pid;
	if (pipex->pid == 0)
	{
		setup_child_fds(pipex);
		close_pipes(pipex);
		set_cmd(argv, pipex);
		if (!pipex->cmd)
		{
			if (pipex->cmd_flags && pipex->cmd_flags[0])
				perror("command not found");
			cleanup_child(pipex);
			exit(127);
		}
		execve(pipex->cmd, pipex->cmd_flags, envp);
		cleanup_child(pipex);
		if (pipex->cmd)
			free(pipex->cmd);
		perror("execve failed");
		exit(127);
	}
}
