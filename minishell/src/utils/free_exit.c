/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneve <gneve@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 17:36:31 by mlazzare          #+#    #+#             */
/*   Updated: 2021/09/26 14:32:36 by gneve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	malloxit(void)
{
	ft_putstr_fd("minishell: memory allocation failed\n", STDERR);
	exit(EXIT_FAILURE);
}

void	ft_free(char *s)
{
	if (s)
		free(s);
	s = NULL;
}

void	free_arr(char **array)
{
	int	i;

	i = 0;
	while (array && array[i])
		free(array[i++]);
	if (array)
		free(array);
	array = 0;
}

void	free_struct(t_shell *s)
{
	free_arr(s->cmd);
	free_arr(s->path);
	free_arr(s->arg);
	free_arr(s->minienv);
	if (s->file.stopword)
		free(s->file.stopword);
	if (s->file.infile)
		free(s->file.infile);
	if (s->file.outfile)
		free(s->file.outfile);
	rl_clear_history();
}

int	ft_exit(t_shell *shell, char *err)
{
	perror(err);
	free_struct(shell);
	exit(EXIT_SUCCESS);
}
