/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 10:35:30 by lsuau             #+#    #+#             */
/*   Updated: 2022/05/13 12:55:01 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	map_backround(t_image *mini, int l)
{
	int	x;
	int	y;

	x = -1;
	while (++x < l)
	{
		y = -1;
		while (++y < l)
			pixel_put(mini, x, y, 0x000000);
	}
}

void	print_map(t_image *mini, int l, char **map, t_player play)
{
	int	ps;
	int mid;

	ps = 8;
	mid = l / 2;
	while ()
	{
		
	}
}

void	minimap(t_data *data)
{
	int	l;
	int	x;
	int	y;

	l = data->display[0];
	if (l > data->display[1])
		l = data->display[1];
	l = (l * 25) / 100;
	map_backround(&data->txt.mini, l);
	print_minimap(&data->txt.mini, l, data->map, data->play);
	mlx_put_image_to_window(data->mlx, data->win, data->txt.border.img, data->display[0] - l - 1, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->txt.mini.img, data->display[0] - l, 0);
}
