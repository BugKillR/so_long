#include "so_long.h"

int	keybinds(int keycode, void *param)
{
	t_data		*data;

	data = (t_data *)param;
	if (keycode == KEY_ESC || keycode == KEY_Q)
		free_data_and_exit(data, 0);
	else if (keycode == KEY_W || keycode == KEY_UP)
		move("Up", data->game_data->map, data);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move("Left", data->game_data->map, data);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move("Down", data->game_data->map, data);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move("Right", data->game_data->map, data);
	return (0);
}