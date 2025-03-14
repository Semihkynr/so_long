/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:11:25 by skaynar           #+#    #+#             */
/*   Updated: 2024/11/06 17:11:28 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_nbr(int nb, size_t *counter)
{
	if (nb == -2147483648)
	{
		ft_print_nbr((nb / 10), counter);
		ft_print_char('8', counter);
	}
	else if (nb < 0)
	{
		ft_print_char('-', counter);
		ft_print_nbr(-nb, counter);
	}
	else
	{
		if (nb >= 10)
		{
			ft_print_nbr((nb / 10), counter);
		}
		ft_print_char(((nb % 10) + 48), counter);
	}
}
