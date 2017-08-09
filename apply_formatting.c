/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_formatting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 12:01:39 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/09 12:11:21 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	apply_formatting(t_argfmt info, char **text)
{
	if (info.flags.pad_with_zeros)
		apply_sign(info, text);
	apply_left_padding(info, text);

}
