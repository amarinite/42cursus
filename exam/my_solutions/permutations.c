#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *s)
{
	int count = 0;
	while (s[count])
		count++;
	return count;
}

void	sort(char *s, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (s[j] > s[j + 1])
			{
				char tmp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = tmp;
			}
		}
	}
}

int	ft_strchr(const char *s, char c)
{
	int i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return 1;
		i++;
	}
	return 0;
}

void	permute(char *str, char *buffer, int pos, int len)
{
	if (pos == len)
		puts(buffer);
	else
	{
		for (int i = 0; i < len; i++)
		{
			if (!ft_strchr(buffer, str[i]))
			{
				buffer[pos] = str[i];
				permute(str, buffer, pos + 1, len);
				buffer[pos] = '\0';
			}
		}
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int len = ft_strlen(av[1]);
		if (len == 0)
			return 0;
		char *str = av[1];
		char *buffer = malloc(len + 1);
		if (!buffer)
			return 1;
		sort(str, len);
		permute(str, buffer, 0, len);
		free(buffer);
		return 0;
	}
	return 1;
}















// void	permute(char *source, char *buffer, int pos, int len)
// {
// 	if (pos == len)
// 		puts(buffer);
// 	else
// 	{
// 		for (int i = 0; i < len; i++)
// 		{
// 			// int j;
// 			// for (j = 0; j < pos; j++)
// 			// 	if (buffer[j] == source[i])
// 			// 		break;
// 			// if (j != pos)
// 			// 	continue;
// 			buffer[pos] = source[i];
// 			permute(source, buffer, pos + 1, len);
// 			}
// 		}
// 	}
// }
