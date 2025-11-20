#include <stdio.h>
#include <stdlib.h>

void	print_solution(int *solutions, int n)
{
	for (int i = 0; i < (n - 1); i++)
		fprintf(stdout, "%d ", solutions[i]);
	fprintf(stdout, "%d\n", solutions[n - 1]);
}

int	is_queen_safe(int *solutions, int column, int row)
{
	for (int i = 0; i < column; i++)
	{
		if (solutions[i] == row)
			return 0;
		if (row - column == solutions[i] - i)
			return 0;
		if (row + column == solutions[i] + i)
			return 0;
	}
	return 1;
}

void	solve_queen(int *solutions, int n, int column)
{
	if (column == n)
		print_solution(solutions, n);
	else
	{
		for (int row = 0; row < n; row++)
		{
			if (is_queen_safe(solutions, column, row))
			{
				solutions[column] = row;
				solve_queen(solutions, n, column + 1);
			}
		}
	}
}

int	main(int ac, char **av)
{
	int n;

	if (ac == 2)
	{
		n = atoi(av[1]);
		if (n > 1)
		{
			int	solutions[n];
			solve_queen(solutions, n, 0);
		}
		else
			fprintf(stdout, 0);
		return 0;
	}
	return 1;
}
