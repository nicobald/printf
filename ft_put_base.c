/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaldes <nbaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:06:15 by nbaldes           #+#    #+#             */
/*   Updated: 2025/04/18 19:25:57 by nbaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_base(long nb, int base, char *str, t_printf *env)
{
	if (nb == -2147483648)
	{
		env->count += write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		env->count += write(1, "-", 1);
		nb = -nb;
	}
	if (nb > base - 1)
	{
		ft_put_base((nb / base), base, str, env);
	}
	env->count += write(1, &str[nb % base], 1);
	return ;
}