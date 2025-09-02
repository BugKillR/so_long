/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:35:16 by kkeskin           #+#    #+#             */
/*   Updated: 2025/09/02 15:35:17 by kkeskin          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**duplicate_map(char **val_map, char **map, t_vector2 map_size)
{
	char	**new_map;
	int		i;

	new_map = malloc(sizeof(char **) * (map_size.y + 2 + 1));
	if (!new_map)
		error_exit_validation(map, val_map);
	i = 0;
	while (i < map_size.y + 2)
	{
		new_map[i] = ft_strdup(val_map[i]);
		if (!new_map[i])
		{
			free_map(new_map);
			error_exit_validation(map, val_map);
		}
		i++;
	}
	new_map[map_size.y + 2] = NULL;
	return (new_map);
}

static char	**malloc_map(char **map, t_vector2 map_size)
{
	char	**validation_map;

	validation_map = malloc(sizeof(char *) * (map_size.y + 2 + 1));
	if (!validation_map)
		error_exit_validation(map, validation_map);
	return (validation_map);
}

static char	*malloc_row(char **map, char **validation_map,
	t_vector2 map_size, int i)
{
	char	*row;

	row = malloc(sizeof(char) * (map_size.x + 2 + 1));
	if (!row)
		error_exit_validation(map, validation_map);
	return (row);
}

static char	**create_validation_map(char **map, t_vector2 map_size)
{
	char	**validation_map;
	int		i;
	int		j;

	validation_map = malloc_map(map, map_size);
	i = 0;
	while (i < map_size.y + 2)
	{
		j = 0;
		validation_map[i] = malloc_row(map, validation_map, map_size, i);
		while (j < map_size.x + 2)
		{
			validation_map[i][j] = '0';
			j++;
		}
		validation_map[i][map_size.x + 2] = '\0';
		if (i > 0 && i < map_size.y + 2 - 1)
		{
			ft_strlcpy(&validation_map[i][1], map[i - 1], map_size.x + 1);
			validation_map[i][map_size.x + 1] = '0';
		}
		i++;
	}
	validation_map[map_size.y + 2] = NULL;
	return (validation_map);
}

t_data	*build_validation_map(char **map, t_vector2 map_size, char *map_name)
{
	char	**validation_map;
	char	**dup_val_map;
	int		collectibles;
	t_data	*data;

	validation_map = create_validation_map(map, map_size);
	dup_val_map = duplicate_map(validation_map, map, map_size);
	if (!check_if_map_surrounded_by_walls(dup_val_map, map_size))
		error_exit_validation(map, validation_map);
	dup_val_map = duplicate_map(validation_map, map, map_size);
	collectibles = count_real_collectibles(dup_val_map, map_size, map_name);
	if (collectibles <= 0)
	{
		ft_putstr_fd("There is no reachable collectible!\n", 1);
		error_exit_validation(map, validation_map);
	}
	dup_val_map = duplicate_map(validation_map, map, map_size);
	if (!check_if_player_can_reach_door(dup_val_map, map_size))
		error_exit_validation(map, validation_map);
	data = malloc(sizeof(t_data));
	if (!data)
		error_exit_validation(map, validation_map);
	data->collectibles = collectibles;
	free_map(validation_map);
	return (data);
}
