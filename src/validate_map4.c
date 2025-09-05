/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:39:50 by kkeskin           #+#    #+#             */
/*   Updated: 2025/09/02 15:39:50 by kkeskin          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	convert_extra_components_to_space_no_c(char **map)
{
	int	i;
	int	k;

	i = 0;
	while (map[i])
	{
		k = 0;
		while (map[i][k])
		{
			if (map[i][k] == 'E')
				map[i][k] = '0';
			k++;
		}
		i++;
	}
}

static void	convert_real_collectibles_to_k(char **map, t_vector2 map_size)
{
	int	y;
	int	x;

	y = 1;
	while (y <= map_size.y)
	{
		x = 1;
		while (x <= map_size.x)
		{
			if (map[y][x] == 'C')
			{
				if (map[y - 1][x] == 'F'
					|| map[y + 1][x] == 'F'
					|| map[y][x - 1] == 'F'
					|| map[y][x + 1] == 'F')
					map[y][x] = 'K';
			}
			x++;
		}
		y++;
	}
}

static int	count_k(char **map)
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
			if (map[y][x] == 'K')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

int	count_real_collectibles(char **map, t_vector2 map_size, char *map_name)
{
	t_flood_fill_data	flood_data;
	int					count_reachable;
	int					count_all;
	int					y;

	count_reachable = 0;
	count_all = 0;
	y = 0;
	while (y < map_size.y)
	{
		count_all += ft_count_chr(map[y], 'C');
		y++;
	}
	flood_data.curr = find_component_location(map, 'P');
	flood_data.size = (t_vector2){map_size.x + 2, map_size.y + 2};
	flood_data.ignored = 'P';
	convert_extra_components_to_space_no_c(map);
	ft_flood_fill(map, flood_data, '0', 'F');
	convert_real_collectibles_to_k(map, map_size);
	count_reachable = count_k(map);
	if (count_all != count_reachable)
		count_reachable = 0;
	free_map(map);
	return (count_reachable);
}
