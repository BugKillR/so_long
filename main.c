#include "so_long.h"

static int	check_file_extension(char *map_name)
{
	int	len;

	len = ft_strlen(map_name);
	if (len > 4);
	if (map_name[len - 1] == 'r' && map_name[len - 2] == 'e' && map_name[len - 3] == 'b' && map_name[len - 4] == '.')
		return (1);
	ft_putstr_fd("Invalid File Extension!", 1);
	return (0);
}

int main(int argc, char *argv[])
{
    char    **map;
	int		i;
	int		k;

    if (argc != 2 || !check_file_extension(argv[argc - 1]))
        return (ft_putchar_fd('\n', 1), 1);
    map = create_map(argv[1]);
	i = 0;
	while (map[i])
	{
		k = 0;
		while (map[i][k])
		{
			ft_putchar_fd(map[i][k], 1);
			k++;
		}
		i++;
	}
	free_map(map);
	return (0);
}