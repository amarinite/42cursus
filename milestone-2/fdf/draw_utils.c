#include "fdf.h"

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

void  isometric(t_point *point)
{
	double prev_x = point->x;
	double prev_y = point->y;

	point->x = (prev_x - prev_y) * cos(0.523599);
	point->y = (prev_x + prev_y) * sin(0.523599) - point->z;
}

void	draw_map_points(t_map *map, int gap, t_data img)
{
	t_point	curr;
	t_point	left;
	t_point	top;
	int		i;
	int		j;
	int x_offset = WINDOW_WIDTH / 2;
	int y_offset = WINDOW_HEIGHT / 4;

	if (!map || !map->points)
		return ;
	i = 0;
	curr = map->points[0][0];
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			curr = map->points[i][j];
			isometric(&curr);
			curr.x *= gap;
			curr.y *= gap;

			curr.x += x_offset;
			curr.y += y_offset;
			if (j > 0)
			{
				left = map->points[i][j - 1];
				isometric(&left);
				left.x *= gap;
				left.y *= gap;

				left.x += x_offset;
				left.y += y_offset;
				draw_line(left, curr, img);
			}
			if (i > 0)
			{
				top = map->points[i - 1][j];
				isometric(&top);
				top.x *= gap;
				top.y *= gap;

				top.x += x_offset;
				top.y += y_offset;
				draw_line(top, curr, img);
			}
			j++;
		}
		i++;
	}
}
/*
void	old_draw_map_points(t_map *map, int gap, t_data img)
{
	t_point	*point;
	int	x;
	int	y;

	point = initialize_point(0, 0, 0);
	while (point->y < map->rows && point->y * gap < WINDOW_HEIGHT)
	{
    	while (point->x < map->columns && point->x * gap < WINDOW_WIDTH)
     	{
        	x = point->x;
         	y = point->y;
          	if (x > 0)
            	draw_line(x * gap, (x - 1) * gap, y * gap, y * gap, img);
           if (y > 0)
            	draw_line(x * gap, x * gap, y * gap, (y - 1) * gap, img);
           point->x++;
      }
      point->x = 0;
      point->y++;
	}
	free(point);
}
 */
