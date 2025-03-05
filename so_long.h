/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:46:57 by skaynar           #+#    #+#             */
/*   Updated: 2025/03/06 00:05:28 by skaynar          ###   ########.fr       */
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
    int    usecount;
}              t_game;

int	ft_strlen(const char *str);
int newlinectl(char *str);
int truemapfloor(char *str,t_game *game);
int mapargctl(t_game *game);
int	check_map_name(char *str);


#endif