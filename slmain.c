/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slmain.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:59:28 by skaynar           #+#    #+#             */
/*   Updated: 2025/03/14 17:22:40 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(t_game *game, char **av, int j, int a)
{
	char	*str;
	int		fd;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (close(fd), 0);
	str = get_next_line(fd);
	a = ft_strlen(str) - 1;
	if (a == -1)
		return (close(fd), free(str), 0);
	while (str)
	{
		if (!(truemapfloor(str, game)))
			return (close(fd), free(str), 0);
		j = game->width;
		if (!(newlinectl(str)))
			j++;
		game->width = j - 1;
		game->high++;
		free(str);
		str = get_next_line(fd);
		if (game->width != a)
			return (freegnl(fd), close(fd), free(str), 0);
	}
	return (close(fd), free(str), 1);
}

void	where_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (++i < game->high - 1)
	{
		j = 0;
		while (++j < game->width - 1)
		{
			if (game->map->realmap[i][j] == 'P')
			{
				game->map->px = j;
				game->map->py = i;
			}
		}
	}
}

void	newgame(t_game *game)
{
	game->coincount = 0;
	game->exitcount = 0;
	game->playercount = 0;
	game->step = 0;
	game->high = 0;
	game->width = 0;
}

int	allcheck(char **av, t_game *game)
{
	newgame(game);
	if (!check_map(game, av, 0, 0))
		return (write(1, "Error\n", 6), 0);
	if (!mapargctl(game, av))
		return (write(1, "Error\n", 6), freemalloc(game), 0);
	game->map->realmap = copymap(game, av[1]);
	if (!map_wallctl(game, game->map->realmap, 0, 0))
		return (clear_array(game->map->realmap), freemalloc(game), write(1,
				"Error\n", 6), 0);
	game->map->fakemap = copymap(game, av[1]);
	flood_fill(game->map->py - 1, game->map->px - 1, game);
	if (!is_reachable(game->map->fakemap))
		return (clear_array(game->map->fakemap),
			clear_array(game->map->realmap), freemalloc(game), write(1,
				"Error\n", 6), 0);
	if (!xpmctl())
		return (clear_array(game->map->fakemap),
			clear_array(game->map->realmap), freemalloc(game), 0);
	if (game->width * 64 > 1920 || game->high > 1080)
		return (clear_array(game->map->fakemap),
			clear_array(game->map->realmap), ft_printf("Error\n"), 0);
	return (1);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		return (write(1, "Error\nNumber of wrong arguments\n", 32), 0);
	if (!check_map_name(av[1]))
		return (0);
	game = malloc(sizeof(t_game));
	game->map = malloc(sizeof(t_map));
	if (!game || !game->map)
		return (write(1, "Error\nMalloc Error!", 19), freemalloc(game), 0);
	if (!allcheck(av, game))
		return (free(game->map), free(game), 0);
	game->mlx = mlx_init();
	game->mlx_window = mlx_new_window(game->mlx, game->width * 64, game->high
			* 64, "so_long");
	image_put(game);
	mlx_key_hook(game->mlx_window, key_hook, game);
	mlx_hook(game->mlx_window, 17, 0L, finish_game, game);
	mlx_loop(game->mlx);
	return (clear_array(game->map->fakemap), clear_array(game->map->realmap),
		freemalloc(game), 0);
}
