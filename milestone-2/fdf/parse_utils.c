/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <amarquez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 12:36:54 by amarquez          #+#    #+#             */
/*   Updated: 2025/07/17 12:37:06 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	check_sign(int *sign, char **p)
{
	if (**p == '-')
	{
		*sign = -1;
		(*p)++;
	}
	else if (**p == '+')
		(*p)++;
}

static void	handle_base(int *base, char **p)
{
	if (*base == 0)
	{
		if (**p == '0')
		{
			if (*((*p) + 1) == 'x' || *((*p) + 1) == 'X')
			{
				*base = 16;
				p += 2;
			}
			else
			{
				*base = 8;
				p++;
			}
		}
		else
			*base = 10;
	}
	else if (*base == 16
		&& **p == '0' && (*((*p) + 1) == 'x' || *((*p) + 1) == 'X'))
		p += 2;
}

static int	char_to_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	else
		return (-1);
}

static int	custom_parsenum(char **ptr, int base)
{
	char	*p;
	int		result;
	int		sign;
	int		digit;

	p = *ptr;
	result = 0;
	sign = 1;
	skip_whitespace(&p);
	check_sign(&sign, &p);
	handle_base(&base, &p);
	while (*p)
	{
		digit = char_to_digit(*p);
		if (digit == -1 || digit >= base)
			break ;
		result = result * base + digit;
		p++;
	}
	*ptr = p;
	return (result * sign);
}

int	parse_map_int(char **ptr)
{
	return (custom_parsenum(ptr, 10));
}
