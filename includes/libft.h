/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 10:10:43 by mdesalle          #+#    #+#             */
/*   Updated: 2020/11/13 10:48:27 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

int     ft_atoi(const char *nptr);
int     ft_isprint(int c);
void    ft_putstr(char const *s);
char    *ft_strncat(char *dest, const char *src, size_t n);
int     ft_toupper(int c);
int     ft_isalnum(int c);
char    *ft_itoa(int n);
char    *ft_strcat(char *dest, const char *src);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
int     ft_isalpha(int c);
void    ft_putchar(char c);
int     ft_strcmp(const char *s1, const char *s2);
char    *ft_strncpy(char *dest, const char *src, size_t n);
int     ft_isascii(int c);
void    ft_putendl(char const *s);
char    *ft_strcpy(char *dest, const char *src);
char    *ft_strstr(const char *haystack, const char *needle);
int     ft_isdigit(int c);
void    ft_putnbr(int n);
size_t  ft_strlen(const char *s);
int     ft_tolower(int c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif
