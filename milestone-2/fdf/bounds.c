/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bounds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <amarquez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:19:18 by amarquez          #+#    #+#             */
/*   Updated: 2025/07/17 13:19:22 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_bounds	initialize_bounds(t_map *map, int gap)
{
	t_bounds	bounds;
	t_point		curr;
	t_point		first_point;

	curr = map->points[0][0];
	first_point = transform(curr, gap, 0, 0);
	bounds.min_x = first_point.x;
	bounds.max_x = first_point.x;
	bounds.min_y = first_point.y;
	bounds.max_y = first_point.y;
	return (bounds);
}

static void	update_bounds(t_bounds *bounds, t_point point)
{
	if (point.x < bounds->min_x)
		bounds->min_x = point.x;
	if (point.x > bounds->max_x)
		bounds->max_x = point.x;
	if (point.y < bounds->min_y)
		bounds->min_y = point.y;
	if (point.y > bounds->max_y)
		bounds->max_y = point.y;
}

t_bounds	calculate_bounds(t_map *map, int gap)
{
	t_bounds	bounds;
	t_point		curr;
	int			i;
	int			j;

	bounds = initialize_bounds(map, gap);
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			curr = transform(map->points[i][j], gap, 0, 0);
			update_bounds(&bounds, curr);
			j++;
		}
		i++;
	}
	return (bounds);
}
