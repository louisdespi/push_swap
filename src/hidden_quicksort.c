/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidden_quicksort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:09:58 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/09/26 16:56:33 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_table(int *t, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		ft_printf("%d", t[i]);
		if (i + 1 < size)
			ft_printf(" ");
		i++;
	}
	ft_printf("\n");
}

static void	swap_index(int *t, int i, int j)
{
	int		tmp;

	tmp = t[i];
	t[i] = t[j];
	t[j] = tmp;
}

static int		partit(int *t, int first, int last)
{
	int		i;
	int		j;
	int		pivot;

	pivot = t[last];
	i = first - 1;
	j = first;
	while (j <= last - 1)
	{
		if (t[j] <= pivot)
		{
			i++;
			swap_index(t, i, j);
		}
		j++;
	}
	swap_index(t, last, i + 1);
	return (i + 1);
}

void	hidden_quicksort(int *t, int first, int last)
{
	int		pivot;

	if (first < last)
	{
		pivot = partit(t, first, last);
		hidden_quicksort(t, first, pivot - 1);
		hidden_quicksort(t, pivot + 1, last);
	}
}
