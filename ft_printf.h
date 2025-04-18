#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_printf
{
	int		count;
	va_list	args;
}			t_printf;

int			ft_printf(const char *str, ...);
void		ft_put_base(long nb, int base, char *str, t_printf *env);
void		ft_putnbr_unsigned(unsigned int nb, t_printf *env);
void		ft_putnbr(int nb, t_printf *env);
void		ft_putstr(char *s, t_printf *env);
void		ft_putchar(char c, t_printf *env);
void		ft_parse(t_printf *env, const char *str);

#endif