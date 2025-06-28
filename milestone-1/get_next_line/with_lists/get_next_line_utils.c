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

char *ft_strdup(const char *s)
{
    int		len;
    int		i;
    char	*result;

    len = 0;
    while (s[len])
    	len++;
    result = malloc(len + 1);
    if (!result)
        return (NULL);
    i = 0;
    while (s[i])
    {
        result[i] = s[i];
        i++;
    }
    result[i] = '\0';
    return (result);
}

void	clear_stash(t_buffer **stash)
{
	t_buffer	*current;
	t_buffer	*next;

	current = *stash;
	while (current)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
	*stash = NULL;
}
