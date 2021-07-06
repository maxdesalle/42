/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 09:58:44 by mdesalle          #+#    #+#             */
/*   Updated: 2021/07/06 14:06:43 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ss(t_node **a_head, t_node **b_head, int a_len, int b_len)
{
	sa(a_head, a_len);
	sb(b_head, b_len);
}
