/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:34:25 by mdesalle          #+#    #+#             */
/*   Updated: 2021/04/02 09:45:56 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* returns the length of the string */

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (s == 0)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

/* searches a character in a string and returns a pointer to it if found */

char	*ft_strchr(const char *s, int c)
{
	if (c == '\0')
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	while (*s)
		if (*s++ == c)
			return ((char *)--s);
	return (NULL);
}

/* swaps image and address with temporary ones to avoid lag */

void	ft_swap(t_list *c)
{
	void	*swap;

	swap = c->mlx.adr;
	c->mlx.adr = c->mlx.asp;
	c->mlx.asp = swap;
	swap = c->mlx.img;
	c->mlx.img = c->mlx.isp;
	c->mlx.isp = swap;
}

/* initiates all the values for the utilities struct */

void	ft_init(t_list *c)
{
	c->uti.i = 0;
	c->uti.err = 0;
	c->uti.nbl = 0;
	c->uti.ll = 0;
	c->uti.ctr = 0;
	c->uti.mps = 0;
	c->uti.ext = 0;
}

/* counts all the lines, computes the map line length and mallocs it */

int	ft_count(char *mapfile, t_list *c)
{
	int		fd;
	char	*line;

	fd = open(mapfile, O_RDONLY);
	if (fd == -1)
		return (ft_error(3, c));
	while (get_next_line(fd, &line) == 1)
	{
		if (ft_map_valid(line, c) == 1)
			if (c->uti.mps != 1)
				c->uti.mps = 1;
		if (c->uti.mps == 1)
		{
			c->uti.nbl++;
			if ((int)ft_strlen(line) > c->uti.ll)
				c->uti.ll = (int)ft_strlen(line);
		}
		free(line);
	}
	close(fd);
	c->map.map = malloc(c->uti.nbl * sizeof(char *));
	if (!(c->map.map))
		return (ft_error(5, c));
	return (0);
}
