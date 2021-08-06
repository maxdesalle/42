/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 15:51:54 by mdesalle          #+#    #+#             */
/*   Updated: 2021/08/06 10:20:08 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

/* checks for problems in arguments */

static int	checker(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != FOUR_ARG)
		return (0);
	if (argv[2][0] == '\0' || argv[3][0] == '\0')
		return (0);
	while (argv[2][i] && (argv[2][i] == ' '
				|| (argv[2][i] >= 9 && argv[2][i] <= 13)))
		i += 1;
	if (argv[2][i] == '\0')
		return (0);
	i = 0;
	while (argv[3][i] && (argv[3][i] == ' '
				|| (argv[3][i] >= 9 && argv[3][i] <= 13)))
		i += 1;
	if (argv[3][i] == '\0')
		return (0);
	return (1);
}

/* initiates the struct values */

int	init(t_node *s, int argc, char **argv)
{
	s->i = -1;
	s->file1 = NULL;
	s->file2 = NULL;
	s->path = NULL;
	s->args1 = NULL;
	s->args2 = NULL;
	return (checker(argc, argv));
}
