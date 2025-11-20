/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <amarquez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 17:02:58 by amarquez          #+#    #+#             */
/*   Updated: 2025/08/26 17:03:00 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "../../../milestone-0/libft/libft.h"

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		heredoc;
	char	**paths;
	int		num_cmds;
	int		num_pipe_fds;
	char	*cmd;
	char	**cmd_flags;
	int		*pipe;
	int		pipe_idx;
	pid_t	pid;
	pid_t	*child_pids;
}	t_pipex;

void	args_error(int argc, char **argv);
void	set_infile(char *filename, t_pipex *pipex);
void	set_outfile(char *filename, t_pipex *pipex);
void	heredoc(char **argv, t_pipex *pipex);
void	set_paths(char **envp, t_pipex *pipex);
void	set_num_cmds(int argc, t_pipex *pipex);
void	set_cmd(char **argv, t_pipex *pipex);
void	set_pipes(t_pipex *pipex);
void	close_pipes(t_pipex *pipex);
void	fork_children(char **argv, t_pipex *pipex, char **envp);
void	cleanup(t_pipex *pipex);
void	cleanup_child(t_pipex *pipex);

#endif
