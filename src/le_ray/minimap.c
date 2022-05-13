/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 10:35:30 by lsuau             #+#    #+#             */
/*   Updated: 2022/05/13 17:54:29 by lsuau            ###   ########.fr       */
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

void	mp_init(t_minimap *mp, t_image *mini, t_player play, int l)
{
	mp->mini = mini;
	mp->ps = 8;
	mp->l = l / 2;
	mp->range = (l / 2) / mp->ps;
	mp->pos_p[0] = play.pos[0];
	mp->pos_p[1] = play.pos[1];
}

void	put_square(t_minimap *mp, int x, int y, int rgb)
{
	int	x2;
	int	y2;

	y2 = 0;
	while (y2 < mp->ps)
	{
		x2 = 0;
		while (x2 < mp->ps)
		{
			pixel_put(mp->mini, x + x2, y + y2, rgb);
			x2++;
		}
		y2++;
	}
}

void	put_pix_img_map(t_minimap *mp, char c)
{
	int	rgb;

	rgb = 0x000000;
	if (c == '0')
		rgb = rgb_shift("77,170,209");
	else if (c == '1')
		rgb = rgb_shift("5,50,163");
	put_square(mp, (mp->x - mp->pos_p[1]) * 8 + mp->l,
		(mp->y - mp->pos_p[0]) * 8 + mp->l, rgb);
}

void	minimap(t_data *data)
{
	int	l;
	int	x;
	int	y;

	l = data->display[0];
	if (l > data->display[1])
		l = data->display[1];
	if (l % 2)
		l++;
	while (l % 64)
		l += 2;
	l = (l * 25) / 100;
	map_backround(&data->txt.mini, l);
	print_minimap(&data->txt.mini, l, data->map, data->play);
	mlx_put_image_to_window(data->mlx, data->win,
		data->txt.border.img, data->display[0] - l - 1, 0);
	mlx_put_image_to_window(data->mlx, data->win,
		data->txt.mini.img, data->display[0] - l, 0);
}
