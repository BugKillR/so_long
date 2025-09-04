#include "so_long.h"

static void	put_background(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, data->sprites.bg, x, y);
}

static void	put_door(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, data->sprites.e1, x, y);
	data->game_data->map[data->game_data->door_location.y]
	[data->game_data->door_location.x] = 'E';
}

int	find_if_component_available(char **map, char component)
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
				return (1);
			k++;
		}
		i++;
	}
	return (0);
}

static void	render_while_loop(t_data *data, int x, int y)
{
	if (data->game_data->map[y][x] == '0')
		put_background(data, x * 64, y * 64);
	if (data->game_data->map[y][x] == '1')
		put_wall(data, x * 64, y * 64);
	if (data->game_data->map[y][x] == 'C')
		put_collectible(data, x * 64, y * 64);
	if (data->game_data->map[y][x] == 'P')
		put_player(data, x * 64, y * 64);
}

int	render(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	data->p_v2 = find_component_location(data->game_data->map, 'P');
	if (data->p_v2.x == -1)
		data->p_v2 = find_component_location(data->game_data->map, 'G');
	else
		put_door(data,
			data->game_data->door_location.x * 64, data->game_data->door_location.y * 64);
	if (!find_if_component_available(data->game_data->map, 'G'))
		data->game_data->map[data->game_data->door_location.y]
		[data->game_data->door_location.x] = 'E';
	while (y < data->game_data->map_size.y)
	{
		x = 0;
		while (x < data->game_data->map_size.x)
		{
			render_while_loop(data, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
