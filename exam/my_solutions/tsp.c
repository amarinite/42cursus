#include <stdio.h>
#include <math.h>
#include <float.h>

typedef struct
{
	float	x;
	float	y;
}	City;

float	calc_distance(City a, City b)
{
	float	dx = a.x - b.x;
	float	dy = a.y - b.y;
	return sqrtf(dx * dx + dy * dy);
}

float	calc_total_distance(City *cities, int *path, int n_cities)
{
	float	total = 0.0f;

	for (int i = 0; i < n_cities - 1; i++)
		total += calc_distance(cities[path[i]], cities[path[i + 1]]);

	total += calc_distance(cities[path[n_cities - 1]], cities[path[0]]);
	return total;
}

void	swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void	find_shortest_path(City *cities, int *path, int n_cities, int pos, float *min_distance)
{
	if (pos == n_cities)
	{
		float curr_distance = calc_total_distance(cities, path, n_cities);
		if (curr_distance < *min_distance)
			*min_distance = curr_distance;
	}
	else
	{
		for (int i = pos; i < n_cities; i++)
		{
			swap(&path[pos], &path[i]);
			find_shortest_path(cities, path, n_cities, pos + 1, min_distance);
			swap(&path[pos], &path[i]);
		}
	}
}

int	main(void)
{
	City cities[12];
	int n_cities = 0;

	while (n_cities < 11 && fscanf(stdin, "%f, %f", &cities[n_cities].x, &cities[n_cities].y) == 2)
		n_cities++;

	if (n_cities < 2)
		return (printf("0.00\n"), 0);

	int path[12];
	for (int i = 0; i < n_cities; i++)
		path[i] = i;

	float min_distance = FLT_MAX;
	find_shortest_path(cities, path, n_cities, 1, &min_distance);
	printf("%.2f\n", min_distance);

	return 0;
}
