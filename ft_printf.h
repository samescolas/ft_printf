#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <sys/types.h>

typedef	char	t_bool;

typedef enum	s_length
{
				HH,
				H,
				L,
				LL,
				J,
				Z
}				t_length;

typedef union	e_arg
{
	long long	num_val;
	char		*str_val;
}				t_arg;

typedef struct	s_argfmt
{
	int			flag;
	long		width;
	long		precision;
	t_length	length;
	t_bool		length_specified;
	char		specifier;
	t_arg		arg;
}				t_argfmt;

int		ft_printf(const char *fmt, ...);

int		is_flag(char c);
int		is_length_specifier(char c);
int		is_numeric_specifier(char c);

int		ftp_printnum(t_argfmt arg);
void	ft_putnum(long long n, int base, char letter_case);
size_t	ft_numlen(long long num, short base);

void	ft_fatal(char *err_msg);

#endif
