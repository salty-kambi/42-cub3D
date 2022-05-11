/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_data_extract.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:18:39 by lsuau             #+#    #+#             */
/*   Updated: 2022/05/03 18:22:56 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	len_line(char *file)
{
	int	x;

	x = 0;
	while (file[x] != '\n')
		x++;
	return (x);
}

int	fc_rgb_shift(char *file)
{
	int	r;
	int	g;
	int	b;
	int	x;

	x = 1;
	r = ft_atoi(file);
	while (file[x - 1] != ',')
		x++;
	g = ft_atoi(file + x);
	x++;
	while (file[x - 1] != ',')
		x++;
	b = ft_atoi(file + x);
	return ((0 << 24) + (r << 16) + (g << 8) + b);
}

void	line_process_fc(t_data *data, char *file, int x)
{
	if (!stncmp(file + x, "F ", 2))
		data->txt.floor = fc_rgb_shift(file + x + 2);
	if (!stncmp(file + x, "C ", 2))
		data->txt.celling = fc_rgb_shift(file + x + 2);
}

int	line_process(t_data *data, char *file, int x)
{
	if (!stncmp(file + x, "NO ", 3))
	{
		data->txt.north = ft_substr(file + x, 3, len_line(file + x) - 3);
		if (!data->txt.north)
			return (0);
	}
	else if (!stncmp(file + x, "SO ", 3))
	{
		data->txt.south = ft_substr(file + x, 3, len_line(file + x) - 3);
		if (!data->txt.south)
			return (0);
	}
	else if (!stncmp(file + x, "WE ", 3))
	{
		data->txt.west = ft_substr(file + x, 3, len_line(file + x) - 3);
		if (!data->txt.west)
			return (0);
	}
	else if (!stncmp(file + x, "EA ", 3))
	{
		data->txt.east = ft_substr(file + x, 3, len_line(file + x) - 3);
		if (!data->txt.east)
			return (0);
	}
	return (x + len_line(file + x) + 1);
}

int	data_extract(t_data *data, char *file)
{
	int	x;
	int	n;

	x = 0;
	n = 0;
	while (n < 6)
	{
		line_process_fc(data, file, x);
		x = line_process(data, file, x);
		if (!x)
			return (1);
		n++;
	}
	data->map = file_map_extract(file + x);
	if (!data->map)
		return (1);
	return (0);
}
