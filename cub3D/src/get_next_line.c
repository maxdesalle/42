/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 09:35:06 by mdesalle          #+#    #+#             */
/*   Updated: 2021/01/29 09:14:54 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
** returns -1 if there was an error in one of the mallocs, returns 0 if the
** read function reached the end of the file (reader == 0) and returns 1 if
** everything is OK.
*/

static int	ft_return(t_list *box)
{
	if (!box->check)
		return (-1);
	else if (!box->reader)
		return (0);
	else
		return (1);
}

/*
** frees the buff and return an error (-1). this function is solely used to
** spare lines in the main get_next_line function.
*/

static int	ft_free(char **buff)
{
	free(*buff);
	return (-1);
}

/*
** if the string isn't valid, return 0. if not, it enters in a loop which
** increments i as long as it hasn't reached the end of the string, or the
** end of a line.
**
** if the option flag is given (if it's equal to 1), the function returns 1
** if it reached the end of line, otherwise it returns 0. if the option flag
** isn't given, it returns the length of the line, or until the end of
** the string.
*/

static int	ft_eol(char *str, int option, int i)
{
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

/*
** if the string isn't valid, its freed, and the function returns NULL.
** otherwise, we allocate the memory needed to store the whole string, minus
** the length of the line + 1 for the \0.
**
** finally, we store the result of ft_strcat_alpha, a modified version of the
** strcat function, in the new newstr string and we return it.
*/

static char	*ft_string(char *str, int len, t_list *box)
{
	char	*newstr;

	if (str[len] == '\0')
	{
		free(str);
		return (NULL);
	}
	if (!(newstr = malloc(sizeof(char) * (ft_strlen(str) - len + 1))))
	{
		free(str);
		box->check = 0;
		return (NULL);
	}
	newstr = ft_strcat_alpha(newstr, str, ++len);
	return (newstr);
}

/*
** We create an array with the str static char, and we give it the size of
** the maximum amount of file descriptors there can be using OPEN_MAX from
** the limits.h library.
**
** if either the file descriptor isn't valid, or the BUFFER_SIZE variable is
** negative, or the line isn't valid, or the memory allocation of buff isn't
** valid, we return an error (-1).
**
** while we don't reach the end of the line, nor read the end of the file,
** if the read function finds an error (-1), we free the buff and return
** an error (-1) using the ft_free function. otherwise, we end the buff with
** a \0 and join the static string with the buff in the static string. if
** this goes wrong, we free the buff and return an error (-1) using the
** ft_free function.
**
** then, we free the buff and if the creation of the line taken from the static
** string goes wrong using the ft_substr function, we return an error (-1).
**
** afterwards, we store the whole string, without the line we just stored in
** the line "table".
**
** finally, if we reach the end of the file (reader == 0), we return 0.
** otherwise we return 1 as everything went well.
*/

int			get_next_line(int fd, char **line)
{
	char		*buff;
	t_list		box;
	static char	*str[OPEN_MAX];

	box.check = 1;
	box.reader = 1;
	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 || !line ||
			(!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1)))))
		return (-1);
	while ((!ft_eol(str[fd], 1, 0)) && box.reader != 0)
	{
		if ((box.reader = read(fd, buff, BUFFER_SIZE)) == -1)
			return (ft_free(&buff));
		buff[box.reader] = '\0';
		if (!(str[fd] = ft_strjoin(str[fd], buff)))
			return (ft_free(&buff));
	}
	free(buff);
	if (!(*line = ft_substr(str[fd], 0, (size_t)ft_eol(str[fd], 0, 0))))
		return (-1);
	if (!(box.reader == 0 && !str[fd]))
		str[fd] = ft_string(str[fd], ft_eol(str[fd], 0, 0), &box);
	return (ft_return(&box));
}
