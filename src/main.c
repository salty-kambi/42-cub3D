/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:16:41 by lsuau             #+#    #+#             */
/*   Updated: 2022/05/13 18:04:19 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

//w = 13 //a = 0 // s = 1 // d = 2 //esc = 53
int	key_hook(int key, t_data *data)
{
	if (key == 53)
		data_clear(data);
	if (key == 13)
		data->play.pos[0] -= 1;
	if (key == 0)
		data->play.pos[1] -= 1;
	if (key == 1)
		data->play.pos[0] += 1;
	if (key == 2)
		data->play.pos[1] += 1;
	return (0);
}

int	game_loop(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->txt.celling.img, 0, 0);
	mlx_put_image_to_window(
		data->mlx, data->win, data->txt.floor.img, 0, data->display[1] / 2);
	minimap(data);
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
	{
		fdata_clear(&data.fdata);
		return (1);
	}
	game_init(&data);
	mlx_loop_hook(data.mlx, game_loop, &data);
	mlx_loop(data.mlx);
	return (0);
}
