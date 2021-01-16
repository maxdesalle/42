/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 09:35:06 by mdesalle          #+#    #+#             */
/*   Updated: 2021/01/16 11:28:31 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

static int	ft_eol(char *str, int option, int i)
{
	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (option == 1)
	{
		if (str[i] == '\n')
			return (1);
		return (0);
	}
	return (i);
}

static char	*ft_string(char *str, int len)
{
	char	*newstr;

	if (str[len] == '\0')
	{
		free(str);
		return (NULL);
	}
	if (!(newstr = malloc(sizeof(char) * (ft_strlen(str) - len + 1))))
		return (NULL);
	newstr = ft_strcat_alpha(newstr, str, ++len);
	return (newstr);
}

int			get_next_line(int fd, char **line)
{
	int			reader;
	char		*buff;
	t_list		box;
	static char	*str;

	reader = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((!ft_eol(str, 1, box.i)) && reader != 0)
	{
		if ((reader = read(fd, buff, BUFFER_SIZE)) == -1)
		{
			free(buff);
			return (-1);
		}
		buff[reader] = '\0';
		if (!(str = ft_strjoin(str, buff)))
			return (-1);
	}
	free(buff);
	box.len = ft_eol(str, 0, box.i);
	*line = ft_substr(str, 0, (size_t)box.len);
	str = ft_string(str, box.len);
	if (reader == 0)
		return (0);
	return (1);
}
