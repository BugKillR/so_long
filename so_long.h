#ifndef SO_LONG_H
# define SO_LONG_H

# include "./get_next_line/get_next_line.h"
# include "./Libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include <fcntl.h>
# include <unistd.h>

typedef struct  s_data
{
    char    **map;

    int     collectibles;
}               t_data;

char	**create_map(char *map_name);
void    free_map(char **map);
void	error_exit_map_creation(char *read, int fd);
void    error_exit_validation(char **map, char **validation_map);
t_data	*build_validation_map(char **map, t_vector2 map_size);
int     check_if_map_surrounded_by_walls(char **map, t_vector2 map_size);
void	print_map(char **map);

#endif