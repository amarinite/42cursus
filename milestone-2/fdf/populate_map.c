/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <amarquez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 12:34:19 by amarquez          #+#    #+#             */
/*   Updated: 2025/07/17 12:34:21 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	assign_colors_to_map(t_map *map)
{
	int		i;
	int		j;
	int		minz;
	int		maxz;
	double	norm_h;

	minz = map->min_z;
	maxz = map->max_z;
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			norm_h = 0.0;
			if (maxz != minz)
				norm_h = (double)(map->points[i][j].z - minz) / (maxz - minz);
			map->points[i][j].color = calculate_color(norm_h);
			j++;
		}
		i++;
	}
}

static void	parse_row(char *line, t_map *map, int row_index)
{
	char	*ptr;
	int		j;
	int		z_value;

	ptr = line;
	j = 0;
	while (j < map->columns && *ptr)
	{
		z_value = parse_map_int(&ptr);
		map->points[row_index][j].x = j;
		map->points[row_index][j].y = row_index;
		map->points[row_index][j].z = z_value;
		if (z_value < map->min_z)
			map->min_z = z_value;
		if (z_value > map->max_z)
			map->max_z = z_value;
		while (*ptr && *ptr != ' ' && *ptr != '\t' && *ptr != '\n')
			ptr++;
		j++;
	}
}

static void	cleanup_and_close(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (line)
		free(line);
	close(fd);
}

int	populate_map_data(char *mapname, t_map *map)
{
	int		fd;
	int		i;
	char	*line;

	if (!map)
		return (perror("No map to populate"), ERROR);
	fd = open(mapname, O_RDONLY);
	if (fd < 0)
		return (perror("Error opening file"), ERROR);
	map->min_z = INT_MAX;
	map->max_z = INT_MIN;
	i = 0;
	while (i < map->rows)
	{
		line = get_next_line(fd);
		if (!line)
			return (close(fd), perror("Unexpected EOF"), ERROR);
		if (line[0] == '\0')
			return (free(line), close(fd), 0);
		parse_row(line, map, i);
		free(line);
		i++;
	}
	return (assign_colors_to_map(map), cleanup_and_close(fd), 0);
}
