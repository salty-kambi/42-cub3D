/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 10:35:30 by lsuau             #+#    #+#             */
/*   Updated: 2022/06/12 15:38:47 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	map_rgb(t_minimap *mp, char **map, int mx, int my)
{
	char	c;

	if (mx >= mp->map_x_max || mx < 0 || my >= mp->map_y_max || my < 0)
		return (0x000000);
	c = map[my][mx];
	if (c == '0')
		return (rgb_shift("4,90,154"));
	if (c == '1')
		return (rgb_shift("15,5,107"));
	return (0);
}

void	print_minimap(t_minimap *mp, char **map)
{
	int	x;
	int	y;
	int	mx;
	int	my;

	y = 0;
	while (y < mp->l)
	{
		x = 0;
		my = floor(((float)y * 0.1) + mp->ogy);
		while (x < mp->l)
		{
			mx = floor(((float)x * 0.1) + mp->ogx);
			pixel_put(mp->img, x, y, map_rgb(mp, map, mx, my));
			x++;
		}
		y++;
	}
}

void	mp_init_2(t_data *data, t_minimap *mp)
{
	mp->ogx = data->p.px - (mp->sqr * 0.5);
	mp->ogy = data->p.py - (mp->sqr * 0.5);
	mp->x_max = mp->ogx + (mp->sqr);
	mp->y_max = mp->ogy + (mp->sqr);
}

void	minimap(t_data *data)
{
	mp_init_2(data, &data->mp);
	print_minimap(&data->mp, data->map);
	minimap_player(&data->mp, &data->p);
	mlx_put_image_to_window(data->mlx, data->win, data->txt.left_border.img,
		data->display[0] - data->mp.l - 1, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->txt.down_border.img,
		data->display[0] - data->mp.l - 1, data->mp.l);
	mlx_put_image_to_window(data->mlx, data->win, data->txt.mini.img,
		data->display[0] - data->mp.l, 0);
}
