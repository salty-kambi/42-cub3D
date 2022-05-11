/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:15:31 by lsuau             #+#    #+#             */
/*   Updated: 2022/05/02 17:28:56 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	clean_empty_line(char *file, int x)
{
	int	y;

	y = x;
	while (file[y] == ' ' || file[y] == '\n')
		y++;
	if (y != x)
		stcpy_same_string(file + x, file + y);
}

void	clean_space(char *file, int x)
{
	int	y;

	y = x;
	while (file[y] == ' ')
		y++;
	if (y != x)
		stcpy_same_string(file + x, file + y);
}

int	check_elem(char *file, int x, int *elem)
{
	int	n;

	n = -1;
	if (!stncmp(file + x, "NO ", 3))
		n = 0;
	if (!stncmp(file + x, "SO ", 3))
		n = 1;
	if (!stncmp(file + x, "WE ", 3))
		n = 2;
	if (!stncmp(file + x, "EA ", 3))
		n = 3;
	if (!stncmp(file + x, "F ", 2))
		n = 4;
	if (!stncmp(file + x, "C ", 2))
		n = 5;
	if (n == -1 || elem[n] == 1)
		return (1);
	elem[n] = 1;
	return (0);
}

int	check_file_line(char *file, int x)
{
	if (check_fc_elem(file, x))
		return (1);
	while (file[x] != ' ')
	{
		if (!file[x] || file[x] == '\n')
			return (1);
		x++;
	}
	x++;
	clean_space(file, x);
	if (!file[x] || file[x] == '\n')
		return (1);
	while (file[x] && file[x] != ' ' && file[x] != '\n')
		x++;
	clean_space(file, x);
	if (file[x] != '\n')
		return (1);
	return (0);
}

int	map_file_error(char *file)
{
	int	x;
	int	*elem;

	x = 0;
	elem = (int [6]){0};
	while (elem_complete(elem))
	{
		clean_empty_line(file, x);
		if (check_elem(file, x, elem) || check_file_line(file, x))
			return (write_error("bad file", 1));
		while (file[x] && file[x] != '\n')
			x++;
		if (file[x])
			x++;
		else
			return (write_error("bad file", 1));
	}
	if (file[x - 1] == '\n')
		x--;
	clean_around_map(file, x);
	if (check_cara_map(file, x))
		return (write_error("bad file", 1));
	return (0);
}
