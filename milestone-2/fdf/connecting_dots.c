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

int	abs(int num)
{
	if (num >= 0)
		return (num);
	return (num * -1);
}

void	draw_line(t_point prev, t_point curr, t_data img)
{
	int		dx;
	int		dy;
	int		steps;
	double	x_inc;
	double	y_inc;

	dx = curr.x - prev.x;
	dy = curr.y - prev.y;
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	/*if (steps == 0)
	{
		my_pixel_put(&img, prev.x, prev.y, 0xFFFFFFFF);
		return;
		}*/
	x_inc = dx / (double) steps;
	y_inc = dy / (double) steps;
	while (steps >= 0)
	{
		my_pixel_put(&img, round(prev.x), round(prev.y), 0xFFFFFFFF);
		prev.x += x_inc;
		prev.y += y_inc;
		steps--;
	}
}
