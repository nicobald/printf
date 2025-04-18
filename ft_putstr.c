/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaldes <nbaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:04:48 by nbaldes           #+#    #+#             */
/*   Updated: 2025/04/18 17:46:13 by nbaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putstr(char *s, t_printf *env)
{
	int i;

	i = 0;
	if (!s)
	{
		env->count += write(1, "(null)", 6);
		return ;
	}
	while (s[i])
	{
		env->count += write(1, &s[i], 1);
		i++;
	}
	return ;
}