#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef union	e_arg
{
	long long	num_val;
	char		*str_val;
}				t_arg;

typedef struct	s_argfmt
{
	int		flag;
	long	width;
	long	precision;
	long	length;
	char	specifier;
	t_arg	arg;
}				t_argfmt;

int		ft_printf(const char *fmt, ...);

int		is_flag(char c);
int		is_length_specifier(char c);
int		is_numeric_specifier(char c);

int		ftp_printnum(t_argfmt arg);
void	ft_putnum(long long n, int base, char letter_case);

#endif
