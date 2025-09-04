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

#include "../inc/pipex.h"

void	set_infile(char *filename, t_pipex *pipex)
{
	pipex->infile = open(filename, O_RDONLY);
	if (pipex->infile < 0)
		perror("Invalid infile");
}

void	set_outfile(char *filename, t_pipex *pipex)
{
	pipex->outfile = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0000644);
	if (pipex->outfile < 0)
		perror("Invalid outfile");
}
