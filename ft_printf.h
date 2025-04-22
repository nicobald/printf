/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaldes <nbaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:56:27 by nbaldes           #+#    #+#             */
/*   Updated: 2025/04/22 16:54:15 by nbaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_printf
{
	int		count;
	va_list	args;
}			t_printf;

int			ft_printf(const char *str, ...);
void		ft_put_base(long nb, int base, char *str, t_printf *env);
void		ft_putnbr_unsigned(unsigned int nb, t_printf *env);
void		ft_putnbr(int nb, t_printf *env);
void		ft_putstr(char *s, t_printf *env);
void		ft_putchar(char c, t_printf *env);
void		ft_parse(t_printf *env, const char *str);
void		ft_put_base_ptr(uintptr_t nb, int base, char *str, t_printf *env);
void		ft_parse_flags(t_printf *env, const char *str, int i);
void		ft_put_base_p(t_printf *env, uintptr_t arg);

#endif