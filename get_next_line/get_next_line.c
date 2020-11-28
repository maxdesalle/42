/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:51:59 by mdesalle          #+#    #+#             */
/*   Updated: 2020/11/28 16:43:06 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*next_string(char *str)
{
	int		i;
	int		len;
	char	*newstr;

	i = 0;
	len = 0;
	if (str == 0)
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
	while (str[len])
		newstr[i++] = str[len++];
	newstr[i] = '\0';
	free(str);
	return (newstr);
}

static char	*line_finder(char *str)
{
	int		len;
	char	*newstr;

	len = 0;
	if (str == 0)
		return (0);
	while (str[len] != '\0' && str[len] != '\n')
		len++;
	return (newstr = ft_substr(str, 0, len));
}

static int	endofline_checker(char *str)
{
	int	i;

	i = 0;
	if (str == 0)
		return (1);
	while (str[i] != '\0')
		if (str[i++] == '\n')
			return (0);
	return (1);
}

int			get_next_line(int fd, char **line)
{
	int			reader;
	char		*buff;
	static char	*str;

	reader = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || line == 0)
		return (-1);
	if ((buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))) == 0)
		return (-1);
	while (endofline_checker(str) && reader != 0)
	{
		if ((reader = read(fd, buff, BUFFER_SIZE)) == -1)
		{
			free(buff);
			return (-1);
		}
		buff[reader] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	*line = line_finder(str);
	str = next_string(str);
	if (reader == 0)
		return (0);
	return (1);
}
