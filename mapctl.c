/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapctl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 23:30:49 by skaynar           #+#    #+#             */
/*   Updated: 2025/03/13 17:39:24 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	newlinectl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		else
			i++;
	}
	return (0);
}

int	mapargctl(t_game *game, char **av)
{
	char	**map;

	if (!(game->coincount > 0))
		return (0);
	if (game->exitcount != 1)
		return (0);
	if (game->playercount != 1)
		return (0);
	map = copymap(game, av[1]);
	if (newlinectl(map[game->high - 1]))
		return (clear_array(map), 0);
	return (clear_array(map), 1);
}

int	truemapfloor(char *str, t_game *game)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (str[j] != 'E' && str[j] != 'C' && str[j] != 'P' && str[j] != '\0'
			&& str[j] != '\n' && str[j] != '1' && str[j] != '0')
			return (0);
		if (str[j] == 'E')
			game->exitcount++;
		if (str[j] == 'C')
			game->coincount++;
		if (str[j] == 'P')
		{
			game->map->py = game->high + 1;
			game->map->px = j + 1;
			game->playercount++;
		}
		j++;
		game->width = j;
	}
	return (1);
}

int	check_map_name(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len > 4)
	{
		if (str[len - 1] == 'r' && str[len - 2] == 'e' && str[len - 3] == 'b'
			&& str[len - 4] == '.')
			return (1);
		else
			return (write(1, "Error\n", 6), 0);
	}
	return (write(1, "Error\n", 6), 0);
}
