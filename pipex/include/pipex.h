/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 09:36:10 by mdesalle          #+#    #+#             */
/*   Updated: 2021/07/29 11:19:36 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/* path.c */
char	**path_finder(char **envp);

/* utilities/ft_split.c */
char	**ft_split(char const *s, char c);

/* utilities/ft_strncmp.c */
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/* misc/return.c */
int		normal(int return_code);
int		error(void);

#endif
