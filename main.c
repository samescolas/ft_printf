/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 11:23:25 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/10 11:36:13 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int		main(void)
{

	//printf("%lld", -9223372036854775808uLL);
	ft_printf("%lld", -9223372036854775808uLL);
}
