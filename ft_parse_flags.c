/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaldes <nbaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:55:50 by nbaldes           #+#    #+#             */
/*   Updated: 2025/04/22 16:55:54 by nbaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_flags(t_printf *env, const char *str, int i)
{
	if (str[i + 1] == 'c')
		ft_putchar(va_arg(env->args, int), env);
	else if (str[i + 1] == 's')
		ft_putstr(va_arg(env->args, char *), env);
	else if (str[i + 1] == '%')
		ft_putchar(str[i + 1], env);
	else if (str[i + 1] == 'd' || str[i + 1] == 'i')
		ft_putnbr(va_arg(env->args, int), env);
	else if (str[i + 1] == 'u')
		ft_putnbr_unsigned(va_arg(env->args, unsigned int), env);
	else if (str[i + 1] == 'x')
		ft_put_base(va_arg(env->args, unsigned int), 16, "0123456789abcdef",
			env);
	else if (str[i + 1] == 'X')
		ft_put_base(va_arg(env->args, unsigned int), 16, "0123456789ABCDEF",
			env);
	else if (str[i + 1] == 'p')
		ft_put_base_p(env, (uintptr_t)va_arg(env->args, void *));
}
