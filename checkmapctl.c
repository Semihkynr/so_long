/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmapctl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:35:51 by skaynar           #+#    #+#             */
/*   Updated: 2025/03/08 15:01:43 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int map_wallctl(t_game *game,char **str, int i , int j)
{    
    while (str[i])
    {
        while(str[0][j])
        {
            if(str[0][j] != '1'&& str[0][j] != '\n')
                return(0);
            j++;
        }
        j = 0;
        while(str[game->high - 1][j])
        {
            if(str[game->high - 1][j] != '1' && str[0][j] != '\n')
                return(0);
            j++;
        }
        j = 0;
        while(str[i]&& str[0][j] != '\n' && i < game->high)
        {
            if(str[i][0] != '1' || str[i][game->width -1] != '1')
                return(0);
            i++;
        }
    }
    return(1);
}

char **copymap(t_game *game , char *map)
{
    int fd;
    char **newmap;
    int i;
    i = 0;
    newmap = malloc(sizeof(char *) * (game->high + 1));
    
    fd = open(map, O_RDONLY);
    while ((newmap[i] = get_next_line(fd)))
        i++;
    close(fd);
    return(newmap);
}
