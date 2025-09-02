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

void	free_data_exit(t_data *data)
{
	if (data)
	{
		if (data->map)
			free_map(data->map);
		free(data);
	}
	exit (0);
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
