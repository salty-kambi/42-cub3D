/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_closed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:16:37 by lsuau             #+#    #+#             */
/*   Updated: 2022/05/12 15:12:59 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	map_remove_player(char *line)
{
	int	x;

	x = 0;
	while (line[x])
	{
		if (line[x] == 'N' || line[x] == 'S'
			|| line[x] == 'W' || line[x] == 'E')
			line[x] = '0';
		x++;
	}
}

char	**map_cpy(char **map)
{
	char	**ret;
	int		n;

	n = 0;
	ret = calloc(sizeof(char *), (tab_len(map) + 1));
	if (!ret)
		return (0);
	while (map[n])
	{
		ret[n] = ft_strdup(map[n]);
		if (!ret[n])
		{
			free_tab(ret);
			return (0);
		}
		map_remove_player(ret[n]);
		n++;
	}
	return (ret);
}

int	check_map_border(char **map)
{
	int	n;
	int	x;

	n = tab_len(map) - 1;
	x = 0;
	while (map[0][x])
	{
		if (map[0][x] == '0' || map[n][x] == '0')
			return (1);
		x++;
	}
	n = 0;
	x = stlen(map[0]) - 1;
	while (map[n])
	{
		if (map[n][0] == '0' || map[n][x] == '0')
			return (1);
		n++;
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

int	check_map_closed(char **map)
{
	char	**cpy;

	cpy = map_cpy(map);
	if (!cpy)
		return (write_error("malloc", 1));
	if (check_map_border(cpy) || check_each_char(cpy))
		return (write_error("map not closed", 1));
	free_tab(cpy);
	return (0);
}
