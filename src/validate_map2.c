#include "so_long.h"

void    validate_components(char **map, t_vector2 map_size)
{
    char    c;
    int     x;
    int     y;

    y = 0;
    while (y < map_size.y)
    {
        x = 0;
        while (x < map_size.x)
        {
            c = map[y][x];
            if (!(c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'D' || c == 'P'))
            {
                free_map(map);
                ft_putstr_fd("Invalid Component In Map!\n", 1);
                exit (1);
            }
            x++;
        }
        y++;
    }
}