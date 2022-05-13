/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:37:28 by lsuau             #+#    #+#             */
/*   Updated: 2022/05/13 17:59:42 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	print_nw_minimap(t_minimap *mp, char **map)
{
	mp->y = mp->pos_p[0];
	while (mp->y >= mp->pos_p[0] - mp->range && mp->y >= 0)
	{
		mp->x = mp->pos_p[1];
		while (mp->x >= mp->pos_p[1] - mp->range && mp->x >= 0)
		{
			put_pix_img_map(mp, map[mp->y][mp->x]);
			mp->x--;
		}
		mp->y--;
	}
}

void	print_ne_minimap(t_minimap *mp, char **map)
{
	mp->y = mp->pos_p[0];
	while (mp->y >= mp->pos_p[0] - mp->range && mp->y >= 0)
	{
		mp->x = mp->pos_p[1];
		while (mp->x < mp->pos_p[1] + mp->range && map[mp->y][mp->x])
		{
			put_pix_img_map(mp, map[mp->y][mp->x]);
			mp->x++;
		}
		mp->y--;
	}
}

void	print_sw_minimap(t_minimap *mp, char **map)
{
	mp->y = mp->pos_p[0];
	while (mp->y < mp->pos_p[0] + mp->range && map[mp->y])
	{
		mp->x = mp->pos_p[1];
		while (mp->x >= mp->pos_p[1] - mp->range && mp->x >= 0)
		{
			put_pix_img_map(mp, map[mp->y][mp->x]);
			mp->x--;
		}
		mp->y++;
	}
}

void	print_se_minimap(t_minimap *mp, char **map)
{
	mp->y = mp->pos_p[0];
	while (mp->y < mp->pos_p[0] + mp->range && map[mp->y])
	{
		mp->x = mp->pos_p[1];
		while (mp->x < mp->pos_p[1] + mp->range && map[mp->y][mp->x])
		{
			put_pix_img_map(mp, map[mp->y][mp->x]);
			mp->x++;
		}
		mp->y++;
	}
}

void	print_minimap(t_image *mini, int l, char **map, t_player play)
{
	t_minimap	mp;

	mp_init(&mp, mini, play, l);
	print_nw_minimap(&mp, map);
	print_ne_minimap(&mp, map);
	print_sw_minimap(&mp, map);
	print_se_minimap(&mp, map);
	put_square(&mp, mp.l, mp.l, rgb_shift("184,24,24"));
}
