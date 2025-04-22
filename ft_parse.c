/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utilisateur <utilisateur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:23:25 by nbaldes           #+#    #+#             */
/*   Updated: 2025/04/22 10:37:03 by utilisateur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse(t_printf *env, const char *str)
{
	int	i;
				uintptr_t arg;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			if (str[i + 1] == 'c')
				ft_putchar(va_arg(env->args, int), env);
			else if (str[i + 1] == 's')
				ft_putstr(va_arg(env->args, char *), env);
			else if (str[i + 1] == '%')
				ft_putchar(str[i + 1], env);
			else if (str[i + 1] == 'd' || str[i + 1] =='i')
				ft_putnbr(va_arg(env->args, int), env);
			else if (str[i + 1] == 'u')
				ft_putnbr_unsigned(va_arg(env->args, unsigned int), env);
			else if (str[i + 1] == 'x')
				ft_put_base(va_arg(env->args, unsigned int), 16,
					"0123456789abcdef", env);
			else if (str[i + 1] == 'X')
				ft_put_base(va_arg(env->args, unsigned int), 16,
					"0123456789ABCDEF", env);
			else if (str[i + 1] == 'p')
			{
				arg = (uintptr_t)va_arg(env->args, void *);
				if (!arg)
					ft_putstr("(nil)", env);
				else if (arg)
				{
					ft_putstr("0x", env);
					ft_put_base_ptr(arg, 16,
						"0123456789abcdef", env);
				}
			}
			i++;
		}
		else
			ft_putchar(str[i], env);
		i++;
	}
}
