/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:21:53 by skaynar           #+#    #+#             */
/*   Updated: 2025/03/14 17:21:54 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	finish_game(t_game *game)
{
	mlx_loop_end(game->mlx);
	mlx_clear_window(game->mlx, game->mlx_window);
	mlx_destroy_window(game->mlx, game->mlx_window);
	mlx_destroy_image(game->mlx, game->img.player);
	mlx_destroy_image(game->mlx, game->img.floor);
	mlx_destroy_image(game->mlx, game->img.coin);
	mlx_destroy_image(game->mlx, game->img.exit);
	mlx_destroy_image(game->mlx, game->img.wall);
	mlx_destroy_display(game->mlx);
	clear_array(game->map->realmap);
	clear_array(game->map->fakemap);
	free(game->mlx);
	freemalloc(game);
	exit(0);
}

void	is_won_game(t_game *game, int x, int y)
{
	if (game->coincount == 0 && game->map->realmap[y][x] == 'E')
	{
		ft_printf("step : %d\nYOU WON!\n", game->step + 1);
		finish_game(game);
	}
}

void	play(t_game *game, int x, int y)
{
	is_won_game(game, x, y);
	if (game->map->realmap[y][x] == '0' || game->map->realmap[y][x] == 'C')
	{
		game->step++;
		ft_printf("step : %d\n", game->step);
		if (game->map->realmap[y][x] == 'C')
			game->coincount--;
		game->map->realmap[game->map->py][game->map->px] = '0';
		game->map->realmap[y][x] = 'P';
		game->map->px = x;
		game->map->py = y;
	}
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		finish_game(game);
	else if (keycode == KEY_A)
		play(game, game->map->px - 1, game->map->py);
	else if (keycode == KEY_S)
		play(game, game->map->px, game->map->py + 1);
	else if (keycode == KEY_D)
		play(game, game->map->px + 1, game->map->py);
	else if (keycode == KEY_W)
		play(game, game->map->px, game->map->py - 1);
	mlx_clear_window(game->mlx, game->mlx_window);
	ft_place(game);
	return (keycode);
}
