/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapctl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 23:30:49 by skaynar           #+#    #+#             */
/*   Updated: 2025/03/06 00:19:39 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int newlinectl(char *str)
{
    int i;
    i = 0;
    while(str[i])
    {
        if(str[i] == '\n')
            return(1);
        else 
            i++;
    }
    return (0);
}

int mapargctl(t_game *game)
{
    if(!(game->coincount > 0))
        return(write(1,"Error\n", 6), 0);
    if(game->exitcount != 1)
        return(write(1,"Error\n", 6), 0);
    if(game->playercount != 1)   
        return(write(1,"Error\n", 6), 0);
    return(1);
}

int truemapfloor(char *str,t_game *game)
{
    int j;
    j = 0;
    while(str[j])
    {
        if(str[j] != 'E' && str[j] != 'C' && str[j] != 'P' 
        && str[j] != '\0' && str[j] != '\n' && str[j] != '1' && str[j] != '0')
            return(write(1,"Error\n", 6), 0);
        if(str[j] == 'E')
            game->exitcount++;
        if(str[j] == 'C')
            game->coincount++;
        if(str[j] == 'P')
            game->playercount++;
        j++;
        game->usecount = j;
    }
    return(1);
}

int	check_map_name(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len >= 4)
	{
		if (str[len - 1] == 'r' && str[len - 2] == 'e'
			&& str[len - 3] == 'b' && str[len - 4] == '.')
			return(1);
		else
			return(write(1,"Error\n",6), 0);
	}
    return(write(1,"1",1) ,0);
}
