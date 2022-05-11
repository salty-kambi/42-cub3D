/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:42:38 by lsuau             #+#    #+#             */
/*   Updated: 2022/05/02 15:45:58 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	file_size(char *name)
{
	int		fd;
	int		x;
	int		size;
	char	buf[1];

	fd = open(name, O_RDONLY);
	if (fd == -1)
		return (-1);
	x = 1;
	size = 0;
	while (x)
	{
		x = read(fd, buf, 1);
		size += x;
	}
	close(fd);
	return (size);
}

int	read_map_file(char *name, char **file)
{
	int	size;
	int	fd;

	size = file_size(name);
	if (size == -1)
		return (write_error("cant open file", 1));
	*file = malloc(sizeof(char) * (size + 2));
	if (!*file)
		return (write_error("malloc", 1));
	fd = open(name, O_RDONLY);
	read(fd, *file, size);
	(*file)[size] = 0;
	close(fd);
	return (0);
}
