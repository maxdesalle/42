/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 15:51:54 by mdesalle          #+#    #+#             */
/*   Updated: 2021/08/04 11:19:18 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

/* initiates the struct values */

void	init(t_node *s)
{
	s->i = -1;
	s->file1 = NULL;
	s->file2 = NULL;
	s->path = NULL;
	s->args1 = NULL;
	s->args2 = NULL;
}
