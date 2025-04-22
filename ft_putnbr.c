/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaldes <nbaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:00:02 by nbaldes           #+#    #+#             */
/*   Updated: 2025/04/22 14:56:42 by nbaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb, t_printf *env)
{
	char	c;

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
	if (nb > 9)
	{
		ft_putnbr(nb / 10, env);
	}
	c = nb % 10 + '0';
	env->count += write(1, &c, 1);
}
