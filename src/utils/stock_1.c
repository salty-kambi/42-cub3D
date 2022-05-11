/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:29:23 by lsuau             #+#    #+#             */
/*   Updated: 2022/05/02 19:03:50 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	stlen(const char *s)
{
	int	x;

	if (!s)
		return (0);
	x = 0;
	while (s[x])
		x++;
	return (x);
}

int	stncmp(const char *s1, const char *s2, int n)
{
	int	x;

	x = 0;
	if (n < 1)
		return (0);
	while (s1[x] && s2[x] && (s1[x] == s2[x]) && n > 0)
	{
		n--;
		if (n > 0)
			x++;
	}
	return ((unsigned char)s1[x] - (unsigned char)s2[x]);
}

int	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_substr(char const	*s, unsigned int start, int len)
{
	int		x;
	int		y;
	char	*r;

	if (!s)
		return (0);
	if (len > stlen(s))
		len = stlen(s);
	r = malloc(sizeof(char) * (len + 1));
	if (!r)
		return (0);
	x = 0;
	y = 0;
	while (s[x] && x < (len + start))
	{
		if (x >= start && x < (len + start))
		{
			r[y] = s[x];
			y++;
		}
		x++;
	}
	r[y] = 0;
	return (r);
}

int	ft_atoi(const char *str)
{
	int		x;
	long	res;
	int		fact;

	x = 0;
	res = 0;
	fact = 1;
	while (str[x] == ' ' || (str[x] >= '\t' && str[x] <= '\r'))
		x++;
	if (str[x] == '-')
	{
		x++;
		fact = -1;
	}
	else if (str[x] == '+')
		x++;
	while (str[x] >= '0' && str[x] <= '9')
	{
		res = res * 10 + str[x++] - '0';
		if (res > 2147483648 && fact == -1)
			return (0);
		else if (res > 2147483647 && fact == 1)
			return (-1);
	}
	return (res * fact);
}
