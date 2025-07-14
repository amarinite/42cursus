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

// NO VALE
t_point	*initialize_point(int x, int y, int z)
{
	t_point	*newpoint;

	newpoint = (t_point *)malloc(sizeof(t_point));
	if (!newpoint)
		return (NULL);
	newpoint->x = x;
	newpoint->y = y;
	newpoint->z = z;
	return (newpoint);
}

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
