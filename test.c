#include "ft_printf.h"
#include <stdlib.h>

void	ft_putchar(char c, t_printf *env)
{
	if (!c)
		return ;
	env->count += write(1, &c, 1);
	return ;
}

void	ft_putstr(char *s, t_printf *env)
{
	int	i;

	i = 0;
	if (!s)
	{
		env->count = write(1, "(null)", 6);
		return ;
	}
	while (s[i])
	{
		env->count += write(1, &s[i], 1);
		i++;
	}
	return ;
}
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

void	ft_put_base(long nb, int base, char *str, t_printf *env)
{
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

void	ft_parse(t_printf *env, const char *str)
{
	int			i;
	uintptr_t	arg;

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
			else if (str[i + 1] == 'd')
				ft_putnbr(va_arg(env->args, int), env);
			else if (str[i + 1] == 'i')
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
				if (!(int)arg)
					ft_putstr("(nil)", env);
				else
				{
					// ft_putstr("0x", env);
					ft_put_base((uintptr_t)va_arg(env->args, void *), 16,
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
int	ft_printf(const char *str, ...)
{
	t_printf	env;

	env.count = 0;
	va_start(env.args, str);
	ft_parse(&env, str);
	va_end(env.args);
	return (env.count);
}

#include <limits.h>
#include <stdint.h>

int	main(void)
{
	int	ret_std;
	int	ret_ft;
	int ret_std1;
    int ret_ft1;

	printf("%d\n", ft_printf(" %d", INT_MIN));
	printf("%d\n", ft_printf(" %d", 9453));
	printf("%d\n\n", ft_printf(" %d", 0));
	printf("%d\n", printf(" %d", INT_MIN));
	printf("%d\n", printf(" %d", 9453));
	printf("%d\n\n", printf(" %d", 0));
	ft_printf(" %d\n", INT_MIN);
	ft_printf(" %d\n", 9453);
	ft_printf(" %d\n\n", 0);
	printf(" %d\n", INT_MIN);
	printf(" %d\n", 9453);
	printf(" %d\n\n", 0);
	return (0);
}

// 	TEST(4, print(" %d ", 9));
// 	TEST(5, print(" %d ", 10));
// 	TEST(6, print(" %d ", 11));
// 	TEST(7, print(" %d ", 15));
// 	TEST(8, print(" %d ", 16));
// 	TEST(9, print(" %d ", 17));
// 	TEST(10, print(" %d ", 99));
// 	TEST(11, print(" %d ", 100));
// 	TEST(12, print(" %d ", 101));
// 	TEST(13, print(" %d ", -9));
// 	TEST(14, print(" %d ", -10));
// 	TEST(15, print(" %d ", -11));
// 	TEST(16, print(" %d ", -14));
// 	TEST(17, print(" %d ", -15));
// 	TEST(18, print(" %d ", -16));
// 	TEST(19, print(" %d ", -99));
// 	TEST(20, print(" %d ", -100));
// 	TEST(21, print(" %d ", -101));
// 	TEST(22, print(" %d ", INT_MAX));
// 	TEST(23, print(" %d ", INT_MIN));
// 	TEST(24, print(" %d ", LONG_MAX));
// 	TEST(25, print(" %d ", LONG_MIN));
// 	TEST(26, print(" %d ", UINT_MAX));
// 	TEST(27, print(" %d ", ULONG_MAX));
// 	TEST(28, print(" %d ", 9223372036854775807LL));
// 	TEST(29, print(" %d %d %d %d %d %d %d", INT_MAX, INT_MIN, LONG_MAX,
// 			LONG_MIN, ULONG_MAX, 0, -42));
// }
