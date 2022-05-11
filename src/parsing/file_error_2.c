/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_error_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:14:20 by lsuau             #+#    #+#             */
/*   Updated: 2022/05/11 12:25:31 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	elem_complete(int *elem)
{
	int	x;

	x = 0;
	while (x < 6)
	{
		if (!elem[x])
			return (1);
		x++;
	}
	return (0);
}

void	clean_around_map(char *file, int x)
{
	int	y;

	stcpy_same_string(file + x, file + x + only_sp_count(file, x));
	while (file[x] && check_sp_nl(file, x))
	{
		while (file[x] && file[x] != '\n')
			x++;
		y = x;
		while (file[y - 1] == ' ')
			y--;
		if (y != x)
			stcpy_same_string(file + y, file + x);
		x = y;
		if (file[x])
			x++;
	}
	if (!file[x] && file[x - 1] != '\n')
		file[x++] = '\n';
	file[x] = 0;
}

int	check_cara_map(char *file, int x)
{
	int		*cara;
	char	c;

	cara = (int [4]){0};
	while (file[x])
	{
		c = file[x];
		if (c != '1' && c != '0' && c != 'N' && c != 'S'
			&& c != 'E' && c != 'W' && c != '\n' && c != ' ')
			return (1);
		cara[0] += (c == 'N');
		cara[1] += (c == 'S');
		cara[2] += (c == 'E');
		cara[3] += (c == 'W');
		x++;
	}
	if (cara[0] + cara[1] + cara[2] + cara[3] != 1)
		return (1);
	return (0);
}

int	check_fc_elem_2(char *file, int *x, int n)
{
	int	nb;

	nb = ft_atoi(file + *x);
	if (nb < 0 || nb > 255)
		return (1);
	if (n)
	{
		while (file[*x] != '\n' && file[*x] != ' ')
		{
			if (!is_num(file[*x]))
				return (1);
			*x += 1;
		}
		return (0);
	}
	while (file[*x] != ',' && file[*x] != ' ')
	{
		if (!is_num(file[*x]))
			return (1);
		*x += 1;
	}
	return (0);
}

int	check_fc_elem(char *file, int x)
{
	int	n;

	if (!(file[x] == 'F' || file[x] == 'C'))
		return (0);
	x += 2;
	n = 0;
	while (n < 2)
	{
		clean_space(file, x);
		if (!is_num(file[x]))
			return (1);
		if (check_fc_elem_2(file, &x, 0))
			return (1);
		clean_space(file, x);
		if (file[x] != ',')
			return (1);
		x++;
		n++;
	}
	clean_space(file, x);
	if (check_fc_elem_2(file, &x, 1))
		return (1);
	return (0);
}
