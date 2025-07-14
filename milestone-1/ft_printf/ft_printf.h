/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprinf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <amarquez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:18:42 by amarquez          #+#    #+#             */
/*   Updated: 2025/06/17 16:18:45 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>
# include "libft/libft.h"

int	ft_printchar(const char c);
int	ft_printstr(char *str);
int	ft_printnbr_base(int nbr, char *base);
int	ft_printnbr_base_u(uintptr_t nbr, char *base);
int	ft_printptr(void *ptr, char *base);
int	ft_printf(const char *str, ...);

#endif
