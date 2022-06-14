/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 09:53:32 by mapontil          #+#    #+#             */
/*   Updated: 2022/06/14 13:54:35 by mapontil         ###   ########.fr       */
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

void	movement_init(t_data *data)
{
	t_movement	*m;

	m = &data->m;
	m->forward = 0;
	m->backward = 0;
	m->left = 0;
	m->right = 0;
}

void	movement(t_movement *m, t_player *p, char **map)
{
	if (m->right)
		rotate_movement(p, SPEED);
	if (m->left)
		rotate_movement(p, -SPEED);
	if (m->forward)
		up_down_movement(p, map, 13);
	if (m->backward)
		up_down_movement(p, map, 1);
}
