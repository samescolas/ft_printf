#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define IS_FLAG(x)

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

int		is_flag(char c);
int		is_length_specifier(char c);
int		is_numeric_specifier(char c);

#endif
