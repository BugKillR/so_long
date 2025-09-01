#ifndef SO_LONG_H
# define SO_LONG_H

# include "./get_next_line/get_next_line.h"
# include "./Libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include <fcntl.h>
# include <unistd.h>

char	**create_map(char *map_name);
void    free_map(char **map);

#endif