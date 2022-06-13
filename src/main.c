/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:16:41 by lsuau             #+#    #+#             */
/*   Updated: 2022/06/13 11:52:53 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	player_init(t_player *p)
{
	if (p->c == 'N')
	{
		p->pdx = 0;
		p->pdy = -1;
	}
	if (p->c == 'S')
	{
		p->pdx = 0;
		p->pdy = 1;
	}
	if (p->c == 'W')
	{
		p->pdx = -1;
		p->pdy = 0;
	}
	if (p->c == 'E')
	{
		p->pdx = 1;
		p->pdy = 0;
	}
	p->planex = -p->pdy * 0.66;
	p->planey = p->pdx * 0.66;
}

int	check_xpm(t_texture *txt)
{
	if (!txt->north.img)
		return (1);
	if (!txt->south.img)
		return (1);
	if (!txt->east.img)
		return (1);
	if (!txt->west.img)
		return (1);
	return (0);
}

void	game_init(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(
			data->mlx, data->display[0], data->display[1], "cub3D");
	mp_init_1(data);
	img_init(data);
	fdata_clear(&data->fdata);
	if (check_xpm(&data->txt))
	{
		write_error("texture must be xpm", 1);
		data_clear(data);
	}
	player_init(&data->p);
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
	mlx_mouse_hide(data.win);
	mlx_mouse_move(data.win, data.display[0] / 2, data.display[1] / 2);
	mlx_loop_hook(data.mlx, game_loop, &data);
	mlx_loop(data.mlx);
	return (0);
}
