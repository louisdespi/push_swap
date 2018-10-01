/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qs_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:25:14 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/09/25 20:47:30 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		build_table(t_list *lst, int **t)
{
	int		size;
	int		i;

	size = ft_lstsize(lst);
	if (!(*t = (int*)malloc(sizeof(**t) * size)))
		return (-1);
	i = 0;
	while (i < size)
	{
		(*t)[i] = *((int*)lst->content);
		lst = lst->next;
		i++;
	}
	return (size);
}

int		get_median(int *t, int first, int last)
{
	return (t[(last - first) / 2 + first]);
}
