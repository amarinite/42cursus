/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connecting_dots.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <amarquez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 11:07:00 by amarquez          #+#    #+#             */
/*   Updated: 2025/07/10 11:07:03 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_bresenham	init_bresenham(t_point start, t_point end)
{
	t_bresenham	b;

	b.dx = abs(end.x - start.x);
	b.dy = abs(end.y - start.y);
	if (start.x < end.x)
		b.step_x = 1;
	else
		b.step_x = -1;
	if (start.y < end.y)
		b.step_y = 1;
	else
		b.step_y = -1;
	b.err = b.dx - b.dy;
	return (b);
}

static void	update_bresenham_step(t_bresenham *b, int *x, int *y)
{
	int	e2;

	e2 = 2 * b->err;
	if (e2 > -(b->dy))
	{
		b->err -= b->dy;
		*x += b->step_x;
	}
	if (e2 < b->dx)
	{
		b->err += b->dx;
		*y += b->step_y;
	}
}

void	draw_line(t_point start, t_point end, t_data img)
{
	t_bresenham	b;
	int			x;
	int			y;
	int			total_steps;
	int			current_step;

	current_step = 0;
	b = init_bresenham(start, end);
	x = start.x;
	y = start.y;
	total_steps = abs(end.x - start.x) + abs(end.y - start.y);
	if (total_steps == 0)
		total_steps = 1;
	while (1)
	{
		my_pixel_put(&img, x, y, interpolate_color(start.color, end.color,
				(double)current_step / total_steps));
		if (x == end.x && y == end.y)
			break ;
		update_bresenham_step(&b, &x, &y);
		current_step++;
	}
}
