#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFF 42

char	*read_input(void)
{
	char	*input = NULL;
	int		bytes_read;
	char	*tmp;
	char	buf[BUFF + 1];
	int		len = 0;

	while ((bytes_read = read(0, buf, BUFF)) > 0)
	{
		buf[bytes_read] = '\0';
		tmp = realloc(input, len + bytes_read + 1);
		if (!tmp)
			return (free(input), NULL);
		input = tmp;
		memmove(input + len, buf, bytes_read);
		len += bytes_read;
		input[len] = '\0';
	}
	if (bytes_read < 0)
		return (free(input), NULL);
	return input;
}

char	*filter(char *input, char *to_filter)
{
	int		filt_len = strlen(to_filter);
	int		len = strlen(input);
	char	*curr = input;
	int		curr_len = len;
	char	*tmp = curr;
	while ((tmp = memmem(curr, curr_len, to_filter, filt_len)) != NULL)
	{
		for (int i = 0; i < filt_len; i++)
			tmp[i] = '*';
		curr = tmp + filt_len;
		curr_len = strlen(curr);
	}
	return input;
}

int	main(int ac, char **av)
{
	if (ac == 2 && av[1][0])
	{
		char *input = read_input();
		if (!input)
			return (perror("Error:"), 1);
		char *to_filter = av[1];
		filter(input, to_filter);
		printf("%s", input);
		return (free(input), 0);
	}
	return 1;
}
