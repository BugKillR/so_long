/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:36:10 by kkeskin           #+#    #+#             */
/*   Updated: 2025/09/02 15:36:11 by kkeskin          ###   ########.tr       */
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
			if (map[i][k] == 'E' || map[i][k] == 'C' || map[i][k] == 'D')
				map[i][k] = '0';
			k++;
		}
		i++;
	}
}

t_vector2	find_component_location(char **map, char component)
{
	int	i;
	int	k;

	i = 0;
	while (map[i])
	{
		k = 0;
		while (map[i][k])
		{
			if (map[i][k] == component)
				return ((t_vector2){.x = k, .y = i});
			k++;
		}
		i++;
	}
	return ((t_vector2){.x = -1, .y = -1});
}

int	check_if_map_surrounded_by_walls(char **map, t_vector2 map_size)
{
	t_flood_fill_data	flood_data;
	t_vector2			beginning;
	t_vector2			size;

	beginning = find_component_location(map, 'P');
	convert_extra_components_to_space(map);
	size = (t_vector2){.x = map_size.x + 2, .y = map_size.y + 2};
	flood_data.curr = beginning;
	flood_data.size = size;
	flood_data.ignored = 'P';
	ft_flood_fill(map, flood_data, '0', 'F');
	if (map[0][0] == '0'
		&& map[0][map_size.x + 1] == '0'
		&& map[map_size.y + 1][0] == '0'
		&& map[map_size.y + 1][map_size.x + 1] == '0')
		ft_putendl_fd("Playground is surrounded by walls!", 1);
	else
		return (ft_putendl_fd("Error!", 1), 0);
	free_map(map);
	return (1);
}
