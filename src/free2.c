#include "so_long.h"

void free_sprites(t_data *data)
{
    if (data->sprites.bg)
        mlx_destroy_image(data->mlx, data->sprites.bg);
    if (data->sprites.p1)
        mlx_destroy_image(data->mlx, data->sprites.p1);
    if (data->sprites.e1)
        mlx_destroy_image(data->mlx, data->sprites.e1);
    if (data->sprites.d1)
        mlx_destroy_image(data->mlx, data->sprites.d1);
    if (data->sprites.c1)
        mlx_destroy_image(data->mlx, data->sprites.c1);
    if (data->sprites.w1)
        mlx_destroy_image(data->mlx, data->sprites.w1);
}