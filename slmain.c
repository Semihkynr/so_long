/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slmain.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:59:28 by skaynar           #+#    #+#             */
/*   Updated: 2025/03/13 15:52:46 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void freegnl(int fd)
{
	char *str;
	str= get_next_line(fd);
	while(str)
	{
		free(str);
		str= get_next_line(fd);
	}	
}
int check_map(t_game *game, char **av, int j, int a)
{
    char *str;
    int fd;
    
    fd = open(av[1], O_RDONLY);
    if(fd == -1)
        return(close(fd),0);
    str = get_next_line(fd);
    a = ft_strlen(str) - 1;
    if(a == -1)
        return(close(fd),free(str),0);    
    while(str)
    {
        if(!(truemapfloor(str,game)))
            return(close(fd),free(str),0);
        j = game->width;
        if(!(newlinectl(str)))
            j++;
        game->width = j - 1;
        game->high++;
        free(str);
        str = get_next_line(fd);
        if(game->width != a)
            return(freegnl(fd),close(fd),free(str),0);
    }
    return(close(fd),free(str),1);
}

void    freemalloc(t_game *game)
{
    free(game->map);
    free(game);
}

void newgame(t_game *game)
{
    game->coincount = 0;
    game->exitcount = 0;
    game->playercount = 0;
    game->step = 0;
    game->high = 0;
    game->width = 0;
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
				game->map->px= j;
				game->map->py = i;
			}
		}
	}
}

void	put_place(t_game *game, char ch, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_window, game->img.floor, x, y);
	if (ch == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_window, game->img.coin, x, y);
	else if (ch == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_window, game->img.exit, x, y);
	else if (ch == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_window, game->img.wall, x, y);
	else if (ch == 'P')
	{
		where_player(game);
		mlx_put_image_to_window(game->mlx, game->mlx_window, game->img.player, x, y);
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
int	finish_game(t_game *game)
{	
	mlx_loop_end(game->mlx);
	mlx_destroy_image(game->mlx,PLAYER_P);
	mlx_destroy_image(game->mlx,EXIT_P);
	mlx_destroy_image(game->mlx,COIN_P);
	mlx_destroy_image(game->mlx,FLOOR_P);
	mlx_destroy_image(game->mlx,WALL_P);
	mlx_destroy_window(game->mlx,game->mlx_window);
	mlx_destroy_display(game->mlx);
	clear_array(game->map->realmap);
	clear_array(game->map->fakemap);
	free(game->mlx);
    free(game->map);
    free(game);
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
int	xpmopenctl(char *path_xpm)
{
	int	fd;

	fd = open(path_xpm, O_RDONLY);
	if (fd <= 0)
	{
		close(fd);
		return(0);
	}
	close(fd);
    return(1);
}
int	xpmctl(void)
{
	if(!xpmopenctl(COIN_P) || !xpmopenctl(WALL_P) || !xpmopenctl(FLOOR_P) 
    || !xpmopenctl(EXIT_P) || !xpmopenctl(PLAYER_P))
        return(ft_printf("%s\n","XPM NOT OPEN!") ,0);
    return(1);
}
void	image_paths(t_game *game)
{
	int	w;
	int	h;
    game->img.player = mlx_xpm_file_to_image(game->mlx, PLAYER_P, &w, &h);
	game->img.coin = mlx_xpm_file_to_image(game->mlx, COIN_P, &w, &h);
	game->img.floor = mlx_xpm_file_to_image(game->mlx, FLOOR_P, &w, &h);
	game->img.exit = mlx_xpm_file_to_image(game->mlx, EXIT_P, &w, &h);
	game->img.wall = mlx_xpm_file_to_image(game->mlx, WALL_P, &w, &h);
}
void	play(t_game *game, int x, int y)
{
	is_won_game(game, x, y);
	if (game->map->realmap[y][x] == '0'
		|| game->map->realmap[y][x] == 'C')
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
		play(game, game->map->px- 1, game->map->py);
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
int allcheck(char **av, t_game *game)
{
	newgame(game);
	if(!check_map(game,av,0,0))
		return(write(1,"Error\n", 6),0);
    if(!mapargctl(game,av))
		return(write(1,"Error\n", 6),freemalloc(game),0);
    game->map->realmap = copymap(game,av[1]);
    if(!map_wallctl(game ,game->map->realmap,0,0))
		return(clear_array(game->map->realmap),freemalloc(game),write(1,"Error\n",6),0);
    game->map->fakemap = copymap(game,av[1]);
	flood_fill(game->map->py - 1, game->map->px - 1, game);
    if(!is_reachable(game->map->fakemap))
		return (clear_array(game->map->fakemap),clear_array(game->map->realmap),freemalloc(game),write(1,"Error\n",6),0);
	if(!xpmctl())
		return(clear_array(game->map->fakemap),clear_array(game->map->realmap),freemalloc(game),0);
	return(1);
}

int main(int ac, char **av)
{
    t_game *game;
    
    if(ac != 2)
        return(write(1,"Error\nNumber of wrong arguments\n",32),0);
    if(!check_map_name(av[1]))
        return(0);
    game = malloc(sizeof(t_game));
    game->map = malloc(sizeof(t_map));
    if(!game || !game->map)
	    return(write(1,"Error\nMalloc Error!",19),freemalloc(game),0);
	if(!allcheck(av,game))
		return(free(game->map),free(game),0);
	if(game->width * 64 > 1920 || game->high > 1080)
    	return (clear_array(game->map->fakemap),clear_array(game->map->realmap),ft_printf("Error\n"),freemalloc(game),0);	
    game->mlx = mlx_init();
    game->mlx_window = mlx_new_window(game->mlx,game->width * 64, game->high * 64, "so_long");
    where_player(game);
    image_paths(game);
    ft_place(game);
    mlx_key_hook(game->mlx_window, key_hook, game);
    mlx_hook(game->mlx_window, 17, 0L, finish_game, game);
	mlx_loop(game->mlx);
    return (clear_array(game->map->fakemap),clear_array(game->map->realmap),freemalloc(game),0);
}
