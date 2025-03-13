#include "so_long.h"

int	xpmopenctl(char *path_xpm)
{
	int	fd;

	fd = open(path_xpm, O_RDONLY);
	if (fd <= 0)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int	xpmctl(void)
{
	if (!xpmopenctl(COIN_P) || !xpmopenctl(WALL_P) || !xpmopenctl(FLOOR_P)
		|| !xpmopenctl(EXIT_P) || !xpmopenctl(PLAYER_P))
		return (ft_printf("%s\n", "XPM NOT OPEN!"), 0);
	return (1);
}

void	put_place(t_game *game, char ch, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_window, game->img.floor, x, y);
	if (ch == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_window, game->img.coin, x,
			y);
	else if (ch == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_window, game->img.exit, x,
			y);
	else if (ch == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_window, game->img.wall, x,
			y);
	else if (ch == 'P')
	{
		where_player(game);
		mlx_put_image_to_window(game->mlx, game->mlx_window, game->img.player,
			x, y);
	}
}

void	ft_place(t_game *game)
{
	int	i;
	int	j;

	j = -1;
	while (++j < game->high)
	{
		i = -1;
		while (++i < game->width)
		{
			put_place(game, game->map->realmap[j][i], i * 64, j * 64);
		}
	}
}

void	image_paths(t_game *game)
{
	int	w;
	int	h;

	where_player(game);
	game->img.player = mlx_xpm_file_to_image(game->mlx, PLAYER_P, &w, &h);
	game->img.coin = mlx_xpm_file_to_image(game->mlx, COIN_P, &w, &h);
	game->img.floor = mlx_xpm_file_to_image(game->mlx, FLOOR_P, &w, &h);
	game->img.exit = mlx_xpm_file_to_image(game->mlx, EXIT_P, &w, &h);
	game->img.wall = mlx_xpm_file_to_image(game->mlx, WALL_P, &w, &h);
	ft_place(game);
}
