/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 11:11:52 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/09 10:37:08 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
t_argfmt		parse_arg(char **fmt, void *arg)
{
	t_argfmt	options;

	*fmt += 1;
	ft_bzero(&options, sizeof(options));
	get_flags(&options.flags, fmt);
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
