/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 04:03:10 by kkeskin           #+#    #+#             */
/*   Updated: 2025/09/05 04:03:13 by kkeskin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_sprites2(t_data *data)
{
	if (data->sprites.e2)
		mlx_destroy_image(data->mlx, data->sprites.e2);
	if (data->sprites.e3)
		mlx_destroy_image(data->mlx, data->sprites.e3);
	if (data->sprites.e4)
		mlx_destroy_image(data->mlx, data->sprites.e4);
	if (data->sprites.e5)
		mlx_destroy_image(data->mlx, data->sprites.e5);
	if (data->sprites.e6)
		mlx_destroy_image(data->mlx, data->sprites.e6);
	if (data->sprites.e7)
		mlx_destroy_image(data->mlx, data->sprites.e7);
	if (data->sprites.e8)
		mlx_destroy_image(data->mlx, data->sprites.e8);
	if (data->sprites.c1)
		mlx_destroy_image(data->mlx, data->sprites.c1);
	if (data->sprites.c2)
		mlx_destroy_image(data->mlx, data->sprites.c2);
	if (data->sprites.w1)
		mlx_destroy_image(data->mlx, data->sprites.w1);
	if (data->sprites.g1)
		mlx_destroy_image(data->mlx, data->sprites.g1);
}

void	free_sprites(t_data *data)
{
	if (data->sprites.bg)
		mlx_destroy_image(data->mlx, data->sprites.bg);
	if (data->sprites.p1)
		mlx_destroy_image(data->mlx, data->sprites.p1);
	if (data->sprites.p2)
		mlx_destroy_image(data->mlx, data->sprites.p2);
	if (data->sprites.p3)
		mlx_destroy_image(data->mlx, data->sprites.p3);
	if (data->sprites.p4)
		mlx_destroy_image(data->mlx, data->sprites.p4);
	if (data->sprites.e1)
		mlx_destroy_image(data->mlx, data->sprites.e1);
	if (data->sprites.d1)
		mlx_destroy_image(data->mlx, data->sprites.d1);
	if (data->sprites.d2)
		mlx_destroy_image(data->mlx, data->sprites.d2);
	free_sprites2(data);
}
