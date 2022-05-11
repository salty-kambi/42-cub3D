/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:26:16 by lsuau             #+#    #+#             */
/*   Updated: 2022/04/28 17:17:36 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	write_error(char *s, int ret)
{
	write(2, "Error\n", 6);
	write(2, s, stlen(s));
	write(2, "\n", 1);
	return (ret);
}
