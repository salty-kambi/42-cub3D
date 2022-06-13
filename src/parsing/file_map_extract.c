/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_map_extract.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 00:07:36 by lsuau             #+#    #+#             */
/*   Updated: 2022/05/27 12:37:01 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	map_len_max(char *file)
{
	int	x;
	int	len;
	int	len_max;

	x = 0;
	len_max = 0;
	while (file[x])
	{
		len = len_line(file + x);
		if (len > len_max)
			len_max = len;
		x += len + 1;
	}
	return (len_max);
}

int	line_count(char *file)
{
	int	x;
	int	nb_line;

	x = 0;
	nb_line = 0;
	while (file[x])
	{
		if (file[x] == '\n')
			nb_line++;
		x++;
	}
	return (nb_line);
}

int	nl_stcpy(char *dst, const char *src, int len_max)
{
	int	x;
	int	y;

	x = 0;
	while (src[x] != '\n')
	{
		dst[x] = src[x];
		x++;
	}
	y = x;
	while (x < len_max)
	{
		dst[x] = ' ';
		x++;
	}
	dst[x] = 0;
	return (y + 1);
}

int	fill_map_tab(char *file, char **map, int nb_line, int len_max)
{
	int	n;
	int	x;

	n = 0;
	x = 0;
	while (n < nb_line)
	{
		map[n] = malloc(sizeof(char) * (len_max + 1));
		if (!map[n])
			return (1);
		x += nl_stcpy(map[n], file + x, len_max);
		n++;
	}
	return (0);
}

char	**file_map_extract(char *file)
{
	int		len_max;
	int		nb_line;
	char	**map;

	nb_line = line_count(file);
	map = calloc(sizeof(char *), (nb_line + 1));
	if (!map)
		return (0);
	map[nb_line] = 0;
	len_max = map_len_max(file);
	if (fill_map_tab(file, map, nb_line, len_max))
	{
		free_tab(map);
		return (0);
	}
	return (map);
}
