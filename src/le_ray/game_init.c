/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:34:20 by lsuau             #+#    #+#             */
/*   Updated: 2022/05/13 17:50:21 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	sprite_preload(void *mlx, t_image *spr, char *path)
{
	spr->img = mlx_xpm_file_to_image(mlx, path, spr->wi_he, spr->wi_he + 1);
	spr->addr = mlx_get_data_addr(
			spr->img, &spr->bpp, &spr->line_len, &spr->endian);
}

void	minimap_preload(void *mlx, t_image *spr, int display[2])
{
	int	l;

	l = display[0];
	if (l > display[1])
		l = display[1];
	if (l % 2)
		l++;
	while (l % 64)
		l += 2;
	l = (l * 25) / 100;
	spr->img = mlx_new_image(mlx, l, l);
	spr->addr = mlx_get_data_addr(
			spr->img, &spr->bpp, &spr->line_len, &spr->endian);
}

void	border_preload(void *mlx, t_image *spr, int display[2])
{
	int	x;
	int	y;
	int	l;

	l = display[0];
	if (l > display[1])
		l = display[1];
	if (l % 2)
		l++;
	while (l % 64)
		l += 2;
	l = (l * 25) / 100 + 2;
	spr->img = mlx_new_image(mlx, l, l);
	spr->addr = mlx_get_data_addr(
			spr->img, &spr->bpp, &spr->line_len, &spr->endian);
	x = -1;
	while (++x < l)
	{
		y = -1;
		while (++y < l - 1)
			pixel_put(spr, x, y, 0xffffff);
	}
}

void	img_init(t_data *data)
{
	sprite_preload(data->mlx, &data->txt.north, data->fdata.north);
	sprite_preload(data->mlx, &data->txt.south, data->fdata.south);
	sprite_preload(data->mlx, &data->txt.west, data->fdata.west);
	sprite_preload(data->mlx, &data->txt.east, data->fdata.east);
	minimap_preload(data->mlx, &data->txt.mini, data->display);
	border_preload(data->mlx, &data->txt.border, data->display);
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
