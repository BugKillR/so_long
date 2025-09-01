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

static void	error_exit(char	*read, int fd)
{
	if (read)
		free(read);
	close(fd);
	ft_putstr_fd("Invalid Map Or Invalid Map Name!\n", 1);
	exit (1);
}

static int	count_row(char *row)
{
	if (ft_strchr(row, '\n'))
		return (ft_strlen(row) - 2);
	return (ft_strlen(row));
}

static void	validate_components(char *map_name)
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
		error_exit(read, fd);
	close(fd);
}

static t_vector2	validate_map(char *map_name)
{
	t_vector2	map_size;
	char		*read;
	int			fd;

	fd = open(map_name, O_RDONLY);
	read = get_next_line(fd);
	if (!read)
		error_exit(read, fd);
	map_size.x = count_row(read);
	map_size.y = 1;
	free(read);
	read = get_next_line(fd);
	while (read)
	{
		map_size.y++;
		if (map_size.x != count_row(read))
			error_exit(read, fd);
		free(read);
		read = get_next_line(fd);
	}
	close(fd);
	return (map_size);
}

char	**create_map(char *map_name)
{
	t_vector2	map_size;
	char		**map;
	char		*read;
	int			fd;
	int			i;

	map_size = validate_map(map_name);
	validate_components(map_name);
	map = malloc(sizeof(char **) * (map_size.y + 1));
	if (!map)
		error_exit(read, fd);
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
