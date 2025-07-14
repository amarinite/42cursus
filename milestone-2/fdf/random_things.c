#include <time.h>
#include <stdint.h>
#include <stdlib.h>

#include "fdf.h"

uint32_t random_color()
{
	uint8_t r = rand() % 256;
    uint8_t g = rand() % 256;
    uint8_t b = rand() % 256;
    uint8_t a = 0xFF;

    return (a << 24) | (r << 16) | (g << 8) | b;
}

void midPointCircleDraw(int x_centre, int y_centre, int r, t_data img)
{
    int x = r, y = 0;
    int color = 0xFFFFFFFF;

    my_pixel_put(&img, x + x_centre, y + y_centre, color);

    if (r > 0)
    {
    	my_pixel_put(&img, x + x_centre, -y + y_centre, color);
     	my_pixel_put(&img, y + x_centre, x + y_centre, color);
      	my_pixel_put(&img, -y + x_centre, x + y_centre, color);
    }
    int P = 1 - r;
    while (x > y)
    {
        y++;
        if (P <= 0)
            P = P + 2*y + 1;
        else
        {
            x--;
            P = P + 2*y - 2*x + 1;
        }
        if (x < y)
            break;

       	my_pixel_put(&img, x + x_centre, y + y_centre, color);
        my_pixel_put(&img, -x + x_centre, y + y_centre, color);
        my_pixel_put(&img, x + x_centre, -y + y_centre, color);
       	my_pixel_put(&img, -x + x_centre, -y + y_centre, color);

        if (x != y)
        {
       		my_pixel_put(&img, y + x_centre, x + y_centre, color);
         	my_pixel_put(&img, -y + x_centre, x + y_centre, color);
          	my_pixel_put(&img, y + x_centre, -x + y_centre, color);
        	my_pixel_put(&img, -y + x_centre, -x + y_centre, color);

        }
    }
}

void	drawRandomColorSquare(int width, int height, t_data	img)
{
	uint32_t color;

	srand(time(NULL));
	color = random_color();
	while (width < 400)
	{
		my_pixel_put(&img, width, height, color);
		width++;
	}
	while (height < 400)
	{
		my_pixel_put(&img, width, height, color);
		height++;
	}
	while (width > 100)
	{
		my_pixel_put(&img, width, height, color);
		width--;
	}
	while (height > 100)
	{
		my_pixel_put(&img, width, height, color);
		height--;
	}
}
