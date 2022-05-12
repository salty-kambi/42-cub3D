/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:34:20 by lsuau             #+#    #+#             */
/*   Updated: 2022/05/12 17:00:47 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	img_init(t_data *data)
{
	t_texture	*txt;
	t_file_data	*fdata;

	txt = &(data->txt);
	fdata = &(data->fdata);
	txt->north.img = mlx_xpm_file_to_image(
			data->mlx, fdata->north, txt->north.wi_he, txt->south.wi_he + 1);
	txt->south.img = mlx_xpm_file_to_image(
			data->mlx, fdata->south, txt->south.wi_he, txt->south.wi_he + 1);
	txt->west.img = mlx_xpm_file_to_image(
			data->mlx, fdata->west, txt->west.wi_he, txt->west.wi_he + 1);
	txt->east.img = mlx_xpm_file_to_image(
			data->mlx, fdata->east, txt->east.wi_he, txt->east.wi_he + 1);
	// txt->floor.img = rgb_to_rect_img(
	// 		data->mlx, fdata->floor, data->display[0], data->display[1]);
	// txt->celling.img = rgb_to_rect_img(
	// 		data->mlx, fdata->celling, data->display[0], data->display[1]);
}

void	game_init(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(
			data->mlx, data->display[0], data->display[1], "cub3D");
	img_init(data);
	fdata_clear(&data->fdata);
}
