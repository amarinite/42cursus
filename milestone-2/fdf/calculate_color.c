/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <amarquez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:46:22 by amarquez          #+#    #+#             */
/*   Updated: 2025/07/17 10:46:24 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_low_color(double h, int *r, int *g, int *b)
{
	*r = (int)(255 - h * 4 * 50);
	*g = (int)(180 + h * 4 * 50);
	*b = (int)(200 + h * 4 * 40);
}

static void	set_mid_low_color(double h, int *r, int *g, int *b)
{
	*r = (int)(205 + (h - 0.25) * 4 * 50);
	*g = (int)(230 + (h - 0.25) * 4 * 25);
	*b = (int)(240 - (h - 0.25) * 4 * 140);
}

static void	set_mid_high_color(double h, int *r, int *g, int *b)
{
	*r = (int)(255 - (h - 0.5) * 4 * 100);
	*g = 255;
	*b = (int)(100 + (h - 0.5) * 4 * 155);
}

int	calculate_color(double normalized_height)
{
	int	red;
	int	green;
	int	blue;

	red = 0;
	green = 0;
	blue = 0;
	if (normalized_height <= 0.25)
		set_low_color(normalized_height, &red, &green, &blue);
	else if (normalized_height <= 0.5)
		set_mid_low_color(normalized_height, &red, &green, &blue);
	else if (normalized_height <= 0.75)
		set_mid_high_color(normalized_height, &red, &green, &blue);
	else
		red = 255;
	return ((red << 16) | (green << 8) | blue);
}
