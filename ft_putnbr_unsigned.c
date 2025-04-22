/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaldes <nbaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 10:58:48 by nbaldes           #+#    #+#             */
/*   Updated: 2025/04/22 14:55:18 by nbaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_unsigned(unsigned int nb, t_printf *env)
{
	char	c;

	if (nb > 9)
	{
		ft_putnbr(nb / 10, env);
	}
	c = nb % 10 + '0';
	env->count += write(1, &c, 1);
}
