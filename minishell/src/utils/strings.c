/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 11:45:12 by maxdesall         #+#    #+#             */
/*   Updated: 2021/09/29 11:39:40 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	starts_with(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i += 1;
	if (s1[i] == '\0')
		return (i + 1);
	return (0);
}

void	str_replace(char **dst, char *src)
{
	if (!src)
		return ;
	if (*dst)
		free(*dst);
	*dst = ft_strdup(src);
	if (!*dst)
		malloxit();
	free(src);
}

void	swap_file(t_shell *s, char **file, char **arg, int i)
{
	int	fd;

	if (*file)
	{
		fd = open(*file, O_CREAT | O_RDWR, 0644);
		if (fd < 0)
			ft_exit(s, "File not created");
		free(*file);
	}
	*file = ft_strdup(arg[i]);
	if (!*file)
		malloxit();
}

/*
* doublequote or backslash
*/

static int	db_or_bs(char c)
{
	return (c == DOUBLEQTS || c == BACKSLASH);
}

int	valid_dbquote(char *s, int j, int Q)
{
	return ((db_or_bs(s[j]) && s[j - 1] == BACKSLASH)
		|| (s[j] == BACKSLASH && !db_or_bs(s[j + 1]))
		|| !(s[j] == Q || s[j] == BACKSLASH));
}
