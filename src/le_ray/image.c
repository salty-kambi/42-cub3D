/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:22:54 by lsuau             #+#    #+#             */
/*   Updated: 2022/05/13 17:50:38 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	pixel_put(t_image *spr, int x, int y, int rgb)
{
	char	*pixel;

	pixel = spr->addr + (y * spr->line_len + x * (spr->bpp / 8));
	*(int *)pixel = rgb;
}

void	rgb_to_rect_img(void *mlx, t_image *spr, int rgb, int display[2])
{
	int	x;
	int	y;

	spr->img = mlx_new_image(mlx, display[0], display[1] / 2);
	spr->addr = mlx_get_data_addr(
			spr->img, &spr->bpp, &spr->line_len, &spr->endian);
	x = 0;
	while (x < display[0])
	{
		y = 0;
		while (y < (display[1] / 2))
		{
			pixel_put(spr, x, y, rgb);
			y++;
		}
		x++;
	}
}
