/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <amarquez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:28:21 by amarquez          #+#    #+#             */
/*   Updated: 2025/08/11 12:28:23 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

static void	init_pipex(t_pipex *pipex)
{
	pipex->infile = -1;
	pipex->outfile = -1;
	pipex->heredoc = 0;
	pipex->paths = NULL;
	pipex->num_cmds = 0;
	pipex->num_pipe_fds = 0;
	pipex->cmd = NULL;
	pipex->cmd_flags = NULL;
	pipex->pipe = NULL;
	pipex->pipe_idx = -1;
	pipex->pid = -1;
	pipex->child_pids = NULL;
}

static int	wait_for_children(t_pipex *pipex)
{
	int		status;
	pid_t	last_pid;
	pid_t	waited_pid;
	int		last_cmd_status;
	int		i;

	last_pid = pipex->child_pids[pipex->num_cmds - 1];
	last_cmd_status = 0;
	i = 0;
	while (i < pipex->num_cmds)
	{
		waited_pid = waitpid(-1, &status, 0);
		if (waited_pid == last_pid && WIFEXITED(status))
			last_cmd_status = WEXITSTATUS(status);
		else if (waited_pid == last_pid)
			last_cmd_status = 1;
		i++;
	}
	return (last_cmd_status);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	pid_t	last_pid;
	int		last_cmd_status;

	args_error(argc, argv);
	init_pipex(&pipex);
	if (ft_strcmp("here_doc", argv[1]) == 0)
		heredoc(argv, &pipex);
	else
		set_infile(argv[1], &pipex);
	set_outfile(argv[argc - 1], &pipex);
	set_paths(envp, &pipex);
	set_num_cmds(argc, &pipex);
	set_pipes(&pipex);
	while (pipex.pipe_idx < pipex.num_cmds)
	{
		fork_children(argv, &pipex, envp);
		pipex.pipe_idx++;
	}
	close_pipes(&pipex);
	last_pid = pipex.child_pids[pipex.num_cmds - 1];
	last_cmd_status = wait_for_children(&pipex);
	cleanup(&pipex);
	return (last_cmd_status);
}
