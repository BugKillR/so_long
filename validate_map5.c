/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:41:24 by kkeskin           #+#    #+#             */
/*   Updated: 2025/09/02 15:41:24 by kkeskin          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	convert_extra_components_to_space_no_e(char **map)
{
	int	i;
	int	k;

	i = 0;
	while (map[i])
	{
		k = 0;
		while (map[i][k])
		{
			if (map[i][k] == 'D' || map[i][k] == 'C')
				map[i][k] = '0';
			k++;
		}
		i++;
	}
}

static void	convert_door_to_e_if_reachable(char **map, t_vector2 map_size)
{
	int	y;
	int	x;

	y = 1;
	while (y <= map_size.y)
	{
		x = 1;
		while (x <= map_size.x)
		{
			if (map[y][x] == 'E')
			{
				if (map[y - 1][x] == 'F'
					|| map[y + 1][x] == 'F'
					|| map[y][x - 1] == 'F'
					|| map[y][x + 1] == 'F')
					map[y][x] = 'e';
			}
			x++;
		}
		y++;
	}
}

static int	count_e(char **map)
{
	int	count;
	int	x;
	int	y;

	count = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'e')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

int	check_if_player_can_reach_door(char **map, t_vector2 map_size)
{
	t_flood_fill_data	flood_data;

	flood_data.curr = find_component_location(map, 'P');
	flood_data.size = (t_vector2){map_size.x + 2, map_size.y + 2};
	flood_data.ignored = 'P';
	convert_extra_components_to_space_no_e(map);
	ft_flood_fill(map, flood_data, '0', 'F');
	convert_door_to_e_if_reachable(map, map_size);
	if (count_e(map) != 1)
		return (ft_putstr_fd("Door isn't reachable!\n", 1), free_map(map), 0);
	return (ft_putstr_fd("Door is reachable!\n", 1), free_map(map), 1);
}
