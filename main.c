/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 11:23:25 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/09 14:42:20 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int		main(void)
{
	//printf("%+3.2d", 1);
	write(1, "\n\n\n", 3);
	ft_printf("%+3.2d", 1);
}
