/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 10:51:18 by mdesalle          #+#    #+#             */
/*   Updated: 2021/01/30 16:53:46 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <limits.h>

# define BUFFER_SIZE 32

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

typedef struct	q_list
{
	int	Rx;
	int	Ry;
	int	i;
}				v_list;

/*
** cub3d.c
*/

void			ft_analytics(char *mapfile, v_list *cube);

/*
** ft_resolution.c
*/

void			ft_resolution(char **line, v_list *cube);

/*
** get_next_line.c
*/

int				get_next_line(int fd, char **line);

/*
** get_next_line_utils.c
*/

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

size_t			ft_strlen(const char *s);

#endif
