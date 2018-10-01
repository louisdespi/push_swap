/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 14:43:53 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/09/25 17:58:05 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		count_sorted(t_list *lst)
{
	int		i;

	i = 1;
	if (ft_lstsize(lst) < 2)
		return (ft_lstsize(lst));
	while (lst->next && *((int*)lst->content) < *((int*)lst->next->content))
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int		ismin(t_list *lst)
{
	int		first;

	if (!lst)
		return (0);
	first = *((int*)lst->content);
	while (lst->next)
	{
		lst = lst->next;
		if (*((int*)lst->content) < first)
			return (0);
	}
	return (1);
}

int		index_min(t_list *lst, int *min)
{
	int		i;
	int		j;

	j = 1;
	i = -1;
	if (lst)
	{
		*min = *((int*)lst->content);
		lst = lst->next;
		i++;
	}
	while (lst)
	{
		if (*min > *((int*)lst->content))
		{
			*min = *((int*)lst->content);
			i = j;
		}
		lst = lst->next;
		j++;
	}
	return (i);
}

int		index_max(t_list *lst, int *max)
{
	int		i;
	int		j;

	j = 1;
	i = -1;
	if (lst)
	{
		*max = *((int*)lst->content);
		lst = lst->next;
		i++;
	}
	while (lst)
	{
		if (*max < *((int*)lst->content))
		{
			*max = *((int*)lst->content);
			i = j;
		}
		lst = lst->next;
		j++;
	}
	return (i);
}

/*int		count_sorted2(t_list *lst)
{
	int		i;
	int		j;

	i = 1;
	if (ft_lstsize(lst) < 2)
		return (ft_lstsize(lst));
	while (lst->next)
	{
		while (*((int*)lst->content < *((int*)lst->next->content)))
		{
			i++;
			lst = lst->next;
		}
		j = 1;
		while (*((int*)lst->content >
	}
}*/
