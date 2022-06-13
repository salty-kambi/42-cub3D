/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:10:34 by lsuau             #+#    #+#             */
/*   Updated: 2022/06/12 17:12:39 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	up_down_movement(t_player *p, char **map, int key)
{
	if (key == W_KEY)
	{
		if (map[(int)floor(p->py)]
			[(int)floor(p->px + (p->pdx * SPEED * 2))] == '0')
			p->px += p->pdx * SPEED;
		if (map[(int)floor(p->py + p->pdy * SPEED * 2)]
			[(int)floor(p->px)] == '0')
			p->py += p->pdy * SPEED;
	}
	if (key == S_KEY)
	{
		if (map[(int)floor(p->py)]
			[(int)floor(p->px - (p->pdx * SPEED * 2))] == '0')
			p->px -= p->pdx * SPEED;
		if (map[(int)floor(p->py - p->pdy * SPEED * 2)]
			[(int)floor(p->px)] == '0')
			p->py -= p->pdy * SPEED;
	}
}

void	rotate_movement(t_player *p, float speed)
{
	float	olddir;
	float	oldplane;

	olddir = p->pdx;
	p->pdx = p->pdx * cos(speed) - p->pdy * sin(speed);
	p->pdy = olddir * sin(speed) + p->pdy * cos(speed);
	oldplane = p->planex;
	p->planex = p->planex * cos(speed) - p->planey * sin(speed);
	p->planey = oldplane * sin(speed) + p->planey * cos(speed);
}

int	key_hook(int key, t_data *data)
{
	t_player	*p;

	p = &data->p;
	if (key == ESC_KEY)
		data_clear(data);
	up_down_movement(&data->p, data->map, key);
	if (key == A_KEY)
		rotate_movement(p, -SPEED);
	if (key == D_KEY)
		rotate_movement(p, SPEED);
	return (0);
}

int	mouse_hook(int x, int y, t_data *data)
{
	float	speed;

	(void) y;
	speed = (x - (data->display[0] / 2)) * 0.03 * SPEED;
	if (x > (data->display[0] / 2))
		rotate_movement(&data->p, speed);
	if (x < (data->display[0] / 2))
		rotate_movement(&data->p, speed);
	mlx_mouse_move(data->win, data->display[0] / 2, data->display[1] / 2);
	return (0);
}

int	game_loop(t_data *data)
{
	raycasting(data);
	mlx_put_image_to_window(data->mlx, data->win, data->txt.wall.img, 0, 0);
	minimap(data);
	mlx_hook(data->win, 2, 1L << 0, key_hook, data);
	mlx_hook(data->win, 6, 1L << 6, mouse_hook, data);
	mlx_hook(data->win, 17, 1L << 19, data_clear, data);
	return (0);
}
