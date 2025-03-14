/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:10:53 by skaynar           #+#    #+#             */
/*   Updated: 2024/11/06 17:10:58 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hexa(unsigned long n, char c, size_t *counter)
{
	char	*hex;

	if (c == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n == 0)
	{
		ft_print_char('0', counter);
		return ;
	}
	if (n < 16)
	{
		ft_print_char(hex[n], counter);
	}
	else
	{
		ft_print_hexa(n / 16, c, counter);
		ft_print_hexa(n % 16, c, counter);
	}
}
