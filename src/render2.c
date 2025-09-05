/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 04:15:40 by kkeskin           #+#    #+#             */
/*   Updated: 2025/09/05 04:15:41 by kkeskin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_player(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, data->sprites.p, x, y);
}

void	put_collectible1(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, data->sprites.c1, x, y);
	data->game_data->map[y / 64][x / 64] = 'K';
}

void	put_wall(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, data->sprites.w1, x, y);
}

void	put_enemy(t_data *data, int x, int y)
{
	if (data->sprites.d == data->sprites.d1)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->sprites.d1, x, y);
		data->sprites.d = data->sprites.d2;
	}
	else if (data->sprites.d == data->sprites.d2)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->sprites.d2, x, y);
		data->sprites.d = data->sprites.d1;
	}
}

void	put_door(t_data *data, int x, int y)
{
	if (data->sprites.e == data->sprites.e1)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->sprites.e1, x, y);
		data->sprites.e = data->sprites.e2;
	}
	else if (data->sprites.e == data->sprites.e2)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->sprites.e2, x, y);
		data->sprites.e = data->sprites.e3;
	}
	else if (data->sprites.e == data->sprites.e3)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->sprites.e3, x, y);
		data->sprites.e = data->sprites.e4;
	}
	else if (data->sprites.e == data->sprites.e4)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->sprites.e4, x, y);
		data->sprites.e = data->sprites.e1;
	}
}
