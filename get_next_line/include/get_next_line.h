/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:05:40 by mdesalle          #+#    #+#             */
/*   Updated: 2021/04/06 18:49:05 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 32

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int	i;
	int	j;
	int	len;
	int	check;
	int	reader;
}				t_list;

size_t			ft_strlen(const char *s);
void			ft_putchar(char c);
void			ft_putstr(const char *s);
void			ft_putendl(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(t_list *box, char const *s1, char const *s2);
char			*ft_strcat_alpha(char *dest, char *src, int len);
int				get_next_line(int fd, char **line);

#endif
