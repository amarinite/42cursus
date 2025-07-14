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

int	close_fdf(t_app *app)
{
	free_map(app->map);
	if (app->mlx_data->img.img != NULL)
    	mlx_destroy_image(app->mlx_data->mlx, app->mlx_data->img.img);
    mlx_destroy_window(app->mlx_data->mlx, app->mlx_data->mlx_win);
    mlx_destroy_display(app->mlx_data->mlx);
    free(app->mlx_data->mlx);
    free(app->mlx_data);
    free(app);
    exit(1);
	return (0);
}

#include <stdio.h>  // for printf

void	print_map_points(t_map *map)
{
	int i, j;

	if (!map || !map->points)
	{
		printf("Map is empty or not allocated.\n");
		return;
	}
	printf("Map Dimensions: %d rows x %d columns\n", map->rows, map->columns);
	for (i = 0; i < map->rows; i++)
	{
		for (j = 0; j < map->columns; j++)
		{
			printf("(%d,%d,%d) ",
				map->points[i][j].x,
				map->points[i][j].y,
				map->points[i][j].z);
		}
		printf("\n");
	}
}


int	main(int argc, char **argv)
{
	t_app	*app;

	app = malloc(sizeof(t_app));
	if (!app)
		return (perror("Malloc error initializing program"),ERROR);
	if (argc != 2)
		return (perror("Program only takes 1 arg"), ERROR);
	app->map = NULL;
	if (parse_map(argv[1], &app->map) != 0)
		return (perror("Error parsing map"), ERROR);
	app->mlx_data = malloc(sizeof(t_mlx_data));
	if (!app->mlx_data)
		return (perror("Malloc error initializing mlx_data"), ERROR);
	if (setup(&app->mlx_data->mlx, &app->mlx_data->mlx_win, &app->mlx_data->img) != 0)
	{
		close_fdf(app);
		return (perror("Error on setup"), ERROR);
	}
	//print_map_points(app->map);
	draw_map_points(app->map, MAP_GAP, app->mlx_data->img);
	mlx_put_image_to_window(app->mlx_data->mlx, app->mlx_data->mlx_win, app->mlx_data->img.img, 0, 0);
	mlx_key_hook(app->mlx_data->mlx_win, &handle_keypress, app);
	mlx_loop(app->mlx_data->mlx);
}
