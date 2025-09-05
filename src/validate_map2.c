/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 04:19:01 by kkeskin           #+#    #+#             */
/*   Updated: 2025/09/05 04:19:02 by kkeskin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_components(char **map, t_vector2 map_size)
{
	char	c;
	int		x;
	int		y;

	y = 0;
	while (y < map_size.y)
	{
		x = 0;
		while (x < map_size.x)
		{
			c = map[y][x];
			if (!(c == '1' || c == '0' || c == 'C'
					|| c == 'E' || c == 'D' || c == 'P'))
			{
				free_map(map);
				ft_putstr_fd("Error!\n", 1);
				exit (1);
			}
			x++;
		}
		y++;
	}
}

void	check_borders(char **map, t_vector2 map_size)
{
	int	y;
	int	x;

	x = 0;
	while (x < map_size.x)
	{
		if (map[0][x] != '1' || map[map_size.y - 1][x] != '1')
		{
			ft_putstr_fd("Error!\n", 1);
			free_map(map);
			exit(1);
		}
		x++;
	}
	y = 0;
	while (y < map_size.y)
	{
		if (map[y][0] != '1' || map[y][map_size.x - 1] != '1')
		{
			ft_putstr_fd("Error!\n", 1);
			free_map(map);
			exit(1);
		}
		y++;
	}
}
