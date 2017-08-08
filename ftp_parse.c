/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 11:11:52 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/08 16:13:16 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_length	get_length(char **fmt, t_argfmt *options)
{
	options->length_specified = 1;
	if (is_length_specifier(*(*fmt + 1)))
	{
		*fmt += 2;
		if (*(*fmt - 2) == 'l' && *(*fmt - 1) == 'l')
			return (LL);
		else if (*(*fmt - 2) == 'h' && *(*fmt - 1) == 'h')
			return (HH);
		else
		{
			write(1, (*fmt - 2), 2);
			ft_fatal("invalid length specifier");
		}
	}
	*fmt += 1;
	if (*(*fmt - 1) == 'l')
		return (L);
	else if (*(*fmt - 1) == 'h')
		return (H);
	else if (*(*fmt - 1) == 'j')
		return (J);
	else if (*(*fmt - 1) == 'z')
		return (Z);
	return (0);
}


t_argfmt		parse_arg(char **fmt, void *arg)
{
	t_argfmt	options;

	*fmt += 1;
	ft_bzero(&options, sizeof(options));
	ftp_parse_flags(&options.flags, fmt);
	options.specifier = get_specifier(*fmt);
	options.width = ft_atoi(*fmt);
	while (**fmt && ft_isdigit(**fmt))
		++(*fmt);
	if (**fmt && **fmt == '.')
	{
		options.precision_specified = 1;
		options.precision = ft_atoi(++(*fmt));
	}
	while (**fmt && ft_isdigit(**fmt))
		++(*fmt);
	if (is_length_specifier(**fmt))
		options.length = get_length(fmt, &options);
	ft_bzero(&options.arg, sizeof(options.arg));
	if (is_numeric_specifier(**fmt))
		options.arg.num_val = convert_fmt(options, arg);
	else if (**fmt == 's')
		options.arg.str_val = (char *)arg;
	//options.specifier = **fmt;
	++(*fmt);
	return (options);
}

/*
t_argfmt		parse_arg(char **fmt, void *arg)
{
	t_argfmt	options;
	ssize_t		*num;

	*fmt += 1;
	ft_bzero(&options, sizeof(options));
	ftp_parse_flags(&options.flags, fmt);
	options.width = ft_atoi(*fmt);
	while (**fmt && ft_isdigit(**fmt))
		++(*fmt);
	if (**fmt && **fmt == '.')
	{
		options.precision_specified = 1;
		options.precision = ft_atoi(++(*fmt));
	}
	while (**fmt && ft_isdigit(**fmt))
		++(*fmt);
	if (is_length_specifier(**fmt))
		options.length = get_length(fmt, &options);
	ft_bzero(&options.arg, sizeof(options.arg));
	if (is_numeric_specifier(**fmt))
	{
		num = (ssize_t *)arg;
		options.arg.num_val = *num;
	}
	else if (**fmt == 's')
		options.arg.str_val = (char *)arg;
	options.specifier = **fmt;
	++(*fmt);
	return (options);
}
*/
