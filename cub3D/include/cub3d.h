/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 21:16:13 by mdesalle          #+#    #+#             */
/*   Updated: 2021/04/04 21:35:21 by mdesalle         ###   ########.fr       */
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
# include <stdio.h>
# include "../minilibX/mlx.h"

# define BUFFER_SIZE 32

# define A 0
# define S 1
# define D 2
# define W 13
# define ESC 53
# define LEFT 123
# define RIGHT 124
# define BACKWARD 125
# define FORWARD 126

# define FORWARD_MOVE 1
# define BACK_MOVE 0
# define RIGHT_MOVE 1
# define LEFT_MOVE 0

typedef struct s_gnl
{
	int	check;
	int	reader;
}				t_gnl;

typedef struct s_fc
{
	int	c;
	int	f;

	int	cre;
	int	cgr;
	int	cbl;

	int	fre;
	int	fgr;
	int	fbl;
}				t_fc;

typedef struct s_ray
{
	int		hit;
	int		sde;

	int		mx;
	int		my;

	int		tx;
	int		ty;

	int		sx;
	int		sy;

	int		ds;
	int		de;

	int		lh;
	int		rc;

	double	wx;

	double	stp;
	double	txp;

	double	px;
	double	py;

	double	dx;
	double	dy;

	double	plx;
	double	ply;

	double	cx;
	double	prp;

	double	rdx;
	double	rdy;

	double	sdx;
	double	sdy;

	double	rs;
	double	ms;

	double	ddx;
	double	ddy;
}				t_ray;

typedef struct s_mlx
{
	int				end;
	int				tdr;
	int				sl;
	int				bpp;
	void			*img;
	void			*win;
	void			*mlx;
	unsigned int	*adr;

	void			*isp;
	unsigned int	*asp;
}				t_mlx;

typedef struct s_map
{
	int		prx;
	int		pry;
	int		ori;
	char	**map;
}				t_map;

typedef struct s_uti
{
	int	i;
	int	j;
	int	k;
	int	fd;
	int	err;
	int	nbl;
	int	ll;
	int	ctr;
	int	mps;
	int	ext;
	int	sve;
	int	chk;
	int	stt;
	int	map;
	int	tex;
	int	ult;
	int	arg;
}				t_uti;

typedef struct s_spr
{
	int		dsx;
	int		dex;

	int		dsy;
	int		dey;

	int		*spo;
	int		spc;

	int		spw;
	int		sph;

	int		ssx;

	double	*sx;
	double	*sy;

	double	inv;

	double	tfx;
	double	tfy;

	double	spx;
	double	spy;

	double	*zbf;
	double	*spd;
}				t_spr;

typedef struct s_res
{
	int	rx;
	int	ry;
	int	sx;
	int	sy;
}				t_res;

typedef struct s_tex
{
	unsigned int	*adr;
	int				wdh;
	int				hgt;
	int				end;
	int				sl;
	int				bpp;
	char			*pth;
	void			*img;
}				t_tex;

typedef struct s_list
{
	t_fc	fc;
	t_ray	ray;
	t_mlx	mlx;
	t_map	map;
	t_uti	uti;
	t_spr	spr;
	t_res	res;
	t_tex	tex[5];
}				t_list;

int					ft_raycast(t_list *c);

int					ft_map_valid(char *line, t_list *c);
int					ft_count(char *mapfile, t_list *c);

int					ft_args(char *argv, t_list *c);
int					ft_argn(char *argv);

int					ft_terror(t_list *c);
int					ft_error(int option, t_list *c);

int					get_next_line(int fd, char **line);

int					ft_exit(t_list *c);

int					ft_key(int key, t_list *c);
void				ft_start(t_list *c);

void				ft_order(t_list *c);
void				ft_sprisual(t_list *c);

size_t				ft_strlen(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strcat_alpha(char *dest, char *src, int len);

int					ft_save(t_list *c);

void				ft_visinit(t_list *c);
void				ft_orinit(t_list *c);

void				ft_height(t_list *c);
void				ft_delta(t_list *c);

void				ft_rright(t_list *c);
void				ft_rleft(t_list *c);
void				ft_vertical(t_list *c, int option);
void				ft_horizontal(t_list *c, int option);

size_t				ft_strlen(const char *s);
char				*ft_strchr(const char *s, int c);
void				ft_swap(t_list *c);
void				ft_init(t_list *c);
void				ft_remap(t_list *c);

void				ft_tex(char *line, t_list *c);
void				ft_texplace(t_list *c);

int					ft_map(char *line, t_list *c);

void				ft_res(char *line, t_list *c);

void				ft_sort(t_list *c);
void				ft_sprosition(t_list *c);

int					ft_hborder(t_list *c);
int					ft_vborder(t_list *c);

#endif
