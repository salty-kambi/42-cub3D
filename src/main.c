/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:16:41 by lsuau             #+#    #+#             */
/*   Updated: 2022/05/07 19:25:36 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	key_hook(int key, t_data *data)
{
	if (key == 53)
		data_clear(data);
	return (0);
}

int	game_loop(t_data *data)
{
	mlx_key_hook(data->win, key_hook, data);
	mlx_hook(data->win, 17, 1L << 19, data_clear, data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (write_error("only 2 argument allowed", 1));
	data_init(&data);
	if (map_parsing(&data, argv[1]))
		return (data_clear(&data));
	mlx_loop_hook(data.mlx, game_loop, &data);
	mlx_loop(data.mlx);
	data_clear(&data);
	return (0);
}
