/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <amarquez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:41:12 by amarquez          #+#    #+#             */
/*   Updated: 2025/07/16 11:41:13 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define ERROR	1
# define WINDOW_WIDTH	3248
# define WINDOW_HEIGHT	1856
# define MAP_GAP		30

# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include <limits.h>

# include "mlx/mlx.h"
# include "libft/libft.h"
# include "gnl/get_next_line.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_bresenham
{
	int	dx;
	int	dy;
	int	step_x;
	int	step_y;
	int	err;
}	t_bresenham;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_bounds
{
	int	min_x;
	int	max_x;
	int	min_y;
	int	max_y;
}	t_bounds;

typedef struct s_offset
{
	int	x;
	int	y;
}	t_offset;

typedef struct s_map
{
	int		columns;
	int		rows;
	t_point	**points;
	int		min_z;
	int		max_z;
}	t_map;

typedef struct s_mlx_data
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
}	t_mlx_data;

typedef struct s_app
{
	t_map		*map;
	t_mlx_data	*mlx_data;
	int			current_gap;
}	t_app;

void		my_pixel_put(t_data *data, int x, int y, int color);
t_point		*initialize_point(int x, int y, int z);
t_map		*create_map(void);
int			calc_mapsize(char *mapname, t_map *map);
int			parse_map(char *filename, t_map **map);
int			parse_map_int(char **ptr);
void		skip_whitespace(char **p);
int			interpolate_color(int color1, int color2, double t);
int			calculate_color(double normalized_height);
int			populate_map_data(char *mapname, t_map *map);
void		draw_line(t_point prev, t_point curr, t_data img);
t_point		transform(t_point p, int gap, int x_offset, int y_offset);
t_bounds	calculate_bounds(t_map *map, int gap);
void		draw_map_points(t_map *map, int gap, t_data img);
void		draw_again(t_app *app);
void		free_map(t_map *map);
int			handle_no_event(void *data);
int			handle_zoom(int mouse, int x, int y, t_app *app);
int			handle_keypress(int keysym, t_app *app);
int			handle_window_close(t_app *app);
int			close_fdf(t_app *app);

#endif
