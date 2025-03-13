/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmapctl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:35:51 by skaynar           #+#    #+#             */
/*   Updated: 2025/03/13 15:10:52 by skaynar          ###   ########.fr       */
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
int     is_reachable(char **map)
{
	int	i;
	int	j;

	i = 0;
    
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'P' || map[i][j] == 'E')
				return(0);
			j++;
		}
		i++;
	}
    
    return(1);
}
void	flood_fill(int x, int y, t_game *game)
{
	char	c;
    
	c = game->map->fakemap[x][y];
	if (c == '1')
		return ;
	game->map->fakemap[x][y] = '1';
	if (c == 'E' || c == 'C')
		return ;
	flood_fill(x + 1, y, game);
	flood_fill(x - 1, y, game);
	flood_fill(x, y + 1, game);
	flood_fill(x, y - 1, game);
}
