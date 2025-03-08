/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:46:57 by skaynar           #+#    #+#             */
/*   Updated: 2025/03/08 16:58:30 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG_H
#define SO_LONG_H

# include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

typedef struct s_game
{
    int    playercount;
    int    exitcount;
    int    coincount;
    int    step;
    int    high;
    int    width;
    int    px;
    int    py;
}              t_game;

int	ft_strlen(const char *str);
int newlinectl(char *str);
int truemapfloor(char *str,t_game *game);
int mapargctl(t_game *game);
int	check_map_name(char *str);
int map_wallctl(t_game *game,char **str, int i , int j);
char **copymap(t_game *game , char *map);


#endif