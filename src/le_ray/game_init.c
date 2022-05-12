/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:34:20 by lsuau             #+#    #+#             */
/*   Updated: 2022/05/12 18:13:56 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	sprite_preload(void *mlx, t_image *spr, char *path)
{
	spr->img = mlx_xpm_file_to_image(mlx, path, spr->wi_he, spr->wi_he + 1);
	spr->addr = mlx_get_data_addr(
			spr->img, &spr->bpp, &spr->line_len, &spr->endian);
}

void	img_init(t_data *data)
{
	sprite_preload(data->mlx, &data->txt.north, data->fdata.north);
	sprite_preload(data->mlx, &data->txt.south, data->fdata.south);
	sprite_preload(data->mlx, &data->txt.west, data->fdata.west);
	sprite_preload(data->mlx, &data->txt.east, data->fdata.east);
	rgb_to_rect_img(data->mlx, &data->txt.floor,
		data->fdata.floor, data->display);
	rgb_to_rect_img(data->mlx, &data->txt.celling,
		data->fdata.celling, data->display);
}

void	game_init(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(
			data->mlx, data->display[0], data->display[1], "cub3D");
	img_init(data);
	fdata_clear(&data->fdata);
}
