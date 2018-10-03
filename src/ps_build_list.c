/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_build_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 11:19:07 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/10/03 01:52:06 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ps_print_list(t_list *lst, int colorcode)
{
	int		*curr;

	if (!lst)
		ft_putstr("(empty)\n");
	while (lst)
	{
		curr = (int*)lst->content;
		if (PS_MODE == VISUAL_MODE)
			printf("\033[%dm%*d\033[0m\n", colorcode, *curr, *curr);
		else if (PS_MODE == DEBUG_MODE)
		{
			ft_printf("%d", *curr);
			if (lst->next)
				ft_printf("|");
		}
		lst = lst->next;
	}
	ft_printf("\n");
}

static int	catoi(char *arg, int *addr)
{
	long	n;
	long	sign;

	sign = 1;
	n = 0;
	if (*arg == '-' && arg[1])
	{
		sign = -1;
		arg++;
	}
	while (*arg)
	{
		if (!ft_isdigit(*arg))
			return (-1);
		n = n * 10 + *arg - 48;
		arg++;
	}
	n *= sign;
	if (n != (long)(int)n)
		return (-1);
	*addr = (int)n;
	return (1);
}

static int	check_doubloons(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst->next;
		while (tmp)
		{
			if (*((int*)tmp->content) == *((int*)lst->content))
				return (-1);
			tmp = tmp->next;
		}
		lst = lst->next;
	}
	return (1);
}

int			ps_build_list(char **argv, t_list **lst)
{
	t_list	*elt;
	int		curr_v;

	*lst = NULL;
	while (*(++argv))
	{
		if (catoi(*argv, &curr_v) == -1)
			return (-1);
		if (!(elt = ft_lstnew(&curr_v, sizeof(curr_v))))
			return (-1);
		ft_lstaddback(lst, elt);
	}
	return (check_doubloons(*lst));
}
