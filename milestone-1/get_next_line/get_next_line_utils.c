/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <amarquez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:48:12 by amarquez          #+#    #+#             */
/*   Updated: 2025/05/28 09:48:15 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char		*pt;
	unsigned char		*piter;
	size_t				total_size;

	if (nmemb != 0 && size > (size_t)(-1) / nmemb)
		return (NULL);
	total_size = (nmemb * size);
	pt = malloc(total_size);
	if (pt == NULL)
		return (NULL);
	piter = pt;
	while (total_size > 0)
	{
		*piter = 0;
		piter++;
		total_size--;
	}
	return (pt);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dt;
	const unsigned char	*sc;

	dt = (unsigned char *) dest;
	sc = (unsigned char *) src;
	while (n > 0)
	{
		*dt = *sc;
		dt++;
		sc++;
		n--;
	}
	return (dest);
}

char	*ft_strndup(const char *s, size_t n)
{
	char	*result;
	size_t	i;

	result = ft_calloc(n + 1, sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (i < n && s[i])
	{
		result[i] = s[i];
		i++;
	}
	return (result);
}
