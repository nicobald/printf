/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaldes <nbaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:58:01 by nbaldes           #+#    #+#             */
/*   Updated: 2025/04/22 17:23:02 by nbaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	t_printf	env;

	env.count = 0;
	if (str == NULL)
		return (-1);
	va_start(env.args, str);
	ft_parse(&env, str);
	va_end(env.args);
	return (env.count);
}
