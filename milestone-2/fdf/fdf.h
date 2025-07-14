#ifndef FDF_H
# define FDF_H
# define ERROR	1
# define WINDOW_WIDTH	3048
# define WINDOW_HEIGHT	1656
# define MAP_GAP		30

# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <X11/keysym.h>

# include "mlx/mlx.h"
# include "libft/libft.h"
# include "gnl/get_next_line.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct	s_point {
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_map {
    int	columns;
    int	rows;
    t_point	**points;
} t_map;

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
}	t_app;

void	my_pixel_put(t_data *data, int x, int y, int color);
t_point	*initialize_point(int x, int y, int z);
t_map	*create_map(void);
int		calc_columns(char *line);
int		calc_rows(int fd, char *line);
int		calc_mapsize(char *mapname, t_map *map);
int		allocate_map_points(t_map *map);
int		parse_map(char *filename, t_map **map);
void	draw_line(t_point prev, t_point curr, t_data img);
void	draw_map_points(t_map *map, int gap, t_data img);
void	free_map(t_map *map);
int		handle_no_event(void *data);
int		handle_keypress(int keysym, t_app *app);
int		close_fdf(t_app *app);

#endif
