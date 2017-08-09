/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 20:59:32 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/09 16:22:02 by sescolas         ###   ########.fr       */
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
	X,
	HH,
	H,
	L,
	LL,
	J,
	Z
}				t_length;

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
	size_t		width;
	size_t		prec;
	t_length	len;
	char		spec;
	char		*text;
	char		sign;
}				t_argfmt;

int				ft_printf(const char *fmt, ...);

t_argfmt		parse_arg(char **fmt, void *arg);

void			get_conversion(t_argfmt *fmt_info, va_list arg);
void			apply_formatting(t_argfmt info, char **text);

int				ftp_lpad(t_argfmt arg, int arg_len);
int				ftp_rpad(t_argfmt arg, int arg_len);

size_t			ft_padnbr(t_argfmt arg, int written);

int				is_length_specifier(char c);
int				is_specifier(char c);
int				is_signed_specifier(char c);
int				is_numeric_specifier(char c);
int				is_hex_or_oct(char c);
int				is_nonzero(char *num);
int				get_base(char c);
int				get_arglen(t_argfmt arg);

void			get_formatting(char **fmt, t_argfmt *fmt_info);
void			get_flags(char **fmt, t_flags *flags);
void			get_length(char **fmt, t_length *length);

int				ftp_printnum(t_argfmt arg);
void			ft_putnum(ssize_t n, int base, char letter_case);
size_t			ft_numlen(long long num, short base);


void			ft_fatal(char *err_msg);

#endif
