#include "so_long.h"

static void	put_background(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, data->sprites.bg, x, y);
}

static void put_door(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, data->sprites.d1, x, y);
}

static void put_wall(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, data->sprites.w1, x, y);
}

int render(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->game_data->map_size.y)
	{
		x = 0;
		while (x < data->game_data->map_size.x)
		{
			if (data->game_data->map[y][x] == '0')
				put_background(data, x * 64, y * 64);
			if (data->game_data->map[y][x] == 'E')
				put_door(data, x * 64, y * 64);
			if (data->game_data->map[y][x] == '1')
				put_wall(data, x * 64, y * 64);
			x++;
		}
		y++;
	}
	return (0);
}
