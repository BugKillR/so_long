#include "so_long.h"

int	keybinds(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == KEY_ESC || keycode == KEY_Q)
		free_data_and_exit(data, 0);
	else if (keycode == KEY_W || keycode == KEY_UP)
		ft_putstr_fd("Up\n", 1);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		ft_putstr_fd("Left\n", 1);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		ft_putstr_fd("Down\n", 1);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		ft_putstr_fd("Right\n", 1);
	return (0);
}