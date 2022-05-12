/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:12:59 by lsuau             #+#    #+#             */
/*   Updated: 2022/05/12 17:06:02 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../mlx/mlx.h"

typedef struct s_file_data {
	char	*file;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		floor;
	int		celling;
}	t_file_data;

typedef struct s_image {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		wi_he[2];
}	t_image;

typedef struct s_texture {
	t_image	north;
	t_image	south;
	t_image	west;
	t_image	east;
	t_image	floor;
	t_image	celling;
}	t_texture;

typedef struct s_player {
	float	pos[2];
}	t_player;

typedef struct s_data {
	void		*mlx;
	void		*win;
	int			display[2];
	char		**map;
	int			run;
	t_file_data	fdata;
	t_texture	txt;
	t_player	play;
}				t_data;

//src
//		data.c
void	data_init(t_data *data);
int		data_clear(t_data *data);
void	fdata_clear(t_file_data *fdata);

//le_ray
//		image.c
void	img_init(t_data *data);
//		game_init.c
void	game_init(t_data *data);

//parsing
//		parsing.c
int		map_parsing(t_data *data, char *name);
//		file_read.c
int		read_map_file(char *name, char **file);
//		file_data_extract.c
int		data_extract(t_data *data, char *file);
int		len_line(char *file);
//		file_map_extract.c
char	**file_map_extract(char *file);
//		map_closed.c
int		check_map_closed(char **map);
//		file_error.c
int		map_file_error(char *file);
int		elem_complete(int *elem);
void	clean_space(char *file, int x);
int		check_cara_map(char *file, int x);
int		check_fc_elem(char *file, int x);
void	clean_around_map(char *file, int x);
int		check_sp_nl(char *file, int x);
void	stcpy_same_string(char *dst, const char *src);

//utils
//		error.c
int		write_error(char *s, int ret);
//		stock_1.c
int		stlen(const char *s);
int		stncmp(const char *s1, const char *s2, int n);
int		is_num(char c);
char	*ft_substr(char const	*s, unsigned int start, int len);
int		ft_atoi(const char *str);
//		stock_2.c
void	free_tab(char **tab);
void	*ft_calloc(int count, int size);
char	*ft_strdup(const char *s1);
void	stcpy(char *dst, const char *src);
int		tab_len(char **tab);
//		ft_sixth.c
int		only_sp_count(char *file, int y);

void	print_tab(char **tab);

 
#endif 