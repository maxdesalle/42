/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 09:35:06 by mdesalle          #+#    #+#             */
/*   Updated: 2020/12/08 09:35:31 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

static char	*ft_string(char *str)
{
	int		i;
	int		len;
	char	*newstr;

	i = 0;
	len = 0;
	if (str == NULL)
		return (0);
	while (str[len] != '\0' && str[len] != '\n')
		len++;
	if (str[len] == '\0')
	{
		free(str);
		return (0);
	}
	if (!(newstr = malloc(sizeof(char) * (ft_strlen(str) - len + 1))))
		return (0);
	len += 1;
	while (str[len] != '\0')
		newstr[i++] = str[len++];
	newstr[i] = '\0';
	free(str);
	return (newstr);
}

static char	*ft_line(char *str)
{
	int		len;
	char	*newstr;

	len = 0;
	if (str == NULL)
		return (0);
	while (str[len] != '\0' && str[len] != '\n')
		len++;
	return (newstr = ft_substr(str, 0, len));
}

static int	ft_eol(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (1);
	while (str[i] != '\0')
		if (str[i++] == '\n')
			return (0);
	return (1);
}

int			get_next_line(int fd, char **line)
{
	int			reader;
	char		buff[BUFFER_SIZE + 1];
	static char	*str;

	reader = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || line == NULL)
		return (-1);
	while (ft_eol(str) && reader != 0)
	{
		if ((reader = read(fd, buff, BUFFER_SIZE)) == -1)
			return (-1);
		buff[reader] = '\0';
		str = ft_strjoin(str, buff);
	}
	*line = ft_line(str);
	str = ft_string(str);
	if (reader == 0)
		return (0);
	return (1);
}