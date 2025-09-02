/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:34:24 by kkeskin           #+#    #+#             */
/*   Updated: 2025/09/02 15:34:25 by kkeskin          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./get_next_line/get_next_line.h"
# include "./Libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include <fcntl.h>
# include <unistd.h>

typedef struct s_data
{
	char	**map;

	int		collectibles;
}				t_data;

//	----- Map Creation -----

t_data		*create_map(char *map_name);
t_data		*build_validation_map(char **map, t_vector2 map_size,
				char *map_name);

//	----- Validation Tools -----

t_vector2	find_component_location(char **map, char component);
int			check_if_map_surrounded_by_walls(char **map, t_vector2 map_size);
int			check_if_player_can_reach_door(char **map, t_vector2 map_size);
int			count_real_collectibles(char **map, t_vector2 map_size,
				char *map_name);

//	----- Free Functions -----

void		free_map(char **map);
void		free_data_exit(t_data *data);
void		error_exit_map_creation(char *read, int fd);
void		error_exit_validation(char **map, char **validation_map);

//	----- Debug Tools -----

void		print_map(char **map);

#endif
