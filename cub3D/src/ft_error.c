/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 21:48:54 by mdesalle          #+#    #+#             */
/*   Updated: 2021/04/02 11:49:35 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
** returns an error based on the given option.
*/

int	ft_error(int option, t_list *c)
{
	c->uti.err = 1;
	if (option == 0)
		write(1, "Error\nInvalid argument\n", 23);
	if (option == 1)
		write(1, "Error\nInvalid resolution\n", 25);
	if (option == 2)
		write(1, "Error\nInvalid map file path\n", 28);
	if (option == 3)
		write(1, "Error\nInvalid map file\n", 23);
	if (option == 4)
		write(1, "Error\nInvalid map\n", 18);
	if (option == 5)
		write(1, "Error\nFailed memory allocation\n", 31);
	if (option == 6)
		write(1, "Error\nInvalid minilibX\n", 23);
	if (option == 7)
		write(1, "Error\nPlayer not found\n", 24);
	if (option == 8)
		write(1, "Error\nImage file could not be created\n", 38);
	if (option == 9)
		write(1, "Error\nTexture could not be loaded\n", 34);
	ft_exit(c);
	return (0);
}
