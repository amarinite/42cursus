/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <amarquez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:40:39 by amarquez          #+#    #+#             */
/*   Updated: 2025/07/09 16:40:42 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	allocate_map_points(t_map *map)
{
	int	i;

	if (!map)
		return (perror("No map to allocate"), ERROR);
	if (map->rows > 0 && map->columns > 0)
	{
		i = 0;
		map->points = (t_point **)malloc(map->rows * sizeof(t_point *));
		if (!map->points)
			return (perror("Malloc failed for map->points"), ERROR);
		while (i < map->rows)
		{
			map->points[i] = (t_point *)malloc(map->columns * sizeof(t_point));
			if (!map->points[i])
			{
				while (--i >= 0)
					free(map->points[i]);
				free(map->points);
				return (perror("Malloc failed for map->points[i]"), ERROR);
			}
			i++;
		}
	}
	return (0);
}

int	parse_map(char *filename, t_map **map)
{
	if (!filename)
		return (perror("Invalid map"), ERROR);
	*map = create_map();
	if (!*map)
		return (perror("Map creation failed"), ERROR);
	if (calc_mapsize(filename, *map) != 0)
	{
		free_map(*map);
		return (ERROR);
	}
	if (allocate_map_points(*map) != 0)
	{
		free_map(*map);
		return (ERROR);
	}
	if (populate_map_data(filename, *map) != 0)
	{
		free_map(*map);
		return (ERROR);
	}
	return (0);
}
