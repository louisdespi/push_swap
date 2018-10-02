/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_do_action.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 16:14:51 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/10/02 21:14:15 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_do_action(char *instr, t_list **lsta, t_list **lstb,
		int (*f)(char*, t_list**, t_list**), int *i)
{
	if (i)
	{
		//ft_printf("\033[2m%d\033[0m ", *i);
		(*i)++;
	}
	(*f)(instr, lsta, lstb);
	ps_print_list(*lsta, A_COLOR);
	ps_print_list(*lstb, B_COLOR);
	usleep(200000);
	system("clear");
	//ft_putendl(instr);
	/*if (options & 1)
	{
		ps_print_list(*lsta);
		ps_print_list(*lstb);
	}*/
}
