/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:12:09 by skaynar           #+#    #+#             */
/*   Updated: 2024/11/06 17:13:58 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);

void	ft_print_char(int c, size_t *counter);
void	ft_print_hexa(unsigned long n, char c, size_t *counter);
void	ft_print_int(int n, size_t *counter);
void	ft_print_nbr(int nb, size_t *counter);
void	ft_print_str(char *str, size_t *counter);
void	ft_print_ptr(unsigned long ptr, size_t *count);

#endif