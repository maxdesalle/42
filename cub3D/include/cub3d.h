/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 10:51:18 by mdesalle          #+#    #+#             */
/*   Updated: 2021/02/24 09:04:48 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <limits.h>
# include <string.h>
# include "../minilibX/mlx.h"

# define BUFFER_SIZE 32

# define A 0
# define S 1
# define D 2
# define W 13
# define ESC 53
# define LEFT 123
# define RIGHT 124

# define FORWARD_MOVE 1
# define BACK_MOVE -1
# define RIGHT_MOVE 1
# define LEFT_MOVE -1
# define RIGHT_ROTATE 1
# define LEFT_ROTATE -1

/*
** linked list used for get_next_line.c
*/

typedef struct	s_list
{
	int	check;
	int	reader;
}				t_list;

/*
** linked list used accross all the code to store the necessary info about
** the map, textures...
*/

typedef struct s_ray
{
	int	mapX;
	int	mapY;

	int	raycounter;

	double	posX;
	double	posY;

	double	dirX;
	double	dirY;

	double	planeX;
	double	planeY;

	double	time;
	double	oldtime;

	double	cameraX;

	double	rayDirX;
	double	rayDirY;

	double	sideDistX;
	double	sideDistY;

	double	rotspeed;
	double	movespeed;

	double	deltaDistX;
	double	deltaDistY;
}				t_ray;

typedef struct	s_player
{
	int	Px;
	int	Py;
	int	orientation;
}				t_player;

typedef struct s_sprite
{
	int	spritecounter;
	double	*Sx;
	double	*Sy;
}				t_sprite;

typedef struct s_texture
{
	int	*addr;
	int	width;
	int	height;
	int	endian;
	int	size_line;
	int	bits_per_pixel;
	void	*img_ptr;
}				t_texture;

typedef struct s_mlx
{
	int		*addr;
	int		endian;
	int		size_line;
	int		bits_per_pixel;
	void		*img_ptr;
	void		*win_ptr;
	void		*mlx_ptr;
	t_texture	north;
	t_texture	south;
	t_texture	east;
	t_texture	west;
	t_texture	sprite;
}				t_mlx;

typedef struct s_screenres
{
	int	Rx;
	int	Ry;
	int	Sx;
	int	Sy;
}				t_screenres;

typedef struct s_path
{
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	char	*SP;
}				t_texture_path;

typedef struct s_utilities
{
	int	i;
	int	error;
	int	nboflines;
	int	linelength;
	int	counter;
}				t_utilities;

typedef struct	s_mainlist
{
	int	**map;
	t_ray		ray;
	t_mlx		mlx;
	t_sprite	sprite;
	t_player	player;
	t_utilities	utilities;
	t_screenres	screenres;
	t_texture_path	texture_path;
}				v_list;

/*
** ft_resolution.c
*/

void			ft_resolution(char *line, v_list *cube);

/*
** ft_textures.c
*/

void			ft_textures(char *line, v_list *cube);

/*
** ft_initiation.c
*/

int			ft_initiation(v_list *cube);

/*
** ft_map.c
*/

int				ft_wall_checker(v_list *cube);
int				ft_wall_check(v_list *cube);
int				ft_map_free(v_list *cube);
int				ft_map_allocator(v_list *cube);
int				ft_array_insert(char *line, v_list *cube);

/*
** ft_mapcheck.c
*/

int				ft_mapsize(char *line, v_list *cube);
int				ft_mapvalid(char *line);
int				ft_player_position(v_list *cube);

/*
** ft_sprite.c
*/

int				ft_sprite_position(v_list *cube);

/*
** ft_keys.c
*/

int				ft_keycode(int keycode, v_list *cube);

/*
** ft_visual.c
*/

int				ft_visual(v_list *cube);

/*
** ft_exit.c
*/

int				ft_exit(v_list *cube);

/*
** get_next_line.c
*/

int				get_next_line(int fd, char **line);

/*
** get_next_line_utils.c
*/

size_t			ft_strlen(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strcat_alpha(char *dest, char *src, int len);

/*
** ft_error_check.c
*/

int				ft_argnamecheck(char *argv);
int				ft_argsavecheck(char *argv);
int				ft_error(int option);

/*
** ft_utilities_one.c
*/

int				ft_atoi_char(char c);
size_t				ft_strlen_alpha(const char *s);

#endif
