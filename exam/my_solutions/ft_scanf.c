#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

int	match_space(FILE *f)
{
	int c = fgetc(f);
	if (c == EOF)
		return -1;
	while(isspace(c))
		c = fgetc(f);
	ungetc(c, f);
	return  1;
}

int	match_char(FILE *f, char c)
{
	int ch = fgetc(f);
	if (ch == EOF)
		return -1;
	if (ch == c)
		return 1;
	ungetc(c, f);
	return 0;
}

int	scan_char(FILE *f, va_list ap)
{
	int c = fgetc(f);
	char *char_p = va_arg(ap, char *);
	if (c == EOF)
		return -1;
	*char_p = c;
	return 1;
}

int	scan_int(FILE *f, va_list ap)
{
	int c = fgetc(f);
	int *int_p = va_arg(ap, int *);
	int res = 0;
	int sign = 1;

	if (c == '-' || c == '+')
	{
		if (c == '-')
			sign = -1;
		int next_c = fgetc(f);
		if (!isdigit(next_c))
		{
			ungetc(next_c, f);
			ungetc(c, f);
			return -1;
		}
		c = next_c;
	}
	if (!isdigit(c))
		return (ungetc(c, f), -1);
	while (isdigit(c))
	{
		res = res * 10 + (c - '0');
		c = fgetc(f);
	}
	*int_p = res * sign;
	ungetc(c, f);
	return 1;
}

int	scan_string(FILE *f, va_list ap)
{
	int c = fgetc(f);
	char *str_p = va_arg(ap, char *);
	int i = 0;


	while (!isspace(c) && c != EOF)
	{
		str_p[i] = c;
		c = fgetc(f);
		i++;
	}
	str_p[i] = '\0';
	if (c != EOF)
		ungetc(c, f);
	return 1;
}

int	match_conv(FILE *f, const char **format, va_list ap)
{
	switch (**format)
	{
		case 'c':
			return scan_char(f, ap);
		case 'd':
			match_space(f);
			return scan_int(f, ap);
		case 's':
			match_space(f);
			return scan_string(f, ap);
		case EOF:
			return -1;
		default:
			return -1;
	}
}

int ft_vfscanf(FILE *f, const char *format, va_list ap)
{
	int nconv = 0;

	int c = fgetc(f);
	if (c == EOF)
		return EOF;
	ungetc(c, f);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (match_conv(f, &format, ap) != 1)
				break;
			else
				nconv++;
		}
		else if (isspace(*format))
		{
			if (match_space(f) == -1)
				break;
		}
		else if (match_char(f, *format) != 1)
			break;
		format++;
	}

	if (ferror(f))
		return EOF;
	return nconv;
}

int	ft_scanf(const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	int ret = ft_vfscanf(stdin, format, ap);
	va_end(ap);
	return ret;
}
/*
#include <stdlib.h>
int main()
{
	int y;
	int x;
	char *s = malloc(50);

	ft_scanf("%d %s", &y, s);
        printf("[%d] [%s]\n", y, s);
	scanf("%d %s", &x, s);
        printf("[%d] [%s]\n", x, s);
	free(s);
	return 0;
}
*/
