/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <amarquez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 13:09:57 by amarquez          #+#    #+#             */
/*   Updated: 2025/08/24 13:09:59 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	set_paths(char **envp, t_pipex *pipex)
{
	char	*path_env;

	while (ft_strncmp("PATH=", *envp, 5))
		envp++;
	path_env = *envp + 5;
	pipex->paths = ft_split(path_env, ':');
	if (!pipex->paths)
	{
		cleanup(pipex);
		perror("Error creating paths");
		exit(EXIT_FAILURE);
	}
}

void	set_num_cmds(int argc, t_pipex *pipex)
{
	pipex->num_cmds = argc - 3;
}

char	*access_cmd(t_pipex *pipex)
{
	char	**paths;
	char	*cmd_name;
	char	*full_path;
	char	*tmp;

	paths = pipex->paths;
	cmd_name = pipex->cmd_flags[0];
	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		full_path = ft_strjoin(tmp, cmd_name);
		free(tmp);
		if (access(full_path, 0) == 0)
			return (full_path);
		free(full_path);
		paths++;
	}
	return (NULL);
}

void	set_cmd(char **argv, t_pipex *pipex)
{
	pipex->cmd_flags = ft_split(argv[pipex->pipe_idx + 2], ' ');
	if (!pipex->cmd_flags)
	{
		pipex->cmd = NULL;
		return ;
	}
	pipex->cmd = access_cmd(pipex);
}
