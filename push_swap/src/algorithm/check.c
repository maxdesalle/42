/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 16:44:16 by mdesalle          #+#    #+#             */
/*   Updated: 2021/07/13 17:22:44 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	sec_smaller(t_node *a_head, t_node *b_head)
{
	int	a_high;
	int	a_sec_high;
	int	b_high;

	a_high = highest(a_head);
	a_sec_high = sec_highest(a_head);
	b_high = highest(b_head);
	if (b_head->value == b_high && a_head->value == a_high && b_high < a_high
		&& a_sec_high < b_high)
		return (1);
	return (0);
}
