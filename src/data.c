/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 23:46:05 by lsuau             #+#    #+#             */
/*   Updated: 2022/05/13 10:28:27 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	data_init(t_data *data)
{
	data->display[0] = 1280;
	data->display[1] = 720;
	data->map = 0;
	data->fdata.file = 0;
	data->fdata.north = 0;
	data->fdata.south = 0;
	data->fdata.east = 0;
	data->fdata.west = 0;
}

void	img_clear(void	*mlx, t_texture *txt)
{
	mlx_destroy_image(mlx, txt->north.img);
	mlx_destroy_image(mlx, txt->south.img);
	mlx_destroy_image(mlx, txt->west.img);
	mlx_destroy_image(mlx, txt->east.img);
	mlx_destroy_image(mlx, txt->floor.img);
	mlx_destroy_image(mlx, txt->celling.img);
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
