/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <amarquez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:46:40 by amarquez          #+#    #+#             */
/*   Updated: 2025/07/09 16:46:43 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*create_map(void)
{
	t_map	*newmap;

	newmap = (t_map *)malloc(sizeof(t_map));
	if (!newmap)
		return (NULL);
	newmap->rows = 0;
	newmap->columns = 0;
	newmap->points = NULL;
	return (newmap);
}

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->points)
	{
		i = 0;
		while (i < map->rows)
		{
			free(map->points[i]);
			i++;
		}
		free(map->points);
	}
	free(map);
}
