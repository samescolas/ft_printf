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

typedef struct	s_flags
{
	t_bool		special;
	t_bool		pad_with_zeros;
	t_bool		left_justify;
	t_bool		show_sign;
	t_bool		space;
}				t_flags;

typedef struct	s_argfmt
{
	t_flags		flags;
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

void	ftp_parse_flags(t_flags *flags, char **fmt);

int		ftp_printnum(t_argfmt arg);
void	ft_putnum(long long n, int base, char letter_case);
size_t	ft_numlen(long long num, short base);

void	ft_fatal(char *err_msg);

#endif
