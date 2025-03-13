#include "so_long.h"

void	freegnl(int fd)
{
	char	*str;

	str = get_next_line(fd);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
	}
}

void	freemalloc(t_game *game)
{
	free(game->map);
	free(game);
}

void	clear_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}
