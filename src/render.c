#include "so_long.h"

static void	put_background(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, data->sprites.bg, x, y);
}

static char	*string_to_print(char *text, char *score)
{
	char	*full;

	full = ft_strjoin(text, score);
	return (full);
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
    if (x == data->game_data->door_location.x && y == data->game_data->door_location.y
        && data->game_data->map[y][x] == 'G')
    {
        put_door(data, x * 64, y * 64);
        put_player(data, x * 64, y * 64);
        return;
    }
    if (data->game_data->map[y][x] == '1')
        put_wall(data, x * 64, y * 64);
    else if (data->game_data->map[y][x] == 'C')
        put_collectible(data, x * 64, y * 64);
    else if (data->game_data->map[y][x] == 'P')
        put_player(data, x * 64, y * 64);
    else if (data->game_data->map[y][x] == 'E')
	put_door(data, x * 64, y * 64);
	else if (data->game_data->map[y][x] == 'D')
	put_enemy(data, x * 64, y * 64);
	else
	put_background(data, x * 64, y * 64);
}

int	render(t_data *data)
{
	int		x;
	int		y;
	
	data->p_v2 = find_component_location(data->game_data->map, 'P');
	if (data->p_v2.x == -1)
	data->p_v2 = find_component_location(data->game_data->map, 'G');
	if (find_if_component_available(data->game_data->map, 'G'))
	put_player(data, x * 64, y * 64);
	if (!find_if_component_available(data->game_data->map, 'G'))
	data->game_data->map[data->game_data->door_location.y]
	[data->game_data->door_location.x] = 'E';
	y = 0;
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
