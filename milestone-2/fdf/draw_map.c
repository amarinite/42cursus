/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <amarquez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 12:59:53 by amarquez          #+#    #+#             */
/*   Updated: 2025/07/17 12:59:57 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_offset	calculate_centering_offset(t_bounds bounds)
{
	t_offset	offset;
	int			map_center_x;
	int			map_center_y;
	int			window_center_x;
	int			window_center_y;

	map_center_x = (bounds.min_x + bounds.max_x) / 2;
	map_center_y = (bounds.min_y + bounds.max_y) / 2;
	window_center_x = WINDOW_WIDTH / 2;
	window_center_y = WINDOW_HEIGHT / 2;
	offset.x = window_center_x - map_center_x;
	offset.y = window_center_y - map_center_y;
	return (offset);
}

static void	draw_all_lines(t_map *map, int gap, t_offset offset, t_data img)
{
	t_point	curr;
	int		i;
	int		j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			curr = transform(map->points[i][j], gap, offset.x, offset.y);
			if (j > 0)
				draw_line(transform(map->points[i][j - 1], gap,
						offset.x, offset.y), curr, img);
			if (i > 0)
				draw_line(curr, transform(map->points[i - 1][j], gap,
						offset.x, offset.y), img);
			j++;
		}
		i++;
	}
}

void	draw_map_points(t_map *map, int gap, t_data img)
{
	t_offset	offset;
	t_bounds	bounds;

	if (!map || !map->points)
		return ;
	bounds = calculate_bounds(map, gap);
	offset = calculate_centering_offset(bounds);
	draw_all_lines(map, gap, offset, img);
}
