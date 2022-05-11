/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_error_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:08:34 by lsuau             #+#    #+#             */
/*   Updated: 2022/05/02 19:06:07 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	stcpy_same_string(char *dst, const char *src)
{
	int	x;
	int	y;

	x = 0;
	y = stlen(dst) - stlen(src);
	while (src[x])
	{
		dst[x] = src[x];
		x++;
	}
	dst[x] = 0;
	y += x;
	while (x < y)
		dst[x++] = 0;
	return ;
}

int	only_sp_count(char *file, int y)
{
	int	x;
	int	y2;

	x = y;
	y2 = y;
	while (file[y2] == ' ' || file[y2] == '\n')
	{
		if (file[y2] == '\n')
			y = y2;
		y2++;
	}
	if (file[y2] == '\n')
		y2++;
	return (y - x);
}

int	check_sp_nl(char *file, int x)
{
	while (file[x])
	{
		if (file[x] != ' ' && file[x] != '\n')
			return (1);
		x++;
	}
	return (0);
}
