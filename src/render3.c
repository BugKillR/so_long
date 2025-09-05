/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 04:16:28 by kkeskin           #+#    #+#             */
/*   Updated: 2025/09/05 04:16:29 by kkeskin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_door_n_player(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, data->sprites.g1, x, y);
}

void	put_door_open(t_data *data, int x, int y)
{
	if (data->sprites.e == data->sprites.e5)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->sprites.e5, x, y);
		data->sprites.e = data->sprites.e6;
	}
	else if (data->sprites.e == data->sprites.e6)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->sprites.e6, x, y);
		data->sprites.e = data->sprites.e7;
	}
	else if (data->sprites.e == data->sprites.e7)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->sprites.e7, x, y);
		data->sprites.e = data->sprites.e8;
	}
	else if (data->sprites.e == data->sprites.e8)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->sprites.e8, x, y);
		data->sprites.e = data->sprites.e5;
	}
	else
	{
		data->sprites.e = data->sprites.e5;
		mlx_put_image_to_window(data->mlx, data->win, data->sprites.e5, x, y);
	}
}

static char	*string_to_print(char *text, t_data *data)
{
	char	*full;
	char	*count;

	count = ft_itoa(data->movement_c);
	full = ft_strjoin(text, count);
	free(count);
	return (full);
}

void	put_str_on_screen(char *str, t_data *data)
{
	char	*text;

	text = string_to_print("Score: ", data);
	mlx_string_put(data->mlx, data->win, 10, 20, 0x00FFFFFF, text);
	free(text);
}

void	put_collectible2(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, data->sprites.c2, x, y);
	data->game_data->map[y / 64][x / 64] = 'C';
}
