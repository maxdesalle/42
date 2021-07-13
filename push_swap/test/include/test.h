/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 09:36:10 by mdesalle          #+#    #+#             */
/*   Updated: 2021/07/13 09:36:12 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
#include <time.h>

# define STDOUT 1
# define STDERR 2

/* ft_intlen.c */
size_t	ft_intlen(long x);

/* ft_itoa.c */
char	*ft_itoa(int n);

/* ft_atoi.c */
long	ft_atoi(const char *nptr);

/* ft_strcat.c */
char	*ft_strcat(char *dest, const char *src);

/* ft_strlen.c */
size_t	ft_strlen(const char *s);

#endif
