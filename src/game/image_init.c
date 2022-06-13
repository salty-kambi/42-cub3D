/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:34:20 by lsuau             #+#    #+#             */
/*   Updated: 2022/06/12 17:24:26 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	sprite_preload(void *mlx, t_image *spr, char *path)
{
	spr->img = mlx_xpm_file_to_image(mlx, path, spr->wi_he, spr->wi_he + 1);
	if (!spr->img)
		return ;
	spr->addr = mlx_get_data_addr(
			spr->img, &spr->bpp, &spr->line_len, &spr->endian);
}

void	minimap_preload(void *mlx, t_image *spr, int display[2])
{
	int	l;

	l = display[0];
	if (l > display[1])
		l = display[1];
	l = (l * 25) / 100;
	spr->img = mlx_new_image(mlx, l, l);
	spr->addr = mlx_get_data_addr(
			spr->img, &spr->bpp, &spr->line_len, &spr->endian);
}

void	border_preload(void *mlx, t_image *left, t_image *down, int l)
{
	int	x;
	int	y;

	l = l + 2;
	left->img = mlx_new_image(mlx, 1, l);
	left->addr = mlx_get_data_addr(
			left->img, &left->bpp, &left->line_len, &left->endian);
	down->img = mlx_new_image(mlx, l, 1);
	down->addr = mlx_get_data_addr(
			down->img, &down->bpp, &down->line_len, &down->endian);
	y = 0;
	while (y < l - 1)
	{
		pixel_put(left, 0, y, 0xffffff);
		y++;
	}
	x = 0;
	while (x < l)
	{
		pixel_put(down, x, 0, 0xffffff);
		x++;
	}
}

void	img_init(t_data *data)
{
	data->txt.wall.img = mlx_new_image(data->mlx, data->display[0], \
		data->display[1]);
	data->txt.wall.addr = mlx_get_data_addr(data->txt.wall.img, \
		&data->txt.wall.bpp, &data->txt.wall.line_len, \
		&data->txt.wall.endian);
	sprite_preload(data->mlx, &data->txt.north, data->fdata.north);
	sprite_preload(data->mlx, &data->txt.south, data->fdata.south);
	sprite_preload(data->mlx, &data->txt.west, data->fdata.west);
	sprite_preload(data->mlx, &data->txt.east, data->fdata.east);
	minimap_preload(data->mlx, &data->txt.mini, data->display);
	border_preload(data->mlx, &data->txt.left_border,
		&data->txt.down_border, data->mp.l);
}
