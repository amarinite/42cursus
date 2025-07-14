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
#include <unistd.h>

int	calc_columns(char *line)
{
	char	**line_splitted;
	int		i;
	int		len;
	int		cols;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	line_splitted = ft_split(line, ' ');
	cols = 0;
	while (line_splitted[cols])
		(cols)++;
	i = 0;
	while (line_splitted[i])
	{
		free(line_splitted[i]);
		i++;
	}
	free(line_splitted);
	return (cols);
}

int	calc_rows(int fd, char *line)
{
	int		rows;

	rows = 0;
	while (line != NULL)
	{
		// USAR SPLIT PARA VER SI EL ARRAY ES EL MISMO SIZE QUE COLS TODAS LAS ROWS
		rows++;
		free(line);
		line = get_next_line(fd);
	}
	return (rows);
}

int	calc_mapsize(char *mapname, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(mapname, O_RDONLY);
	if (fd < 0)
		return (perror("Error opening file"), ERROR);
	line = get_next_line(fd);
	if (line != NULL)
	{
		map->columns = calc_columns(line);
		map->rows = calc_rows(fd, line);
	}
	close(fd);
	return (0);
}

int	calc_z(char *line, int column, int *z)
{
	char	**line_splitted;
	int		i;

	if (!line || !z)
		return (perror("Invalid input to calc_z"), ERROR);
	line_splitted = ft_split(line, ' ');
	if (!line_splitted || !line_splitted[column])
	{
		perror("Error calculating z");
		if (line_splitted)
		{
			i = 0;
			while (line_splitted[i])
				free(line_splitted[i++]);
			free(line_splitted);
		}
		return (ERROR);
	}
	*z = ft_atoi(line_splitted[column]);
	i = 0;
	while (line_splitted[i])
		free(line_splitted[i++]);
	free(line_splitted);
	return (0);
}

int	allocate_map_points(t_map *map)
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

int	populate_map_data(char *mapname, t_map *map)
{
	int		fd;
	int		i;
	int		j;
	char	*line;
	int		z;

	if (!map)
		return (perror("No map to populate"), ERROR);
	fd = open(mapname, O_RDONLY);
	if (fd < 0)
		return (perror("Error opening file"), ERROR);
	i = 0;
	while (i < map->rows)
	{
		line = get_next_line(fd);
		if (!line)
		{
			return (close(fd), perror("Unexpected EOF while reading map"), ERROR);
		}
		if (line[0] == '\0')
			return (free(line), close(fd), 0);
		j = 0;
		while (j < map->columns)
		{
			map->points[i][j].x = j;
			map->points[i][j].y = i;
			if (calc_z(line, j, &z) != 0)
			{
				free(line);
				close(fd);
				return (ERROR);
			}
			map->points[i][j].z = z;
			j++;
		}
		free(line);
		i++;
	}
	line = get_next_line(fd);
	if (line)
		free(line);
	close(fd);
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
