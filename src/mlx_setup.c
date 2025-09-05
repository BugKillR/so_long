/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 04:05:19 by kkeskin           #+#    #+#             */
/*   Updated: 2025/09/05 04:05:20 by kkeskin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_sprites	set_sprites2(t_data *data, t_sprites sprites)
{
	int	w;
	int	h;

	sprites.e1 = mlx_xpm_file_to_image(data->mlx,
			"./textures/Door1.xpm", &w, &h);
	sprites.e2 = mlx_xpm_file_to_image(data->mlx,
			"./textures/Door2.xpm", &w, &h);
	sprites.e3 = mlx_xpm_file_to_image(data->mlx,
			"./textures/Door3.xpm", &w, &h);
	sprites.e4 = mlx_xpm_file_to_image(data->mlx,
			"./textures/Door4.xpm", &w, &h);
	sprites.e5 = mlx_xpm_file_to_image(data->mlx,
			"./textures/Door5.xpm", &w, &h);
	sprites.e6 = mlx_xpm_file_to_image(data->mlx,
			"./textures/Door6.xpm", &w, &h);
	sprites.e7 = mlx_xpm_file_to_image(data->mlx,
			"./textures/Door7.xpm", &w, &h);
	sprites.e8 = mlx_xpm_file_to_image(data->mlx,
			"./textures/Door8.xpm", &w, &h);
	sprites.g1 = mlx_xpm_file_to_image(data->mlx,
			"./textures/DoorNPlayer.xpm", &w, &h);
	sprites.d2 = mlx_xpm_file_to_image(data->mlx,
			"./textures/Enemy2.xpm", &w, &h);
	return (sprites);
}

static t_sprites	set_sprites(t_data *data)
{
	t_sprites	sprites;
	int			w;
	int			h;

	sprites.bg = mlx_xpm_file_to_image(data->mlx,
			"./textures/Background.xpm", &w, &h);
	sprites.p1 = mlx_xpm_file_to_image(data->mlx,
			"./textures/PlayerIdle.xpm", &w, &h);
	sprites.p2 = mlx_xpm_file_to_image(data->mlx,
			"./textures/PlayerUp.xpm", &w, &h);
	sprites.p3 = mlx_xpm_file_to_image(data->mlx,
			"./textures/PlayerRight.xpm", &w, &h);
	sprites.p4 = mlx_xpm_file_to_image(data->mlx,
			"./textures/PlayerLeft.xpm", &w, &h);
	sprites.d1 = mlx_xpm_file_to_image(data->mlx,
			"./textures/Enemy.xpm", &w, &h);
	sprites.c1 = mlx_xpm_file_to_image(data->mlx,
			"./textures/Coll1.xpm", &w, &h);
	sprites.c2 = mlx_xpm_file_to_image(data->mlx,
			"./textures/Coll2.xpm", &w, &h);
	sprites.w1 = mlx_xpm_file_to_image(data->mlx,
			"./textures/Wall.xpm", &w, &h);
	sprites = set_sprites2(data, sprites);
	return (sprites);
}

static t_data	*instantiate_data(t_game_data *game_data)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		free_game_data_exit(game_data);
	data->game_data = game_data;
	data->movement_c = 0;
	data->w = data->game_data->map_size.x * 64;
	data->h = data->game_data->map_size.y * 64;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->w, data->h,
			game_data->map_name);
	data->img = mlx_new_image(data->mlx, data->w, data->h);
	data->addr = mlx_get_data_addr(data->img, &data->bpp,
			&data->line_len, &data->endian);
	ft_putstr_fd("\n ----------- Game ----------- \n\n", 1);
	return (data);
}

static void	set_walls(t_data *data, t_vector2 map_size)
{
	int	y;
	int	x;

	y = 0;
	while (y < map_size.y)
	{
		x = 0;
		while (x < map_size.x)
		{
			if (data->game_data->map[y][x] == '1')
				put_wall(data, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	mlx_setup(t_game_data *game_data)
{
	t_sprites	sprites;
	t_data		*data;

	data = instantiate_data(game_data);
	data->sprites = set_sprites(data);
	data->sprites.p = data->sprites.p1;
	data->sprites.e = data->sprites.e1;
	data->sprites.d = data->sprites.d1;
	if (data->w > MAX_WIDTH_ON_DEVICE || data->h > MAX_HEIGHT_ON_DEVICE)
	{
		ft_putstr_fd("Map is bigger than screen!\nMap Width: ", 1);
		ft_putnbr_fd(data->w, 1);
		ft_putstr_fd(" Map Height: ", 1);
		ft_putnbr_fd(data->h, 1);
		ft_putstr_fd("\n", 1);
		free_data_and_exit(data, 1);
	}
	data->game_data->door_location
		= find_component_location(data->game_data->map, 'E');
	set_walls(data, data->game_data->map_size);
	mlx_hook(data->win, DESTROY_NOTIFY, 0, close_window, data);
	mlx_key_hook(data->win, keybinds, data);
	mlx_loop_hook(data->mlx, render, data);
	mlx_loop(data->mlx);
	return ;
}
