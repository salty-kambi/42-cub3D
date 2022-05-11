/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 23:49:56 by lsuau             #+#    #+#             */
/*   Updated: 2022/05/03 18:26:03 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	free_tab(char **tab)
{
	int	x;

	x = 0;
	while (tab[x])
	{
		free(tab[x]);
		x++;
	}
	free(tab);
}

void	*ft_calloc(int count, int size)
{
	char	*r;
	int		x;

	x = 0;
	r = malloc(size * count);
	if (!r)
		return (0);
	while (x < (size * count))
	{
		r[x] = 0;
		x++;
	}
	return (r);
}

char	*ft_strdup(const char *s1)
{
	int		x;
	char	*r;

	x = 0;
	r = malloc(stlen(s1) + 1);
	if (!r)
		return (0);
	stcpy(r, s1);
	return (r);
}

void	stcpy(char *dst, const char *src)
{
	int	x;

	x = 0;
	while (src[x])
	{
		dst[x] = src[x];
		x++;
	}
	dst[x] = 0;
}

int	tab_len(char **tab)
{
	int	x;

	x = 0;
	while (tab[x])
		x++;
	return (x);
}
