#include <stdlib.h>
#include <stdio.h>

void	print_subset(int *set, int *indices, int subsize)
{
	if (subsize == 0)
		return;
	for (int i = 0; i < subsize - 1; i++)
		printf("%d ", set[indices[i]]);
	printf("%d\n", set[indices[subsize - 1]]);
}

void	find_subsets(int *set, int size, int target, int start, int *indices, int subsize, int current_sum)
{
	if (current_sum == target)
		print_subset(set, indices, subsize);
	for (int i = start; i < size; i++)
	{
		indices[subsize] = i;
		find_subsets(set, size, target, i + 1, indices, subsize + 1, current_sum + set[i]);
	}
}

int	main(int ac, char **av)
{
	if (ac > 2)
	{
		int target = atoi(av[1]);
		int size = ac - 2;
		int *set = malloc(sizeof(int) * size);
		if (!set)
			return (1);
		int *subset = malloc(sizeof(int) * size);
		if (!subset)
			return (free(set), 1);
		int i = 0;
		for (int i = 0; i < size; i++)
			set[i] = atoi(av[i + 2]);
		find_subsets(set, size, target, 0, subset, 0, 0);
		return (free(set), free(subset), 0);
	}
}
