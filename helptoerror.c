/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helptoerror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:21:36 by skaynar           #+#    #+#             */
/*   Updated: 2025/03/14 17:21:38 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	freegnl(int fd)
{
	char	*str;

	str = get_next_line(fd);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
	}
}

void	freemalloc(t_game *game)
{
	free(game->map);
	free(game);
}

void	clear_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}
