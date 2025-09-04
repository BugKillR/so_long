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

# include "../get_next_line/get_next_line.h"
# include "../Libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <unistd.h>

# define MAX_WIDTH_ON_DEVICE 3840
# define MAX_HEIGHT_ON_DEVICE 2160

# define KEY_ESC	65307
# define KEY_Q		113
# define KEY_LEFT	65361
# define KEY_UP		65362
# define KEY_RIGHT	65363
# define KEY_DOWN	65364
# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100

typedef struct s_game_data
{
	t_vector2	map_size;
	t_vector2	door_location;
	char		*map_name;
	char		**map;

	int			collectibles;
}				t_game_data;

typedef struct s_sprites
{
	void	*bg;
	void	*p1;
	void	*e1;
	void	*d1;
	void	*c1;
	void	*w1;
}				t_sprites;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			line_len;
	int			endian;
	int			bpp;
	int			w;
	int			h;

	t_game_data	*game_data;
	t_sprites	sprites;
	t_vector2	p_v2;
	int			movement_c;
}				t_data;

//	----- Map Creation -----

t_game_data	*create_map(char *map_name);
t_game_data	*build_validation_map(char **map, t_vector2 map_size,
				char *map_name);

//	----- Validation Tools -----

void		validate_components(char **map, t_vector2 map_size);
t_vector2	find_component_location(char **map, char component);
int			check_if_map_surrounded_by_walls(char **map, t_vector2 map_size);
int			check_if_player_can_reach_door(char **map, t_vector2 map_size);
int			count_real_collectibles(char **map, t_vector2 map_size,
				char *map_name);

//	----- Free Functions -----

void		free_map(char **map);
void		free_game_data_exit(t_game_data *data);
void		error_exit_map_creation(char *read, int fd);
void		error_exit_validation(char **map, char **validation_map);
void		free_data_and_exit(t_data *data, int exitcode);
void		free_sprites(t_data *data);

//	----- Debug Tools -----

void		print_map(char **map);

//	----- MLX Part -----

void		mlx_setup(t_game_data *game_data);
int			keybinds(int keycode, void *param);
int			render(t_data *data);

//	----- Movement -----

void		move(char *rotation, char **map, t_data *data);
void		door_player(t_data *data, t_vector2 to_move);
void		swap_player_space(t_data *data, t_vector2 to_move);
void 		put_collectible(t_data *data, int x, int y);
void		put_player(t_data *data, int x, int y);
void		put_wall(t_data *data, int x, int y);
void		put_enemy(t_data *data, int x, int y);
void		put_door(t_data *data, int x, int y);

#endif
