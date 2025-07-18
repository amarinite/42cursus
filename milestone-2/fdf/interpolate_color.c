/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpolate_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <amarquez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:46:10 by amarquez          #+#    #+#             */
/*   Updated: 2025/07/17 10:46:12 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_rgb	extract_rgb(int color)
{
	t_rgb	rgb;

	rgb.r = (color >> 16) & 0xFF;
	rgb.g = (color >> 8) & 0xFF;
	rgb.b = color & 0xFF;
	return (rgb);
}

static int	rgb_to_color(t_rgb rgb)
{
	return ((rgb.r << 16) | (rgb.g << 8) | rgb.b);
}

int	interpolate_color(int color1, int color2, double t)
{
	t_rgb	c1;
	t_rgb	c2;
	t_rgb	result;

	c1 = extract_rgb(color1);
	c2 = extract_rgb(color2);
	result.r = (int)(c1.r + t * (c2.r - c1.r));
	result.g = (int)(c1.g + t * (c2.g - c1.g));
	result.b = (int)(c1.b + t * (c2.b - c1.b));
	return (rgb_to_color(result));
}
