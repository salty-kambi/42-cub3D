/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:11:09 by lsuau             #+#    #+#             */
/*   Updated: 2022/05/07 16:48:29 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	print_tab(char **tab)
{
	int	x;

	x = 0;
	if (!tab)
		return ;
	while (tab[x])
	{
		printf("%s\n", tab[x]);
		x++;
	}
}

int	map_parsing(t_data *data, char *name)
{
	if (stlen(name) < 5 || stncmp(name + stlen(name) - 4, ".cub", 4))
		return (write_error("Not a .cub file format", 1));
	if (read_map_file(name, &(data->file)) || map_file_error(data->file))
		return (1);
	 if (data_extract(data, data->file))
		 return (write_error("malloc", 1));
	free(data->file);
	if (check_map_closed(data->map))
		return (1);
	return (0);
}
