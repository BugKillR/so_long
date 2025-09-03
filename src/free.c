/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:27:57 by kkeskin           #+#    #+#             */
/*   Updated: 2025/09/02 15:27:58 by kkeskin          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit_validation(char **map, char **validation_map)
{
	if (map)
		free_map(map);
	if (validation_map)
		free_map(validation_map);
	exit (1);
}

void	free_game_data_exit(t_game_data *data)
{
	if (data)
	{
		if (data->map)
			free_map(data->map);
		free(data);
	}
	exit (0);
}

void free_data_and_exit(t_data *data, int exitcode)
{
	if (data->game_data)
	{
		if (data->game_data->map)
			free_map(data->game_data->map);
		free(data->game_data);
	}
	if (data->mlx && data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->mlx && data->win)
		mlx_destroy_window(data->mlx, data->win);
	free_sprites(data);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	free(data);
	exit (exitcode);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	error_exit_map_creation(char *read, int fd)
{
	if (read)
		free(read);
	close(fd);
	ft_putstr_fd("Invalid Map Or Invalid Map Name!\n", 1);
	exit (1);
}
