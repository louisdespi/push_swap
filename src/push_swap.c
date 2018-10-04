/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 12:13:58 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/10/03 23:29:54 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_list	*lsta;
	t_list	*lstb;
	//char	options;
	int		acc;

	acc = 0;
	//options = 0;
	lstb = NULL;
	if (argc < 2)
		return (1);
	//options = check_options(argv);
	//afficher etat des listes a chaque coup, forcer un algo de tri different, 
	//imprimer les instructions dans un fichier afficher le nbr d op	
	if (ps_build_list(argv, &lsta) == -1)
	{
		ft_putendl("Error");
		return (1);
	}
	//if (argc - 1 <= 10)
		//insertion_sort(&lsta, &lstb);
	//else
	//{
		quicksortA(&lsta, &lstb, ft_lstsize(lsta), &acc);
		if (PS_MODE == DEBUG_MODE)
		{
			ft_printf("END OF SORTING\n");
			ft_printf("\033[4mList A\033[0m\n");
			ps_print_list(lsta, A_COLOR);
			ft_printf("\033[4mList B\033[0m\n");
			ps_print_list(lstb, B_COLOR);
			ft_printf("Total instruction : %d\n", acc);
		}
	//}
	return (0);
}
