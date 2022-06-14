/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:12:59 by lsuau             #+#    #+#             */
/*   Updated: 2022/06/14 11:03:52 by mapontil         ###   ########.fr       */
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

# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720
# define SPEED 0.05

# define W_KEY 13
# define S_KEY 1
# define A_KEY 0
# define D_KEY 2
# define ESC_KEY 53

typedef struct s_file_data {
	char	*file;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		floor;
	int		celling;
}	t_file_data;

typedef struct s_movement
{
	int	right;
	int	left;
	int	forward;
	int	backward;
}	t_movement;

typedef struct s_image {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		wi_he[2];
}	t_image;

typedef struct s_minimap {
	float	sqr;
	int		l;
	float	ogx;
	float	ogy;
	int		x_max;
	int		y_max;
	int		map_x_max;
	int		map_y_max;
	t_image	*img;
}	t_minimap;

typedef struct s_texture {
	t_image	wall;
	t_image	north;
	t_image	south;
	t_image	west;
	t_image	east;
	t_image	mini;
	t_image	left_border;
	t_image	down_border;
}	t_texture;

typedef struct s_player {
	char	c;
	float	px;
	float	py;
	float	pdx;
	float	pdy;
	float	pa;
	float	planex;
	float	planey;
}	t_player;

typedef struct s_raycast {
	float	raydirx;
	float	raydiry;
	int		mapx;
	int		mapy;
	float	sidedistx;
	float	sidedisty;
	float	deltadistx;
	float	deltadisty;
	int		stepx;
	int		stepy;
	float	walldist;
	int		side;
	int		hit;
}	t_raycast;

typedef struct s_data {
	void		*mlx;
	void		*win;
	int			display[2];
	char		**map;
	t_file_data	fdata;
	t_texture	txt;
	t_player	p;
	t_minimap	mp;
	t_movement	m;
}				t_data;

//src
//		data.c
void	data_init(t_data *data);
int		data_clear(t_data *data);
void	fdata_clear(t_file_data *fdata);
void	mp_init_1(t_data *data);

//game
//		image_init.c
void	img_init(t_data *data);
//		game_loop.c
int		game_loop(t_data *data);
//		minimap.c
void	minimap(t_data *data);
//		player_minimap
void	minimap_player(t_minimap *mp, t_player *p);
//		movement.c
void	up_down_movement(t_player *p, char **map, int key);
void	rotate_movement(t_player *p, float speed);
void	movement_init(t_data *data);
void	movement(t_movement *m, t_player *p, char **map);

//graphic
//		image.c
void	pixel_put(t_image *spr, int x, int y, int rgb);
int		get_pix_txt(t_data *data, int side, float x, float y);
//		raycasting.c
void	raycasting(t_data *data);
void	build_wall(t_raycast *ray, t_data *data, int x);

//parsing
//		parsing.c
int		map_parsing(t_data *data, char *name);
//		file_read.c
int		read_map_file(char *name, char **file);
//		file_data_extract.c
int		data_extract(t_data *data, char *file);
int		len_line(char *file);
int		rgb_shift(char *file);
//		file_map_extract.c
char	**file_map_extract(char *file);
//		map_closed.c
int		check_map_closed(t_player *play, char **map);
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
char	*ft_substr(char const	*s, int start, int len);
int		ft_atoi(const char *str);
//		stock_2.c
void	free_tab(char **tab);
void	*ft_calloc(int count, int size);
char	*ft_strdup(const char *s1);
void	stcpy(char *dst, const char *src);
int		tab_len(char **tab);
//		stock_3.c
int		absol(int n);
float	fabsolf(float n);
//		ft_sixth.c
int		only_sp_count(char *file, int y);

void	print_tab(char **tab);
#endif 