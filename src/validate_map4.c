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

static void	convert_extra_components_to_space(char **map)
{
	int	i;
	int	k;

	i = 0;
	while (map[i])
	{
		k = 0;
		while (map[i][k])
		{
			if (map[i][k] == 'E' || map[i][k] == 'C')
				map[i][k] = '0';
			k++;
		}
		i++;
	}
}

static void	convert_real_collectibles_to_k(char **map, char **new_map,
	int y, int x)
{
	if (map[y][x] == 'C' && new_map[y][x] == 'F')
		map[y][x] = 'K';
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

static int	compare_maps(char **map, t_vector2 map_size)
{
	t_flood_fill_data	flood_data;
	char				**new_map;
	int					y;
	int					x;

	new_map = duplicate_map(map, map, map_size);
	if (!new_map)
		return (0);
	convert_extra_components_to_space(new_map);
	flood_data.curr = find_component_location(new_map, 'P');
	flood_data.size = (t_vector2){map_size.x + 2, map_size.y + 2};
	flood_data.ignored = 'P';
	ft_flood_fill(new_map, flood_data, '0', 'F');
	y = 0;
	while (y < map_size.y)
	{
		x = 0;
		while (x < map_size.x)
		{
			convert_real_collectibles_to_k(map, new_map, y, x);
			x++;
		}
		y++;
	}
	return (free_map(new_map), 1);
}

int	count_real_collectibles(char **map, t_vector2 map_size, char *map_name)
{
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
	if (!compare_maps(map, map_size))
		return (0);
	count_reachable = count_k(map);
	if (count_all != count_reachable)
		count_reachable = 0;
	print_map(map);
	free_map(map);
	return (count_reachable);
}
