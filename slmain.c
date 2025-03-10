/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slmain.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:59:28 by skaynar           #+#    #+#             */
/*   Updated: 2025/03/08 17:07:45 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
        j = game->width;
        if(!(newlinectl(str)))
            j++;
        game->width = j -1;
        game->high++;
        free(str);
        str = get_next_line(fd);
        if(game->width != a)
            return(write(1,"Error\n",6),close(fd),free(str),0);
    }
    return(close(fd),free(str),1);
}

void newgame(t_game *game)
{
    game->coincount = 0;
    game->exitcount = 0;
    game->playercount = 0;
    game->step = 0;
    game->high = 0;
    game->width = 0;
    game->px = 0;
    game->py = 0;
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
    if(!mapargctl(game))
        return(write(1,"Error\n", 6), 0);
    if(!check_map_name(av[1]))
        return(free(game),0);
    if(!map_wallctl(game ,copymap(game,av[1]),0,0))
        return(free(game),write(1,"Error\n",6),0);
    printf("xxxxxx%d\n",game->px);
    printf("yyyyyy%d\n",game->py);
    // y nin x y si oluşturuldu ,indexli yani 0 dan başlıyo ,flootfill yazılcak, sonda new line varsa sıkıntı çıkması lazım çıkmıyo o kontrol edilcek
    // float fill + new line kontrolü + mlx komutları + leakler kaldı:)
    return (free(game),0);
}
