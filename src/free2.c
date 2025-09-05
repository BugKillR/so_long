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

void	free_sprites(t_data *data)
{
	if (data->sprites.bg)
		mlx_destroy_image(data->mlx, data->sprites.bg);
	if (data->sprites.p1)
		mlx_destroy_image(data->mlx, data->sprites.p1);
	if (data->sprites.e1)
		mlx_destroy_image(data->mlx, data->sprites.e1);
	if (data->sprites.e2)
		mlx_destroy_image(data->mlx, data->sprites.e2);
	if (data->sprites.d1)
		mlx_destroy_image(data->mlx, data->sprites.d1);
	if (data->sprites.c1)
		mlx_destroy_image(data->mlx, data->sprites.c1);
	if (data->sprites.c2)
		mlx_destroy_image(data->mlx, data->sprites.c2);
	if (data->sprites.w1)
		mlx_destroy_image(data->mlx, data->sprites.w1);
	if (data->sprites.g1)
		mlx_destroy_image(data->mlx, data->sprites.g1);
}
