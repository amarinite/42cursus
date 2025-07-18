/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <amarquez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:44:41 by amarquez          #+#    #+#             */
/*   Updated: 2025/07/10 12:44:43 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_zoom(int mouse, int x, int y, t_app *app)
{
	(void)x;
	(void)y;
	if (mouse == 4 && (app->current_gap + 5) < 100)
	{
		if (app->current_gap == 2)
			app->current_gap = 5;
		else
			app->current_gap += 5;
		draw_again(app);
	}
	else if (mouse == 5)
	{
		if (app->current_gap == 5)
			app->current_gap = 2;
		else if ((app->current_gap - 5) > 0)
			app->current_gap -= 5;
		draw_again(app);
	}
	return (0);
}

int	handle_keypress(int keysym, t_app *app)
{
	if (keysym == XK_Escape)
		close_fdf(app);
	return (0);
}

int	handle_window_close(t_app *app)
{
	close_fdf(app);
	return (0);
}
