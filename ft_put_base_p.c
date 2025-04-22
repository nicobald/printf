/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_base_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaldes <nbaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:30:34 by nbaldes           #+#    #+#             */
/*   Updated: 2025/04/22 16:56:08 by nbaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_base_p(t_printf *env, uintptr_t arg)
{
	if (!arg)
		ft_putstr("(nil)", env);
	else if (arg)
	{
		ft_putstr("0x", env);
		ft_put_base_ptr(arg, 16, "0123456789abcdef", env);
	}
}
