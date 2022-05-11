/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 23:46:05 by lsuau             #+#    #+#             */
/*   Updated: 2022/05/07 19:25:50 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	data_init(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1920, 1080, "cub3D");
	data->file = 0;
	data->map = 0;
	data->txt.north = 0;
	data->txt.south = 0;
	data->txt.east = 0;
	data->txt.west = 0;
}

int	data_clear(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	if (data->file)
		free(data->file);
	if (data->map)
		free_tab(data->map);
	if (data->txt.north)
		free(data->txt.north);
	if (data->txt.east)
		free(data->txt.east);
	if (data->txt.south)
		free(data->txt.south);
	if (data->txt.west)
		free(data->txt.west);
	exit(0);
	return (1);
}
