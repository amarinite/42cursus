/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <amarquez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:12:07 by amarquez          #+#    #+#             */
/*   Updated: 2025/07/09 16:12:11 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	setup(void **mlx, void **mlx_win, t_data *img)
{
	*mlx = mlx_init();
	if (*mlx == NULL)
		return (perror("Malloc error on mlx init"), ERROR);
	*mlx_win = mlx_new_window(*mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	if (*mlx_win == NULL)
	{
		mlx_destroy_display(*mlx);
		free(*mlx);
		return (perror("Malloc error on new window"), ERROR);
	}
	img->img = mlx_new_image(*mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	return (0);
}

void	cleanup_fdf(t_app *app)
{
	if (!app)
		return ;
	if (app->map)
		free_map(app->map);
	if (app->mlx_data)
	{
		if (app->mlx_data->img.img != NULL)
			mlx_destroy_image(app->mlx_data->mlx, app->mlx_data->img.img);
		if (app->mlx_data->mlx_win)
			mlx_destroy_window(app->mlx_data->mlx, app->mlx_data->mlx_win);
		if (app->mlx_data->mlx)
		{
			mlx_destroy_display(app->mlx_data->mlx);
			free(app->mlx_data->mlx);
		}
		free(app->mlx_data);
	}
	free(app);
}

int	close_fdf(t_app *app)
{
	cleanup_fdf(app);
	exit(0);
	return (0);
}

int	error_exit(t_app *app, char *message)
{
	if (message)
		perror(message);
	cleanup_fdf(app);
	exit(1);
	return (ERROR);
}

int	main(int argc, char **argv)
{
	t_app	*app;

	app = malloc(sizeof(t_app));
	if (!app)
		return (perror("Malloc error initializing program"), ERROR);
	if (argc != 2)
		return (close_fdf(app), perror("Program only takes 1 arg"), ERROR);
	app->map = NULL;
	if (parse_map(argv[1], &app->map) != 0)
		return (perror("Error parsing map"), ERROR);
	app->mlx_data = malloc(sizeof(t_mlx_data));
	if (!app->mlx_data)
		return (perror("Malloc error initializing mlx_data"), ERROR);
	if (setup(&app->mlx_data->mlx,
			&app->mlx_data->mlx_win, &app->mlx_data->img) != 0)
		return (error_exit(app, "Error on setup"));
	app->current_gap = MAP_GAP;
	draw_map_points(app->map, app->current_gap, app->mlx_data->img);
	mlx_put_image_to_window(app->mlx_data->mlx,
		app->mlx_data->mlx_win, app->mlx_data->img.img, 0, 0);
	mlx_mouse_hook(app->mlx_data->mlx_win, handle_zoom, app);
	mlx_key_hook(app->mlx_data->mlx_win, &handle_keypress, app);
	mlx_hook(app->mlx_data->mlx_win, 17, 0, &handle_window_close, app);
	mlx_loop(app->mlx_data->mlx);
}
