/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 16:15:28 by lsuau             #+#    #+#             */
/*   Updated: 2022/06/12 15:59:44 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	rgb_wall(t_data *data, t_raycast *ray, float wally)
{
	float	wallx;
	int		rgb;

	if (ray->side == 0 || ray->side == 1)
	{
		wallx = data->p.py + ray->walldist * ray->raydiry;
		rgb = get_pix_txt(data, ray->side, wallx, wally);
	}
	else
	{
		wallx = data->p.px + ray->walldist * ray->raydirx;
		rgb = get_pix_txt(data, ray->side, wallx, wally);
	}
	return (rgb);
}

void	build_wall(t_raycast *ray, t_data *data, int x)
{
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		i;
	float	ratio;

	lineheight = SCREEN_HEIGHT / ray->walldist;
	drawstart = (-lineheight + SCREEN_HEIGHT) * 0.5;
	drawend = (lineheight + SCREEN_HEIGHT) * 0.5;
	ratio = (float)1 / (drawend - drawstart);
	i = -1;
	while (++i < drawstart || i < 0)
		pixel_put(&data->txt.wall, x, i, data->fdata.celling);
	while (i < drawend && i < SCREEN_HEIGHT - 1)
	{
		pixel_put(&data->txt.wall, x, i, rgb_wall(data, ray,
				(float)(i - drawstart) *ratio));
		i++;
	}
	while (i < data->display[1])
	{
		pixel_put(&data->txt.wall, x, i, data->fdata.floor);
		i++;
	}
}
