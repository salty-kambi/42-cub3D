/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_closed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:16:37 by lsuau             #+#    #+#             */
/*   Updated: 2022/05/13 12:16:43 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	map_grab_player(t_player *play, char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S'
				|| map[y][x] == 'W' || map[y][x] == 'E')
			{
				map[y][x] = '0';
				play->pos[0] = y;
				play->pos[1] = x;
			}
			x++;
		}
		y++;
	}
}

int	check_map_border(char **map)
{
	int	y;
	int	x;

	y = tab_len(map) - 1;
	x = 0;
	while (map[0][x])
	{
		if (map[0][x] == '0' || map[y][x] == '0')
			return (1);
		x++;
	}
	y = 0;
	x = stlen(map[0]) - 1;
	while (map[y])
	{
		if (map[y][0] == '0' || map[y][x] == '0')
			return (1);
		y++;
	}
	return (0);
}

int	check_each_char(char **map)
{
	int	x;
	int	y;

	y = 1;
	while (map[y])
	{
		x = 1;
		while (map[y][x])
		{
			if (map[y][x] == '0')
			{
				if (map[y][x - 1] == ' ' || map[y - 1][x] == ' '
					|| map[y + 1][x] == ' ' || map[y][x + 1] == ' ')
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	check_map_closed(t_player *play, char **map)
{
	map_grab_player(play, map);
	if (check_map_border(map) || check_each_char(map))
		return (write_error("map not closed", 1));
	return (0);
}
