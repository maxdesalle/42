/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 17:48:11 by mlazzare          #+#    #+#             */
/*   Updated: 2021/10/01 10:33:52 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

int		ft_space(char c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isnumber(char *s);
int		ft_isdigit(int c);
int		ft_numlen(long n);
size_t	ft_strlen(const char *s);
size_t	ft_tablen(char **str);
char	*ft_strcat(char *dst, const char *src, int k);
char	*ft_trim(char *s);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_concat(char **arg);
char	*ft_join(char *dst, const char *src);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_splitpath(char *s, char c);
char	**ft_split(char const *s, char c);
void	ft_putstr(char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
void	ft_putstr_fd(char const *s, int fd);
long	ft_atoi(const char *nptr);
char	*ft_itoa(int n);
char	**ft_split_quotes(char const *str);
size_t	ft_intlen(long x);
char	*ft_strchr(const char *s, int c);

#endif
