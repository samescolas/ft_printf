/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 11:09:12 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/09 11:40:45 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
int		get_arglen(t_argfmt arg)
{
	int		ret;
	int		add;

	if (ft_toupper(arg.specifier) == 'C')
		return (1);
	else if (is_numeric_specifier(arg.specifier))
		return (ft_numlen(arg.arg.num_val, get_base(arg.specifier))
														- (arg.arg.num_val < 0));
	else if (arg.specifier == 'S')
		return (0);
	else
		return (ft_strlen(arg.arg.str_val));
	add = 0;
	if (arg.flags.special && arg.arg.num_val > 0 && (
		ft_toupper(arg.specifier) == 'O' || ft_toupper(arg.specifier) == 'X'))
		add += 1 + (ft_toupper(arg.specifier) == 'X');
	if (arg.flags.show_sign && is_numeric_specifier(arg.specifier) &&
					ft_toupper(arg.specifier) != 'U' && arg.arg.num_val > 0)
		add += 1;
	else if (arg.flags.space)
		add += 1;
	if (arg.precision > 0 && arg.precision < ret + add)
		return (arg.precision);
	return (ret + add);
}

char	get_specifier(char *fmt)
{
	char	*ptr;

	ptr = fmt;
	while (*ptr && !is_specifier(*ptr))
		++ptr;
	return (*ptr);
}
*/
int		get_base(char specifier)
{
	specifier = ft_toupper(specifier);
	if (specifier == 'C' || specifier == 'D' || specifier == 'I' ||
															specifier == 'U')
		return (10);
	else if (specifier == 'X')
		return (16);
	else if (specifier == 'O')
		return (8);
	else
		return (1);
}
