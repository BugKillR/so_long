#include "so_long.h"

void	print_map(char **map)
{
	int	i;
	
	i = 0;
	while (map[i])
	{
		ft_putendl_fd(map[i], 1);
		i++;
	}
}