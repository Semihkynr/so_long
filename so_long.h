/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:46:57 by skaynar           #+#    #+#             */
/*   Updated: 2025/03/13 17:46:37 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "get_next_line.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef PATHS_TEXTURES
#  define COIN_P "textures/coin.xpm"
#  define WALL_P "textures/wall.xpm"
#  define EXIT_P "textures/exit.xpm"
#  define FLOOR_P "textures/floor.xpm"
#  define PLAYER_P "textures/player.xpm"
# endif

enum			e_key_codes
{
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100,
	KEY_W = 119,
	KEY_ESC = 65307
};

typedef struct s_images
{
	void		*player;
	void		*exit;
	void		*coin;
	void		*wall;
	void		*floor;
}				t_images;

typedef struct s_map
{
	int			px;
	int			py;
	char		**realmap;
	char		**fakemap;
}				t_map;

typedef struct s_game
{
	int			playercount;
	int			exitcount;
	int			coincount;
	int			step;
	int			high;
	int			width;
	t_map		*map;
	t_images	img;
	void		*mlx;
	void		*mlx_window;
}				t_game;

void			where_player(t_game *game);
int				finish_game(t_game *game);
int				key_hook(int keycode, t_game *game);
void			image_paths(t_game *game);
int				xpmctl(void);
void			ft_place(t_game *game);
void			freegnl(int fd);
void			freemalloc(t_game *game);
void			clear_array(char **array);
void			flood_fill(int x, int y, t_game *game);
int				is_reachable(char **map);
int				ft_strlen(const char *str);
int				newlinectl(char *str);
int				truemapfloor(char *str, t_game *game);
int				mapargctl(t_game *game, char **av);
int				check_map_name(char *str);
int				map_wallctl(t_game *game, char **str, int i, int j);
char			**copymap(t_game *game, char *map);

#endif