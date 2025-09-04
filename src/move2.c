#include "so_long.h"

void	door_player(t_data *data, t_vector2 to_move)
{
	if (data->game_data->collectibles == 0)
	{
		ft_putstr_fd("Congratz!\n", 1);
		free_data_and_exit(data, 0);
	}
	else
	{
		data->game_data->map[to_move.y][to_move.x] = 'G';
		data->game_data->map[data->p_v2.y][data->p_v2.x] = '0';
	}
}

void	swap_player_space(t_data *data, t_vector2 to_move)
{
	data->game_data->map[to_move.y][to_move.x] = 'P';
	data->game_data->map[data->p_v2.y][data->p_v2.x] = '0'; 
}