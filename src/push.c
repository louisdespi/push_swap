/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 16:18:59 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/09/20 16:26:26 by cvan-bee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_stack(t_list **lsta, t_list **lstb)
{
	t_list	*tmp;

	if (*lsta)
	{
		tmp = *lsta;
		*lsta = (*lsta)->next;
		tmp->next = NULL;
		ft_lstadd(lstb, tmp);
	}
}

int			push(char *line, t_list **lsta, t_list **lstb)
{
	if (ft_strequ(line, "pa"))
		push_stack(lstb, lsta);
	else if (ft_strequ(line, "pb"))
		push_stack(lsta, lstb);
	else
		return (-1);
	return (1);
}
