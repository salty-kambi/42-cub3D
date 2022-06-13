/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 14:52:31 by lsuau             #+#    #+#             */
/*   Updated: 2022/06/12 15:44:36 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	ray_dir(t_player *p, t_raycast *ray, int x, float in_nb_ray)
{
	float	camerax;

	camerax = (2 * (float)x * in_nb_ray) - 1;
	ray->raydirx = p->pdx + (p->planex * camerax);
	ray->raydiry = p->pdy + (p->planey * camerax);
	if (ray->raydirx == 0)
		ray->deltadistx = INFINITY;
	else
		ray->deltadistx = fabsolf(1 / ray->raydirx);
	if (ray->raydiry == 0)
		ray->deltadisty = INFINITY;
	else
		ray->deltadisty = fabsolf(1 / ray->raydiry);
}

void	ray_step_side(t_player *p, t_raycast *ray)
{
	if (ray->raydirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (p->px - ray->mapx) * ray->deltadistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->mapx + 1 - p->px) * ray->deltadistx;
	}
	if (ray->raydiry < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (p->py - ray->mapy) * ray->deltadisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = (ray->mapy + 1 - p->py) * ray->deltadisty;
	}
}

//side-> 0=east 1=west 2=south 3=north
void	ray_hit(char **map, t_raycast *ray)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->sidedistx < ray->sidedisty)
		{
			ray->sidedistx += ray->deltadistx;
			ray->mapx += ray->stepx;
			if (ray->sidedistx >= 0 && ray->stepx == 1)
				ray->side = 0;
			else
				ray->side = 1;
		}
		else
		{
			ray->sidedisty += ray->deltadisty;
			ray->mapy += ray->stepy;
			if (ray->sidedisty >= 0 && ray->stepy == 1)
				ray->side = 2;
			else
				ray->side = 3;
		}
		if (map[ray->mapy][ray->mapx] == '1')
			ray->hit = 1;
	}
}

void	raycasting(t_data *data)
{
	int			x;
	int			nb_ray;
	float		in_nb_ray;
	t_raycast	ray;

	x = -1;
	nb_ray = SCREEN_WIDTH - 1;
	in_nb_ray = (float)1 / nb_ray;
	while (++x <= nb_ray)
	{
		ray.mapx = floor(data->p.px);
		ray.mapy = floor(data->p.py);
		ray_dir(&data->p, &ray, x, in_nb_ray);
		ray_step_side(&data->p, &ray);
		ray_hit(data->map, &ray);
		if (ray.side == 0 || ray.side == 1)
			ray.walldist = (ray.sidedistx - ray.deltadistx);
		else
			ray.walldist = (ray.sidedisty - ray.deltadisty);
		build_wall(&ray, data, x);
	}
}
