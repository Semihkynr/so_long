/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slmain.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:59:28 by skaynar           #+#    #+#             */
/*   Updated: 2025/03/06 00:30:14 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int map_wallctl(t_game *game,char *str, int i)
// {
//     int a;
    
//     while (str[i])
//     {
//         while((game->usecount == 0 || game->usecount == max çağırma sayısı ) && str[i])
//         {
//             if(str[i] == '1' || str[i] == '\0')
//                 i++;
//             else
//             {
//                 printf("--%d\n",i);
//                 game->usecount++;
//                 return(write(1,"bura\n",6), 0);
//             }
//         }
//         while(str[i])
//         {
//             a = ft_strlen(str);
//             if(!(str[0] == '1') || str[a] == '1')
//                return(write(1,"Error\n",6), 0);
//             else 
//                 i++;
//         }
//     }
//     return(1);
// }

int check_map(t_game *game, char **av, int j)
{
    char *str;
    int fd;
    int a;
    
    fd = open(av[1], O_RDONLY);
    if(fd == -1)
        return(write(1,"Error\n",6),close(fd),0);
    str = get_next_line(fd);
    a = ft_strlen(str) - 1;
    while(str)
    {
        if(!(truemapfloor(str,game)))
            return(close(fd),free(str),0);
        j = game->usecount;
        if(!(newlinectl(str)))
            j++;
        game->width = j - 1;
        free(str);
        game->high++;
        str = get_next_line(fd);
        if(game->width != a)
            return(write(1,"Error\n",6),close(fd),free(str),0);
        free(str);
    }
    return(close(fd),1);
}

void newgame(t_game *game)
{
    game->coincount = 0;
    game->exitcount = 0;
    game->playercount = 0;
    game->step = 0;
    game->high = 0;
    game->width = 0;
    game->usecount = 0;
}
int main(int ac, char **av)
{
    t_game *game;
    
    if(ac != 2)
        return(write(1,"Error\nNumber of wrong arguments\n",32),0);
    game = malloc(sizeof(t_game));
    if(!game)
        return(write(1,"Error\nMalloc Error!",19),free(game),0);
    newgame(game);
    if(!check_map(game,av,0))
        return(free(game),0);
    if(!check_map_name(av[1]))
        return(free(game),0);
    return (free(game),0);
}
