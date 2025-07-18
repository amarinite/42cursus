/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <amarquez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 12:40:12 by amarquez          #+#    #+#             */
/*   Updated: 2025/07/17 12:40:18 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	isometric(t_point *point)
{
	static double	cos_val;
	static double	sin_val;
	double			prev_x;
	double			prev_y;

	cos_val = -1;
	sin_val = -1;
	if (cos_val < 0)
	{
		cos_val = cos(0.523599);
		sin_val = sin(0.523599);
	}
	prev_x = point->x;
	prev_y = point->y;
	point->x = (prev_x - prev_y) * cos_val;
	point->y = (prev_x + prev_y) * sin_val - point->z;
}

t_point	transform(t_point p, int gap, int x_offset, int y_offset)
{
	int	original_color;

	original_color = p.color;
	p.x *= gap;
	p.y *= gap;
	isometric(&p);
	p.x += x_offset;
	p.y += y_offset;
	p.color = original_color;
	return (p);
}

void	draw_again(t_app *app)
{
	if (app->mlx_data->img.img != NULL)
		mlx_destroy_image(app->mlx_data->mlx, app->mlx_data->img.img);
	app->mlx_data->img.img = mlx_new_image(app->mlx_data->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	app->mlx_data->img.addr = mlx_get_data_addr(app->mlx_data->img.img,
			&app->mlx_data->img.bits_per_pixel,
			&app->mlx_data->img.line_length, &app->mlx_data->img.endian);
	draw_map_points(app->map, app->current_gap, app->mlx_data->img);
	mlx_put_image_to_window(app->mlx_data->mlx,
		app->mlx_data->mlx_win, app->mlx_data->img.img, 0, 0);
}
