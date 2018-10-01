/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:53:13 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/09/20 16:27:10 by cvan-bee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_stack(t_list **lst)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (*lst && (*lst)->next)
	{
		tmp1 = (*lst)->next->next;
		tmp2 = *lst;
		*lst = (*lst)->next;
		(*lst)->next = tmp2;
		(*lst)->next->next = tmp1;
	}
}

int			swap(char *line, t_list **lsta, t_list **lstb)
{
	if (ft_strequ(line, "sa"))
		swap_stack(lsta);
	else if (ft_strequ(line, "sb"))
		swap_stack(lstb);
	else if (ft_strequ(line, "ss"))
	{
		swap_stack(lsta);
		swap_stack(lstb);
	}
	else
		return (-1);
	return (1);
}
