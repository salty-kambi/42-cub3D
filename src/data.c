/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 23:46:05 by lsuau             #+#    #+#             */
/*   Updated: 2022/06/13 11:52:00 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	mp_init_1(t_data *data)
{
	data->mp.l = data->display[0];
	if (data->mp.l > data->display[1])
		data->mp.l = data->display[1];
	data->mp.l = (data->mp.l * 25) / 100;
	data->mp.sqr = data->mp.l / 10;
	data->mp.img = &data->txt.mini;
	data->mp.map_x_max = stlen(data->map[0]);
	data->mp.map_y_max = tab_len(data->map);
}

void	data_init(t_data *data)
{
	data->display[0] = SCREEN_WIDTH;
	data->display[1] = SCREEN_HEIGHT;
}

void	img_clear(void	*mlx, t_texture *txt)
{
	mlx_destroy_image(mlx, txt->wall.img);
	if (txt->north.img)
		mlx_destroy_image(mlx, txt->north.img);
	if (txt->south.img)
		mlx_destroy_image(mlx, txt->south.img);
	if (txt->west.img)
		mlx_destroy_image(mlx, txt->west.img);
	if (txt->east.img)
		mlx_destroy_image(mlx, txt->east.img);
	mlx_destroy_image(mlx, txt->mini.img);
	mlx_destroy_image(mlx, txt->left_border.img);
	mlx_destroy_image(mlx, txt->down_border.img);
}

void	fdata_clear(t_file_data *fdata)
{
	if (fdata->file)
		free(fdata->file);
	if (fdata->north)
		free(fdata->north);
	if (fdata->east)
		free(fdata->east);
	if (fdata->south)
		free(fdata->south);
	if (fdata->west)
		free(fdata->west);
}

int	data_clear(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	free_tab(data->map);
	img_clear(data->mlx, &data->txt);
	exit(0);
	return (0);
}
