/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:11:09 by lsuau             #+#    #+#             */
/*   Updated: 2022/06/05 14:38:59 by lsuau            ###   ########.fr       */
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

int	check_txt_path(t_file_data *fdata)
{
	int	fd;
	int	n;

	n = 0;
	fd = open(fdata->north, O_RDONLY);
	if (fd == -1)
		n = 1;
	close(fd);
	fd = open(fdata->south, O_RDONLY);
	if (fd == -1)
		n = 1;
	close(fd);
	fd = open(fdata->west, O_RDONLY);
	if (fd == -1)
		n = 1;
	close(fd);
	fd = open(fdata->east, O_RDONLY);
	if (fd == -1)
		n = 1;
	close(fd);
	if (n)
		return (write_error("no such texture file", 1));
	return (0);
}

int	map_parsing(t_data *data, char *name)
{
	if (stlen(name) < 5 || stncmp(name + stlen(name) - 4, ".cub", 4))
		return (write_error("Not a .cub file format", 1));
	if (read_map_file(name, &(data->fdata.file)))
		return (1);
	if (map_file_error(data->fdata.file))
		return (1);
	if (data_extract(data, data->fdata.file))
		return (write_error("malloc", 1));
	if (check_map_closed(&data->p, data->map)
		|| check_txt_path(&data->fdata))
	{
		free_tab(data->map);
		return (1);
	}
	return (0);
}
