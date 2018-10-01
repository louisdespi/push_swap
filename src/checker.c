/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 11:18:52 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/09/20 16:26:42 by cvan-bee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_list	*lsta;
	t_list	*lstb;

	lstb = NULL;
	if (argc < 2)
		return (0);
	if (ps_build_list(argv, &lsta) == -1)
	{
		ft_putendl("Error");
		return (1);
	}
	if (reader(&lsta, &lstb) == -1)
	{
		ft_putendl("Error");
		return (1);
	}
	if (!is_sorted(lsta) || lstb)
		ft_putendl("KO");
	else
		ft_putendl("OK");
	return (0);
}
