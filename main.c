/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:29:27 by kkeskin           #+#    #+#             */
/*   Updated: 2025/09/02 15:29:28 by kkeskin          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "./src/so_long.h"

static int	check_file_extension(char *map_name)
{
	int	len;

	len = ft_strlen(map_name);
	if (map_name[len - 1] == 'r' && map_name[len - 2] == 'e'
		&& map_name[len - 3] == 'b' && map_name[len - 4] == '.')
		return (1);
	ft_putstr_fd("Invalid File Extension!\nError!", 1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game_data	*data;

	if (argc != 2)
		return (ft_putstr_fd("Error\n", 1), 1);
	if (!check_file_extension(argv[argc - 1]))
		return (ft_putchar_fd('\n', 1), 1);
	data = create_map(argv[1]);
	mlx_setup(data);
	free_game_data_exit(data);
	return (0);
}
