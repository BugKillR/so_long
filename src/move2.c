/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 04:08:12 by kkeskin           #+#    #+#             */
/*   Updated: 2025/09/05 04:08:13 by kkeskin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_movement_c(t_data *data)
{
	data->movement_c += 1;
	ft_putstr_fd("Movement Count: ", 1);
	ft_putnbr_fd(data->movement_c, 1);
	ft_putchar_fd('\n', 1);
}

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
