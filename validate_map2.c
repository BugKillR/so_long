#include "so_long.h"
#include <stdio.h>

static t_vector2	find_player_location(char **map)
{
	int	i;
	int	k;

	i = 0;
	while (map[i])
	{
		k = 0;
		while (map[i][k])
		{
			if (map[i][k] == 'P')
				return ((t_vector2){.x = k, .y = i});
			k++;
		}
		i++;
	}
	return ((t_vector2){.x = k, .y = i});
}

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

int	check_if_map_surrounded_by_walls(char **map, t_vector2 map_size)
{
	t_flood_fill_data	flood_data;
	t_vector2			beginning;
	t_vector2			size;

	beginning = find_player_location(map);
	convert_extra_components_to_space(map);
	size = (t_vector2){.x = map_size.x + 2, .y = map_size.y + 2};
	flood_data.curr = beginning;
	flood_data.size = size;
	flood_data.ignored = 'P';
	ft_flood_fill(map, flood_data, '0', 'F');
	if(map[0][0] == '0' && map[0][map_size.x + 1] == '0' && map[map_size.y + 1][0] == '0' && map[map_size.y + 1][map_size.x + 1] == '0')
		ft_putendl_fd("Playground is surrounded by walls!", 1);
	else
		return (ft_putendl_fd("Invalid Map!", 1), 0);
	free_map(map);
	return (1);
}
