/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:22:54 by lsuau             #+#    #+#             */
/*   Updated: 2022/06/12 17:10:53 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	pixel_put(t_image *spr, int x, int y, int rgb)
{
	char	*pixel;

	pixel = spr->addr
		+ (y * spr->line_len + x * (int)((float)spr->bpp * 0.125));
	*(int *)pixel = rgb;
}

int	get_pix_txt(t_data *data, int side, float x, float y)
{
	t_image	*img;
	char	*pixel;
	int		rgb;

	img = 0;
	if (side == 0)
		img = &data->txt.east;
	else if (side == 1)
		img = &data->txt.west;
	else if (side == 2)
		img = &data->txt.south;
	else if (side == 3)
		img = &data->txt.north;
	x = x - floor(x);
	y = floor(y * img->wi_he[1]) * img->line_len;
	x = floor(x * img->wi_he[0]) * (img->bpp / 8);
	pixel = img->addr + ((int)y + (int)x);
	rgb = *(int *)pixel;
	return (rgb);
}
