#include "so_long.h"

void error_exit_validation(char **map, char **validation_map)
{
    if (map)
        free_map(map);
    if (validation_map)
        free_map(validation_map);
    exit (1);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while(map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	error_exit_map_creation(char *read, int fd)
{
	if (read)
		free(read);
	close(fd);
	ft_putstr_fd("Invalid Map Or Invalid Map Name!\n", 1);
	exit (1);
}
