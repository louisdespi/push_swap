/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 11:18:52 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/10/07 18:23:34 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*int		handle_argv(int argc, char **argv)
{
	
}*/

int		main(int argc, char **argv)
{
	t_list		*lsta;
	t_list		*lstb;
	int		total;
	
	lstb = NULL;
	if (argc < 2)
		return (0);
	if (ps_build_list(argv, &lsta) == -1)
	{
		ft_putendl("Error");
		return (1);
	}
	launch_visualizer(lsta, lstb);
	return (0);
}
