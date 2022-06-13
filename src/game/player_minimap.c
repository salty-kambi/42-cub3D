/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:33:30 by mapontil          #+#    #+#             */
/*   Updated: 2022/06/12 15:39:03 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	minimap_player(t_minimap *mp, t_player *p)
{
	int		x;
	int		y;
	int		mid;

	mid = mp->l * 0.5;
	y = -1;
	while (y <= 1)
	{
		x = -1;
		while (x <= 1)
		{
			pixel_put(mp->img, mid + x, mid + y,
				rgb_shift("184,24,24"));
			x++;
		}
		y++;
	}
	pixel_put(mp->img, mid + p->pdx * 2, mid + p->pdy * 2, \
		rgb_shift("255,255,60"));
}
