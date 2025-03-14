/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:11:35 by skaynar           #+#    #+#             */
/*   Updated: 2024/11/06 17:14:12 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_ptr(unsigned long ptr, size_t *count)
{
	if (ptr == 0)
	{
		ft_print_str("(nil)", count);
	}
	else
	{
		ft_print_str("0x", count);
		ft_print_hexa(ptr, 'x', count);
	}
}
