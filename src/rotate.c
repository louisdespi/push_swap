/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 16:45:55 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/09/20 16:26:57 by cvan-bee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stack(t_list **lst)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (*lst && (*lst)->next)
	{
		tmp1 = *lst;
		*lst = (*lst)->next;
		tmp1->next = NULL;
		tmp2 = *lst;
		while (tmp2->next)
			tmp2 = tmp2->next;
		tmp2->next = tmp1;
	}
}

static void	rev_rotate_stack(t_list **lst)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (*lst && (*lst)->next)
	{
		tmp1 = *lst;
		while (tmp1->next->next)
			tmp1 = tmp1->next;
		tmp2 = tmp1->next;
		tmp1->next = NULL;
		tmp2->next = *lst;
		*lst = tmp2;
	}
}

int			rotate(char *line, t_list **lsta, t_list **lstb)
{
	if (ft_strequ(line, "ra"))
		rotate_stack(lsta);
	else if (ft_strequ(line, "rb"))
		rotate_stack(lstb);
	else if (ft_strequ(line, "rr"))
	{
		rotate_stack(lsta);
		rotate_stack(lstb);
	}
	else if (ft_strequ(line, "rra"))
		rev_rotate_stack(lsta);
	else if (ft_strequ(line, "rrb"))
		rev_rotate_stack(lstb);
	else if (ft_strequ(line, "rrr"))
	{
		rev_rotate_stack(lsta);
		rev_rotate_stack(lstb);
	}
	else
		return (-1);
	return (1);
}
