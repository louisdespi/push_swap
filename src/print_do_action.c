/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_do_action.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 16:14:51 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/10/03 01:53:53 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_do_action(char *instr, t_list **lsta, t_list **lstb,
		int (*f)(char*, t_list**, t_list**), int *i)
{
	if (i)
	{
		if (PS_MODE == DEBUG_MODE)
			ft_printf("\033[2m%d\033[0m ", *i);
		(*i)++;
	}
	(*f)(instr, lsta, lstb);
	if (PS_MODE == VISUAL_MODE)
	{
		ps_print_list(*lsta, A_COLOR);
		ps_print_list(*lstb, B_COLOR);
		usleep(50000);
		system("clear");
	}
	else
		ft_putendl(instr);
	/*if (options & 1)
	{
		ps_print_list(*lsta);
		ps_print_list(*lstb);
	}*/
}
