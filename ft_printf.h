/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 20:59:32 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/07 11:14:42 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <sys/types.h>

typedef	char	t_bool;

typedef enum	e_length
{
	HH,
	H,
	L,
	LL,
	J,
	Z
}				t_length;

typedef union	u_arg
{
	size_t		num_val;
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

int				ft_printf(const char *fmt, ...);

t_argfmt		parse_arg(char **fmt, void *arg);

size_t			ft_padnbr(t_argfmt arg, int written);

int				is_flag(char c);
int				is_length_specifier(char c);
int				is_specifier(char c);
int				is_numeric_specifier(char c);
int				get_base(char c);
char			get_specifier(char *fmt);

void			ftp_parse_flags(t_flags *flags, char **fmt);

int				ftp_printnum(t_argfmt arg);
void			ft_putnum(long long n, int base, char letter_case, long precision);
size_t			ft_numlen(long long num, short base);

size_t			convert_value(size_t n, t_length len, t_bool is_unsigned);

void			ft_fatal(char *err_msg);

#endif
