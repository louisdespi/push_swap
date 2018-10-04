/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 13:56:39 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/10/04 02:51:09 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_index(t_list *lst, int n)
{
	int		curr;
	int		i;

	i = 0;
	while (lst)
	{
		curr = *((int*)lst->content);
		if (curr == n)
			return (i);
		lst = lst->next;
		i++;
	}
	return (-1);
}

int		remaining_smaller_value(t_list *lst, int n)
{
	int		curr;
	int		i;

	i = 0;
	while (lst)
	{
		curr = *((int*)lst->content);
		if (curr <= n)
			i++;
		lst = lst->next;
	}
	return (i);
}

int		remaining_bigger_value(t_list *lst, int n)
{
	int		curr;
	int		i;

	i = 0;
	while (lst)
	{
		curr = *((int*)lst->content);
		if (curr >= n)
			i++;
		lst = lst->next;
	}
	return (i);
}

int		get_index_array(int *t, int v, size_t size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (t[i] == v)
			return (i);
		i++;
	}
	return (-1);
}

void		get_max_partition(t_list *lst, int size_partition, int *max)
{
	int		i;

	i = 0;
	*max = 0;
	if (!lst)
		return ; 
	*max = *((int*)lst->content);
	while (lst && i < size_partition)
	{
		if (*max < *((int*)lst->content))
			*max = *((int*)lst->content);
		i++;
		lst = lst->next;
	}
}

void		get_min_partition(t_list *lst, int size_partition, int *min)
{
	int		i;

	i = 0;
	*min = 0;
	if (!lst)
		return ;
	*min = *((int*)lst->content);
	while (lst && i < size_partition)
	{
		if (*min > *((int*)lst->content))
			*min = *((int*)lst->content);
		i++;
		lst = lst->next;
	}
}

int		get_median_partition(t_list *lst, int size_partition)
{
	int		min;
	int		max;
	int		*t;
	int		size;
	int		median;

	size = build_table(lst, &t); //penser au pattern singleton
	hidden_quicksort(t, 0, size - 1);
	get_max_partition(lst, size_partition, &max);
	get_min_partition(lst, size_partition, &min);
	median = get_median(t, get_index_array(t, min, size), get_index_array(t, max, size));
	return (median);
}

void	partitionningA(t_list **lsta, t_list **lstb, int size_partition, int *i)
{
	int		curr_median;
	int		curr_value;
	int		vbool;
	int		counter;

	vbool = 0;
	counter = 0;
	curr_median = get_median_partition(*lsta, size_partition);
	if (PS_MODE == DEBUG_MODE)
	{
		ft_printf("\033[4;32m--------------Partitionning A--------------\033[0m\n");
		ft_printf("Partition size : \033[1;31m%d\033[0m\n", size_partition);
		ft_printf("Pivot : \033[1;33m%d\033[0m\n", curr_median);
	}
	while (remaining_smaller_value(*lsta, curr_median))
	{
		curr_value = *((int*)(*lsta)->content);
		if (curr_value <= curr_median)
		{
			print_do_action("pb", lsta, lstb, push, i);
			if (curr_value == curr_median)
			{
				if (lstb)
				{
					print_do_action("rb", lsta, lstb, rotate, i);
					vbool = 1;
				}
			}
		}
		else
		{
			counter++;
			print_do_action("ra", lsta, lstb, rotate, i);
		}
	}
	if (vbool)
	{
		print_do_action("rrb", lsta, lstb, rotate, i);
		vbool = 0;
	}
	while (counter--)
	{
		print_do_action("rra", lsta, lstb, rotate, i);
	}
	if (PS_MODE == DEBUG_MODE)
		ft_printf("\033[4;32m------------End Partitionning A------------\033[0m\n\n");
}

void	partitionningB(t_list **lsta, t_list **lstb, int size_partition, int *i)
{
	int		curr_median;
	int		curr_value;
	int		vbool;
	int		counter;

	vbool = 0;
	counter = 0;
	curr_median = get_median_partition(*lstb, size_partition);
	if (PS_MODE == DEBUG_MODE)
	{
		ft_printf("\033[4;35m--------------Partitionning B--------------\033[0m\n");
		ft_printf("Partition size : \033[1;31m%d\033[0m\n", size_partition);
		ft_printf("Pivot : \033[1;33m%d\033[0m\n", curr_median);
	}
	while (remaining_bigger_value(*lstb, curr_median))
	{
		curr_value = *((int*)(*lstb)->content);
		if (curr_value >= curr_median)
		{
			print_do_action("pa", lsta, lstb, push, i);
			if (curr_value == curr_median)
			{
				if (lsta)
				{
					print_do_action("ra", lsta, lstb, rotate, i);
					vbool = 1;
				}
			}
		}
		else
		{
			counter++;
			print_do_action("rb", lsta, lstb, rotate, i);
		}
	}
	if (vbool)
	{
		print_do_action("rra", lsta, lstb, rotate, i);
		vbool = 0;
	}
	while (counter--)
	{
		print_do_action("rrb", lsta, lstb, rotate, i);
	}
	if (PS_MODE == DEBUG_MODE)
		ft_printf("\033[4;35m------------End Partitionning B------------\033[0m\n\n");
}

void	quicksortB(t_list **lsta, t_list **lstb, int size_partition, int *i)
{
	int		p;

	p = size_partition;
	if (size_partition == 2)
	{
		if (*((int*)(*lstb)->content) < *((int*)(*lstb)->next->content))
			print_do_action("sb", lsta, lstb, swap, i);
		print_do_action("pa", lsta, lstb, push, i);
		print_do_action("pa", lsta, lstb, push, i);
		return ;
	}
	if (size_partition > 0)
	{
		partitionningB(lsta, lstb, p, i);
		print_do_action("pb", lsta, lstb, push, i);
		quicksortA(lsta, lstb, p / 2, i);
		print_do_action("pa", lsta, lstb, push, i);
		p = (p - 1) / 2;
		quicksortB(lsta, lstb, p, i);
	}
}

void	quicksortA(t_list **lsta, t_list **lstb, int size_partition, int *i)
{
	int		p;

	p = size_partition;
	if (size_partition > 0)
	{
		partitionningA(lsta, lstb, p, i);
		quicksortA(lsta, lstb, p / 2, i);
		print_do_action("pa", lsta, lstb, push, i);
		p = (p - 1) / 2;
		quicksortB(lsta, lstb, p, i);
	}
}

/*void	quicksort(t_list **lsta, t_list **lstb, int size_partition, int *i)
  {
  int		p;

  if (PS_MODE == DEBUG_MODE)
  {
  ps_print_list(*lsta, A_COLOR);
  ps_print_list(*lstb, B_COLOR);
  }
  if (size_partition > 0)
  {
  p = partitionningA(lsta, lstb, size_partition, i);
  quicksort(lsta, lstb, size_partition - p, i);
  print_do_action("pa", lsta, lstb, push, i);
  size_partition--;
  if (size_partition > 0)
  {
  p = partitionningB(lsta, lstb, size_partition, i);
  quicksort(lsta, lstb, size_partition - p, i);
  }
  }
  }*/

/*static void	sort_three(t_list **lsta, t_list **lstb)
  {
  int		i;
  int		csorted;
  int		size;
  int		max;

  i = index_max(*lsta, &max);
  size = ft_lstsize(*lsta);
  csorted = count_sorted(*lsta);
  if (csorted != size && size == 3)
  {
  if (i == 1)
  print_do_action("rra", lsta, lstb, rotate);
  else if (i == 0)
  print_do_action("ra", lsta, lstb, rotate);
  csorted = count_sorted(*lsta);
  }
  if (csorted != size && size >= 2)
  {
  if (*((int*)(*lsta)->content) > *((int*)(*lsta)->next->content))
  print_do_action("sa", lsta, lstb, swap);
  }
  }

  void	sort_sl(t_list **lsta, t_list **lstb)
  {
  int		csorted;
  int		initial_size;
  int		csortedb;

  initial_size = ft_lstsize(*lsta);
  csorted = count_sorted(*lsta);
  csortedb = 0;
  while (csorted != initial_size && ft_lstsize(*lsta) > 3)
  {
  if (*((int*)(*lsta)->content) > *((int*)(*lsta)->next->content))
  print_do_action("sa", lsta, lstb, swap);
  else if (ismin(*lsta))
  {
  print_do_action("pb", lsta, lstb, push);
  csortedb++;
  }
  else
  print_do_action("rra", lsta, lstb, rotate);
  csorted = count_sorted(*lsta) + csortedb;
  }
  sort_three(lsta, lstb);
  while (*lstb)
  print_do_action("pa", lsta, lstb, push);
  }

  void		insertion_sort(t_list **lsta, t_list **lstb)
  {
  int		initial_size;
  int		csorted;
  int		i;
  int		min;
  int		size;

  csorted = count_sorted(*lsta);
  initial_size = ft_lstsize(*lsta);
  while ((size = ft_lstsize(*lsta)) > 3 && initial_size != csorted)
  {
  i = index_min(*lsta, &min);
  if (i <= size / 2)
  {
  while (*((int*)(*lsta)->content) != min)
  print_do_action("ra", lsta, lstb, rotate);
  }
  else
{
	while (*((int*)(*lsta)->content) != min)
		print_do_action("rra", lsta, lstb, rotate);
}
print_do_action("pb", lsta, lstb, push);
}
sort_three(lsta, lstb);
while (*lstb)
	print_do_action("pa", lsta, lstb, push);
	}*/

/*static void	merge(t_list **lsta, t_list **lstb)
  {
  while (*lsta && (*lsta)->next && *((int*)(*lsta)->content) >
 *((int*)(*lsta)->next->content))
 {
 if (*lstb && (*lstb)->next && *((int*)(*lstb)->content) <
 *((int*)(*lstb)->next->content))
 print_do_action("ss", lsta, lstb, swap);
 else
 print_do_action("sa", lsta, lstb, swap);
 if ((*lsta)->next->next && *((int*)(*lsta)->next->content) >
 *((int*)(*lsta)->next->next->content))
 print_do_action("pb", lsta, lstb, push);
 }
 }

 static void	merge_rev(t_list **lsta, t_list **lstb)
 {
 while (*lstb)
 {
//if (b < b->next)
//	sb
print_do_action("pa", lsta, lstb, push);
if (*((int*)(*lsta)->content) > *((int*)(*lsta)->next->content))
print_do_action("sa", lsta, lstb, swap);
}
}

void	sort_sl2(t_list **lsta, t_list **lstb)
{
int		initial_size;
int		csorted;

csorted = count_sorted(*lsta);
initial_size = ft_lstsize(*lsta);
while (csorted < initial_size)
{
if (ismin(*lsta))
print_do_action("pb", lsta, lstb, push);
if (*((int*)(*lsta)->content) > *((int*)(*lsta)->next->content))
{
merge(lsta, lstb);
merge_rev(lsta, lstb);
csorted = count_sorted(*lsta);
}
else
{
print_do_action("rra", lsta, lstb, rotate);
csorted = count_sorted(*lsta);
}
}
//csorted doit compter juste si la liste est trie mais que le plus petit
//pas au dessus
}

#include <stdio.h> //TODEL

void	sort_sl3(t_list **lsta, t_list **lstb)
{
int		initial_size;
int		csorted;

csorted = count_sorted(*lsta);
initial_size = ft_lstsize(*lsta);
while (csorted < initial_size)
{
//if (ismin(*lsta))
//	print_do_action("pb", lsta, lstb, push);
while (ft_lstsize(*lsta) > 4)
{
if (*((int*)(*lsta)->content) > *((int*)(*lsta)->next->content) ||
(*lstb && (*lstb)->next &&
 *((int*)(*lstb)->content) < *((int*)(*lstb)->next->content)))
{
	if (*((int*)(*lsta)->content) > *((int*)(*lsta)->next->content) &&
			(*lstb && (*lstb)->next &&
			 *((int*)(*lstb)->content) < *((int*)(*lstb)->next->content)))
		print_do_action("ss", lsta, lstb, swap);
	else if (*((int*)(*lsta)->content) > *((int*)(*lsta)->next->content))
		print_do_action("sa", lsta, lstb, swap);
	else
	{
		//ps_print_list(*lstb);
		//ps_print_list(*lsta);
		//printf("boucle infinie NOOB\n");
		print_do_action("sb", lsta, lstb, swap);
	}
}
else
print_do_action("pb", lsta, lstb, push);
}
while (*lstb)
{
	if (((*lstb)->next && *((int*)(*lstb)->content) <
				*((int*)(*lstb)->next->content)) ||
			*((int*)(*lsta)->content) >
			*((int*)(*lsta)->next->content))
	{
		if (((*lstb)->next && *((int*)(*lstb)->content) <
					*((int*)(*lstb)->next->content)) &&
				*((int*)(*lsta)->content) >
				*((int*)(*lsta)->next->content))
			print_do_action("ss", lsta, lstb, swap);
		else if (*((int*)(*lsta)->content) > *((int*)(*lsta)->next->content))
			print_do_action("sa", lsta, lstb, swap);
		else
			print_do_action("sb", lsta, lstb, swap);
	}
	print_do_action("pa", lsta, lstb, push);
}
if (*((int*)(*lsta)->content) > *((int*)(*lsta)->next->content))
	print_do_action("sa", lsta, lstb, swap);
	csorted = count_sorted(*lsta);
	}
}*/
