/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:34:25 by mdesalle          #+#    #+#             */
/*   Updated: 2021/04/03 17:50:46 by mdesalle         ###   ########.fr       */
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
	c->fc.cre = -1;
	c->fc.cgr = -1;
	c->fc.cbl = -1;
	c->fc.fre = -1;
	c->fc.fgr = -1;
	c->fc.fbl = -1;
	c->uti.stt = 0;
	c->uti.map = 0;
}

/* replaces '4' value indicators with '1' value walls in the map array */

void	ft_remap(t_list *c)
{
	int	i;
	int	j;

	j = -1;
	while (++j < c->uti.nbl)
	{
		i = -1;
		while (++i < c->uti.ll)
			if (c->map.map[j][i] == '4')
				c->map.map[j][i] = '1';
	}
}
