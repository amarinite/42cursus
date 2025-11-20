#include <stdio.h>

int	invalid(char *s)
{
	int opened  = 0;
	int closed = 0;
	for(int i = 0; s[i]; i++)
	{
		if(s[i] == '(')
			opened++;
		else if(s[i] == ')')
		{
			if(opened > 0)
				opened--;
			else
				closed++;
		}
	}
	return (closed + opened);
}

void	solve_pts(char *parenthesis, int must_fix, int fixed, int pos)
{
	if(must_fix == fixed && !invalid(parenthesis))
	{
		puts(parenthesis);
		return ;
	}
	for(int i = pos; parenthesis[i]; i++)
	{
		if(parenthesis[i] == '(' || parenthesis[i] == ')')
		{
			char c = parenthesis[i];
			parenthesis[i] = ' ';
			solve_pts(parenthesis, must_fix, fixed + 1, i + 1);
			parenthesis[i] = c;
		}
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		char *parenthesis = av[1];
		int must_fix = invalid(parenthesis);
		solve_pts(parenthesis, must_fix, 0, 0);
		return 0;
	}
	return 1;
}
