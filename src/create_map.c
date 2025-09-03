/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 03:54:45 by kkeskin           #+#    #+#             */
/*   Updated: 2025/09/01 03:54:46 by kkeskin          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_row(char *row)
{
	if (ft_strchr(row, '\n'))
		return (ft_strlen(row) - 2);
	return (ft_strlen(row));
}

static void	validate_component_count(char *map_name)
{
	char	*read;
	int		exit_c;
	int		start_c;
	int		collect_c;
	int		fd;

	fd = open(map_name, O_RDONLY);
	read = get_next_line(fd);
	exit_c = 0;
	start_c = 0;
	collect_c = 0;
	while (read)
	{
		exit_c += ft_count_chr(read, 'E');
		start_c += ft_count_chr(read, 'P');
		collect_c += ft_count_chr(read, 'C');
		free(read);
		read = get_next_line(fd);
	}
	if (exit_c != 1 || start_c != 1 || collect_c < 1)
		error_exit_map_creation(read, fd);
	close(fd);
}

static t_vector2	get_map_size(char *map_name)
{
	t_vector2	map_size;
	char		*read;
	int			fd;

	fd = open(map_name, O_RDONLY);
	read = get_next_line(fd);
	if (!read)
		error_exit_map_creation(read, fd);
	map_size.x = count_row(read);
	map_size.y = 1;
	free(read);
	read = get_next_line(fd);
	while (read)
	{
		map_size.y++;
		if (map_size.x != count_row(read))
			error_exit_map_creation(read, fd);
		free(read);
		read = get_next_line(fd);
	}
	close(fd);
	return (map_size);
}

static char	**set_map(t_vector2 map_size, char *map_name)
{
	char	**map;
	char	*read;
	int		fd;
	int		i;

	map = malloc(sizeof(char **) * (map_size.y + 1));
	if (!map)
		error_exit_map_creation(read, fd);
	fd = open(map_name, O_RDONLY);
	i = 0;
	while (i < map_size.y)
	{
		read = get_next_line(fd);
		map[i] = ft_strdup(read);
		free(read);
		i++;
	}
	map[map_size.y] = NULL;
	close(fd);
	return (map);
}

t_game_data	*create_map(char *map_name)
{
	t_vector2	map_size;
	t_game_data	*data;
	char		**map;

	map_size = get_map_size(map_name);
	validate_component_count(map_name);
	map = set_map(map_size, map_name);
	data = build_validation_map(map, map_size, map_name);
	//data->map_name = ft_strlcat(data->map_name, ft_strrchr(map_name, '/'), ft_strlen(map_name) - (ft_strrchr(map_name, '/') - map_name));
	data->map = map;
	return (data);
}
