/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 20:59:32 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/12 11:30:40 by sescolas         ###   ########.fr       */
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
	t_bool		prec_specified;
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
	size_t		arg_len;
}				t_argfmt;

int				ft_printf(const char *fmt, ...);

void			get_formatting(char **fmt, t_argfmt *fmt_info);
void			get_conversion(t_argfmt *fmt_info, va_list arg);
void			get_flags(char **fmt, t_flags *flags);
void			get_length(char **fmt, t_length *length);
int				get_base(char c);

void			apply_formatting(t_argfmt info, char **text);
void			apply_padding(t_argfmt info, char **text);
void			apply_precision(t_argfmt info, char **text);

int				is_specifier(char c);
int				is_signed_specifier(char c);
int				is_numeric_specifier(char c);
int				is_length_specifier(char c);
int				is_hex_or_oct(char c);
int				is_nonzero(char *num);
int				is_blank(char *str);

int				ft_wctomb(wchar_t wc, char **buf);

void			ft_fatal(char *err_msg);

#endif
