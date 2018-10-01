/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 17:14:10 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/09/18 10:26:37 by cvan-bee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted(t_list *lsta)
{
	if (lsta)
	{
		while (lsta->next)
		{
			if (*((int*)(lsta->content)) > *((int*)(lsta->next->content)))
				return (0);
			lsta = lsta->next;
		}
	}
	return (1);
}
