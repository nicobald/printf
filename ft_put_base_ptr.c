/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_base_ptr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaldes <nbaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:53:22 by utilisateur       #+#    #+#             */
/*   Updated: 2025/04/22 14:54:26 by nbaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_base_ptr(uintptr_t nb, int base, char *str, t_printf *env)
{
	if (nb >= (uintptr_t)base)
		ft_put_base_ptr(nb / base, base, str, env);
	env->count += write(1, &str[nb % base], 1);
	return ;
}
