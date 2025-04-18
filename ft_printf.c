/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaldes <nbaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:58:01 by nbaldes           #+#    #+#             */
/*   Updated: 2025/04/18 16:58:10 by nbaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// void	ft_putchar(char c, t_printf *env)
// {
// 	env->count += write(1, &c, 1);
// 	return ;
// }

// void	ft_putstr(char *s, t_printf *env)
// {
// 	int	i;

// 	i = 0;
// 	if (!s)
// 	{
// 		env->count += i;
// 		return ;
// 	}
// 	while (s[i])
// 	{
// 		env->count += write(1, &s[i], 1);
// 		i++;
// 	}
// 	return ;
// }
// void	ft_putnbr(int nb, t_printf *env)
// {
// 	char	c;

// 	if (nb == -2147483648)
// 	{
// 		env->count += write(1, "-2147483648", 11);
// 		return ;
// 	}
// 	if (nb < 0)
// 	{
// 		env->count += write(1, "-", 1);
// 		nb = -nb;
// 	}
// 	if (nb > 9)
// 	{
// 		ft_putnbr(nb / 10, env);
// 	}
// 	c = nb % 10 + '0';
// 	env->count += write(1, &c, 1);
// }
// void	ft_putnbr_unsigned(unsigned int nb, t_printf *env)
// {
// 	char	c;

// 	if (nb > 9)
// 	{
// 		ft_putnbr(nb / 10, env);
// 	}
// 	c = nb % 10 + '0';
// 	env->count += write(1, &c, 1);
// }

// void	ft_put_base(long nb, int base, char *str, t_printf *env)
// {
// 	if (nb < 0)
// 	{
// 		env->count += write(1, "-", 1);
// 		nb = -nb;
// 	}
// 	if (nb > base - 1)
// 	{
// 		ft_put_base((nb / base), base, str, env);
// 	}
// 	env->count += write(1, &str[nb % base], 1);
// 	return ;
// }

// void	ft_parse(t_printf *env, const char *str)
// {
// 	int	i;
// 				uintptr_t arg;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == '%' && str[i + 1])
// 		{
// 			if (str[i + 1] == 'c')
// 				ft_putchar(va_arg(env->args, int), env);
// 			else if (str[i + 1] == 's')
// 				ft_putstr(va_arg(env->args, char *), env);
// 			else if (str[i + 1] == '%')
// 				ft_putchar(str[i + 1], env);
// 			else if (str[i + 1] == 'd')
// 				ft_putnbr(va_arg(env->args, int), env);
// 			else if (str[i + 1] == 'i')
// 				ft_putnbr(va_arg(env->args, int), env);
// 			else if (str[i + 1] == 'u')
// 				ft_putnbr_unsigned(va_arg(env->args, unsigned int), env);
// 			else if (str[i + 1] == 'x')
// 				ft_put_base(va_arg(env->args, unsigned int), 16,
// 					"0123456789abcdef", env);
// 			else if (str[i + 1] == 'X')
// 				ft_put_base(va_arg(env->args, unsigned int), 16,
// 					"0123456789ABCDEF", env);
// 			else if (str[i + 1] == 'p')
// 			{
// 				arg = (uintptr_t)va_arg(env->args, void *);
// 				if (!(int)arg)
// 					ft_putstr("(nil)", env);
// 				else
// 				{
// 					ft_putstr("0x", env);
// 					ft_put_base((uintptr_t)va_arg(env->args, void *), 16,
// 						"0123456789abcdef", env);
// 				}
// 			}
// 			i++;
// 		}
// 		else
// 			ft_putchar(str[i], env);
// 		i++;
// 	}
// }
int	ft_printf(const char *str, ...)
{
	t_printf	env;

	env.count = 0;
	va_start(env.args, str);
	ft_parse(&env, str);
	va_end(env.args);
	return (env.count);
}
// int	main(void)
// {
// 	int local = 42;

// 	printf("%d\n", printf("%x et %X et %p\n", 5869547, 5869547,
			// (void *)&local));
// 	printf("%d\n",ft_printf("%x et %X et %p\n", 5869547, 5869547,
			// (void *)&local));
// 	return (0);

// size_t tmp;
// int cmpt;

// tmp = write(1, &c, 1);
// cmpt = cmpt + (int)tmp;
// cmpt += (int)write(1, &c, 1);
//}
// #include <limits.h>

// int	main(void)
// {
// 	int a, b;
// 	int valX1 = 0;
// 	int valX2 = 1;
// 	int valX3 = -1;
// 	int valX4 = 10;
// 	int valX5 = -10;
// 	int valX6 = 102;
// 	int valX7 = -101;
// 	int valX8 = 1021;
// 	int valX9 = -1011;
// 	int valX10 = INT_MAX;
// 	int valX11 = INT_MIN;
// 	int valX12 = CHAR_MAX;
// 	int valX13 = CHAR_MIN;
// 	int valX14 = UINT_MAX;
// 	int valX15 = UINT_MAX + 1;
// 	int valX16 = -42;

// 	int valx1 = 0;
// 	int valx2 = 1;
// 	int valx3 = -1;
// 	int valx4 = 10;
// 	int valx5 = -10;
// 	int valx6 = 102;
// 	int valx7 = -101;
// 	int valx8 = 1021;
// 	int valx9 = -1011;
// 	int valx10 = INT_MAX;
// 	int valx11 = INT_MIN;
// 	int valx12 = CHAR_MAX;
// 	int valx13 = CHAR_MIN;
// 	int valx14 = UINT_MAX;
// 	int valx15 = UINT_MAX + 1;
// 	int valx16 = -42;

// 	int valp1 = 0;
// 	int valp2 = 1;
// 	int valp3 = -1;
// 	int valp4 = 10;
// 	int valp5 = -10;
// 	int valp6 = 102;
// 	int valp7 = -101;
// 	int valp8 = 1021;
// 	int valp9 = -1011;
// 	int valp10 = INT_MAX;
// 	int valp11 = INT_MIN;
// 	int valp12 = LONG_MAX;
// 	int valp13 = LONG_MIN;
// 	int valp14 = ULONG_MAX;
// 	int valp15 = -ULONG_MAX;
// 	int valp16 = -42;

// 	int valc1 = 0;
// 	int valc2 = 1;
// 	int valc3 = -1;
// 	int valc4 = 10;
// 	int valc5 = -10;
// 	int valc6 = 102;
// 	int valc7 = 256;
// 	int valc8 = 102;
// 	int valc9 = -11;
// 	int valc10 = -42;

// 	int vald1 = 0;
// 	int vald2 = 1;
// 	int vald3 = -1;
// 	int vald4 = 10;
// 	int vald5 = -10;
// 	int vald6 = 102;
// 	int vald7 = -101;
// 	int vald8 = 1021;
// 	int vald9 = -1011;
// 	int vald10 = INT_MAX;
// 	int vald11 = INT_MIN;
// 	int vald12 = CHAR_MAX;
// 	int vald13 = CHAR_MIN;
// 	int vald14 = UINT_MAX;
// 	int vald15 = UINT_MAX + 1;
// 	int vald16 = -42;
// 	int vald17 = LONG_MAX;
// 	int vald18 = LONG_MIN;

// 	char *val1 = "";
// 	char *val2 = "0";
// 	char *val3 = "1";
// 	char *val4 = "123";
// 	char *val5 = "4567";
// 	char *val6 = NULL;

// 	int valu1 = 0;
// 	int valu2 = 1;
// 	int valu3 = -1;
// 	int valu4 = 10;
// 	int valu5 = -10;
// 	int valu6 = 102;
// 	int valu7 = -101;
// 	int valu8 = 1021;
// 	int valu9 = -1011;
// 	int valu10 = INT_MAX;
// 	int valu11 = INT_MIN;
// 	int valu12 = CHAR_MAX;
// 	int valu13 = CHAR_MIN;
// 	int valu14 = UINT_MAX;
// 	int valu15 = UINT_MAX + 1;
// 	int valu16 = -42;
// 	int valu17 = LONG_MAX;
// 	int valu18 = LONG_MIN;

// 	printf("mixteeeeed\n");

// 	a = ft_printf("testx %x test p %p test u %u test d %d test ntm
// 			%ioiujaqgzoidgaqiouldcgtqipudhioodp\n", valx12, valp2, valu15,
// 			vald13, vald17);
// 	b = printf("testx %x test p %p test u %u test d %d test ntm
// 			%ioiujaqgzoidgaqiouldcgtqipudhioodp\n", valx12, valp2, valu15,
// 			vald13, vald17);
// 	printf("%d %d\n", a, b);

// 	printf("type x\n");

// 	a = ft_printf("test : %x |\n", valx1);
// 	b = printf("test : %x |\n", valx1);
// 	printf("test retour :%d %d \n", a, b);
// 	a = ft_printf("test :%x\n", valx2);
// 	b = printf("test :%x\n", valx2);
// 	printf("test retour :%d %d \n", a, b);
// 	a = ft_printf("test :%x\n", valx3);
// 	b = printf("test :%x\n", valx3);
// 	printf("test retour :%d %d \n", a, b);
// 	a = ft_printf("test :%x\n", valx4);
// 	b = printf("test :%x\n", valx4);
// 	printf("test retour :%d %d \n", a, b);
// 	a = ft_printf("test :%x\n", valx5);
// 	b = printf("test :%x\n", valx5);
// 	printf("test :%d %d \n", a, b);
// 	a = ft_printf("test :%x\n", valx6);
// 	b = printf("test :%x\n", valx6);
// 	printf("test retour :%d %d \n", a, b);
// 	a = ft_printf("%x\n", valx7);
// 	b = printf("%x\n", valx7);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%x\n", valx8);
// 	b = printf("%x\n", valx8);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%x\n", valx9);
// 	b = printf("%x\n", valx9);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%x\n", valx10);
// 	b = printf("%x\n", valx10);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%x\n", valx11);
// 	b = printf("%x\n", valx11);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%x\n", valx12);
// 	b = printf("%x\n", valx12);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%x\n", valx13);
// 	b = printf("%x\n", valx13);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%x\n", valx14);
// 	b = printf("%x\n", valx14);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%x\n", valx15);
// 	b = printf("%x\n", valx15);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%x\n", valx16);
// 	b = printf("%x\n", valx16);
// 	printf("%d %d \n", a, b);

// 	printf("%%X\n");

// 	a = ft_printf("%X\n", valX1);
// 	b = printf("%X\n", valX1);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%X\n", valX2);
// 	b = printf("%X\n", valX2);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%X\n", valX3);
// 	b = printf("%X\n", valX3);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%X\n", valX4);
// 	b = printf("%X\n", valX4);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%X\n", valX5);
// 	b = printf("%X\n", valX5);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%X\n", valX6);
// 	b = printf("%X\n", valX6);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%X\n", valX7);
// 	b = printf("%X\n", valX7);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%X\n", valX8);
// 	b = printf("%X\n", valX8);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%X\n", valX9);
// 	b = printf("%X\n", valX9);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%X\n", valX10);
// 	b = printf("%X\n", valX10);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%X\n", valX11);
// 	b = printf("%X\n", valX11);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%X\n", valX12);
// 	b = printf("%X\n", valX12);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%X\n", valX13);
// 	b = printf("%X\n", valX13);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%X\n", valX14);
// 	b = printf("%X\n", valX14);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%X\n", valX15);
// 	b = printf("%X\n", valX15);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%X\n", valX16);
// 	b = printf("%X\n", valX16);
// 	printf("%d %d \n", a, b);

// 	printf("%%p\n");

// 	a = ft_printf("%p\n", valp1);
// 	b = printf("%p\n", valp1);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%p\n", valp2);
// 	b = printf("%p\n", valp2);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%p\n", valp3);
// 	b = printf("%p\n", valp3);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%p\n", valp4);
// 	b = printf("%p\n", valp4);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%p\n", valp5);
// 	b = printf("%p\n", valp5);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%p\n", valp6);
// 	b = printf("%p\n", valp6);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%p\n", valp7);
// 	b = printf("%p\n", valp7);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%p\n", valp8);
// 	b = printf("%p\n", valp8);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%p\n", valp9);
// 	b = printf("%p\n", valp9);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%p\n", valp10);
// 	b = printf("%p\n", valp10);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%p\n", valp11);
// 	b = printf("%p\n", valp11);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%p\n", valp12);
// 	b = printf("%p\n", valp12);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%p\n", valp12);
// 	b = printf("%p\n", valp12);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%p\n", valp13);
// 	b = printf("%p\n", valp13);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%p\n", valp14);
// 	b = printf("%p\n", valp14);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%p\n", valp15);
// 	b = printf("%p\n", valp15);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%p\n", valp16);
// 	b = printf("%p\n", valp16);
// 	printf("%d %d \n", a, b);

// 	printf("%%d\n");
// 	a = ft_printf("%d\n", vald1);
// 	b = printf("%d\n", vald1);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%d\n", vald2);
// 	b = printf("%d\n", vald2);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%d\n", vald3);
// 	b = printf("%d\n", vald3);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%d\n", vald4);
// 	b = printf("%d\n", vald4);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%d\n", vald5);
// 	b = printf("%d\n", vald5);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%d\n", vald6);
// 	b = printf("%d\n", vald6);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%d\n", vald7);
// 	b = printf("%d\n", vald7);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%d\n", vald8);
// 	b = printf("%d\n", vald8);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%d\n", vald9);
// 	b = printf("%d\n", vald9);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%d\n", vald10);
// 	b = printf("%d\n", vald10);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%d\n", vald11);
// 	b = printf("%d\n", vald11);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%d\n", vald12);
// 	b = printf("%d\n", vald12);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%d\n", vald13);
// 	b = printf("%d\n", vald13);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%d\n", vald14);
// 	b = printf("%d\n", vald14);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%d\n", vald15);
// 	b = printf("%d\n", vald15);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%d\n", vald16);
// 	b = printf("%d\n", vald16);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%d\n", vald17);
// 	b = printf("%d\n", vald17);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%d\n", vald18);
// 	b = printf("%d\n", vald18);
// 	printf("%d %d \n", a, b);

// 	printf("%%s\n");
// 	a = ft_printf("%s\n", val1);
// 	b = printf("%s\n", val1);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%s\n", val2);
// 	b = printf("%s\n", val2);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%s\n", val3);
// 	b = printf("%s\n", val3);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%s\n", val4);
// 	b = printf("%s\n", val4);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%s\n", val5);
// 	b = printf("%s\n", val5);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%s\n", val6);
// 	b = printf("%s\n", val6);
// 	printf("%d %d \n", a, b);

// 	printf("%%c\n");
// 	a = ft_printf("%c\n", valc1);
// 	b = printf("%c\n", valc1);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%c\n", valc2);
// 	b = printf("%c\n", valc2);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%c\n", valc3);
// 	b = printf("%c\n", valc3);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%c\n", valc4);
// 	b = printf("%c\n", valc4);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%c\n", valc5);
// 	b = printf("%c\n", valc5);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%c\n", valc6);
// 	b = printf("%c\n", valc6);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%c\n", valc7);
// 	b = printf("%c\n", valc7);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%c\n", valc8);
// 	b = printf("%c\n", valc8);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%c\n", valc9);
// 	b = printf("%c\n", valc9);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%c\n", valc10);
// 	b = printf("%c\n", valc10);
// 	printf("%d %d \n", a, b);

// 	printf("%%u\n");

// 	a = ft_printf("%u\n", valu1);
// 	b = printf("%u\n", valu1);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%u\n", valu2);
// 	b = printf("%u\n", valu2);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%u\n", valu3);
// 	b = printf("%u\n", valu3);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%u\n", valu4);
// 	b = printf("%u\n", valu4);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%u\n", valu5);
// 	b = printf("%u\n", valu5);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%u\n", valu6);
// 	b = printf("%u\n", valu6);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%u\n", valu7);
// 	b = printf("%u\n", valu7);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%u\n", valu8);
// 	b = printf("%u\n", valu8);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%u\n", valu9);
// 	b = printf("%u\n", valu9);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%u\n", valu10);
// 	b = printf("%u\n", valu10);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%u\n", valu11);
// 	b = printf("%u\n", valu11);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%u\n", valu12);
// 	b = printf("%u\n", valu12);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%u\n", valu13);
// 	b = printf("%u\n", valu13);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%u\n", valu14);
// 	b = printf("%u\n", valu14);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%u\n", valu15);
// 	b = printf("%u\n", valu15);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%u\n", valu16);
// 	b = printf("%u\n", valu16);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%u\n", valu17);
// 	b = printf("%u\n", valu17);
// 	printf("%d %d \n", a, b);
// 	a = ft_printf("%u\n", valu18);
// 	b = printf("%u\n", valu18);
// 	printf("%d %d \n", a, b);
// }