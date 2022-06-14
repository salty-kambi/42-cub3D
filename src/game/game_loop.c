/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:10:34 by lsuau             #+#    #+#             */
/*   Updated: 2022/06/14 13:55:48 by mapontil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	key_hook(int key, t_data *data)
{
	t_movement	*m;

	m = &data->m;
	if (key == ESC_KEY)
		data_clear(data);
	if (key == W_KEY)
		m->forward = 1;
	if (key == S_KEY)
		m->backward = 1;
	if (key == A_KEY)
		m->left = 1;
	if (key == D_KEY)
		m->right = 1;
	return (0);
}

int	key_uhook(int key, t_data *data)
{
	t_movement	*m;

	m = &data->m;
	if (key == W_KEY)
		m->forward = 0;
	if (key == S_KEY)
		m->backward = 0;
	if (key == A_KEY)
		m->left = 0;
	if (key == D_KEY)
		m->right = 0;
	return (0);
}

int	mouse_hook(int x, int y, t_data *data)
{
	float	speed;

	(void) y;
	speed = (x - (data->display[0] / 2)) * 0.03 * SPEED;
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
	mlx_hook(data->win, 3, 1L << 0, key_uhook, data);
	mlx_hook(data->win, 6, 1L << 6, mouse_hook, data);
	movement(&data->m, &data->p, data->map);
	mlx_hook(data->win, 17, 1L << 19, data_clear, data);
	return (0);
}
