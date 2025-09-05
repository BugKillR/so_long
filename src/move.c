/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 04:07:45 by kkeskin           #+#    #+#             */
/*   Updated: 2025/09/05 04:07:46 by kkeskin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_up(char **map, t_data *data, int y, int x)
{
	t_vector2	to_move;

	to_move = (t_vector2){.x = data->p_v2.x, .y = data->p_v2.y - 1};
	if (map[y - 1][x] == '1')
		return ;
	else if (map[y - 1][x] == 'E')
		door_player(data, to_move);
	else if (map[y - 1][x] == 'D')
	{
		print_movement_c(data);
		ft_putstr_fd("You died!\n", 1);
		free_data_and_exit(data, 0);
	}
	else if (map[y - 1][x] == 'C')
	{
		swap_player_space(data, to_move);
		data->game_data->collectibles--;
	}
	else
		swap_player_space(data, to_move);
	print_movement_c(data);
}

static void	move_left(char **map, t_data *data, int y, int x)
{
	t_vector2	to_move;

	to_move = (t_vector2){.x = data->p_v2.x - 1, .y = data->p_v2.y};
	if (map[y][x - 1] == '1')
		return ;
	else if (map[y][x - 1] == 'E')
		door_player(data, to_move);
	else if (map[y][x - 1] == 'D')
	{
		print_movement_c(data);
		ft_putstr_fd("You died!\n", 1);
		free_data_and_exit(data, 0);
	}
	else if (map[y][x - 1] == 'C')
	{
		swap_player_space(data, to_move);
		data->game_data->collectibles--;
	}
	else
		swap_player_space(data, to_move);
	print_movement_c(data);
}

static void	move_down(char **map, t_data *data, int y, int x)
{
	t_vector2	to_move;

	to_move = (t_vector2){.x = data->p_v2.x, .y = data->p_v2.y + 1};
	if (map[y + 1][x] == '1')
		return ;
	else if (map[y + 1][x] == 'E')
		door_player(data, to_move);
	else if (map[y + 1][x] == 'D')
	{
		print_movement_c(data);
		ft_putstr_fd("You died!\n", 1);
		free_data_and_exit(data, 0);
	}
	else if (map[y + 1][x] == 'C')
	{
		swap_player_space(data, to_move);
		data->game_data->collectibles--;
	}
	else
		swap_player_space(data, to_move);
	print_movement_c(data);
}

static void	move_right(char **map, t_data *data, int y, int x)
{
	t_vector2	to_move;

	to_move = (t_vector2){.x = data->p_v2.x + 1, .y = data->p_v2.y};
	if (map[to_move.y][to_move.x] == '1')
		return ;
	else if (map[to_move.y][to_move.x] == 'E')
		door_player(data, to_move);
	else if (map[to_move.y][to_move.x] == 'D')
	{
		print_movement_c(data);
		ft_putstr_fd("You died!\n", 1);
		free_data_and_exit(data, 0);
	}
	else if (map[to_move.y][to_move.x] == 'C')
	{
		swap_player_space(data, to_move);
		data->game_data->collectibles--;
	}
	else
		swap_player_space(data, to_move);
	print_movement_c(data);
}

void	move(char *rotation, char **map, t_data *data)
{
	if (rotation == "Up")
		move_up(map, data, data->p_v2.y, data->p_v2.x);
	else if (rotation == "Left")
		move_left(map, data, data->p_v2.y, data->p_v2.x);
	else if (rotation == "Down")
		move_down(map, data, data->p_v2.y, data->p_v2.x);
	else if (rotation == "Right")
		move_right(map, data, data->p_v2.y, data->p_v2.x);
}
