#include <stdio.h>
#include <math.h>
#include <float.h>

typedef struct {
	float x, y;
}	City;

float	calculate_distance(City a, City b)
{
	float dx = a.x - b.x;
	float dy = a.y - b.y;
	return sqrtf(dx * dx + dy * dy);
}

float	calculate_total_distance(City *cities, int *path, int n)
{
	float total = 0.0f;
	int i;
	for (i = 0; i < n - 1; i++)
		total += calculate_distance(cities[path[i]], cities[path[i + 1]]);
	total += calculate_distance(cities[path[n - 1]], cities[path[0]]);
	return total;
}

void	swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void	find_shortest_path(City *cities, int *path, int n,
	int pos, float *min_distance)
{
	if (pos == n)
	{
		float current_distance = calculate_total_distance(cities, path, n);
		if (current_distance < *min_distance)
			*min_distance = current_distance;
		return;
	}
	for (int i = pos; i < n; i++)
	{
		swap(&path[pos], &path[i]);
		find_shortest_path(cities, path, n, pos + 1, min_distance);
		swap(&path[pos], &path[i]);
	}
}

int main(void)
{
	City cities[12];
	int n = 0;
	while (n < 11 && fscanf(stdin, "%f, %f", &cities[n].x, &cities[n].y) == 2)
		n++;
	if (n < 2)
	{
		printf("0.00\n");
		return 0;
	}
	int path[12];
	for (int i = 0; i < n; i++)
		path[i] = i;
	float min_distance = FLT_MAX;
	find_shortest_path(cities, path, n, 1, &min_distance);
	printf("%.2f\n", min_distance);
	return 0;
}
