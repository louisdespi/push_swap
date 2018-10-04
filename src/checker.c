/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 11:18:52 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/10/04 01:37:44 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_list		*lsta;
	t_list		*lstb;
	t_mlx		mlx;
	t_params	p;

	lstb = NULL;
	if (argc < 2)
		return (0);
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGTH, "Checker_visualizer");
	if (ps_build_list(argv, &lsta) == -1)
	{
		ft_putendl("Error");
		return (1);
	}
	p.mlx = mlx;
	p.lsta = lsta;
	p.lstb = lstb;
	p.heigth = WIN_HEIGTH / ft_lstsize(lsta);
	p.coef = (WIN_WIDTH / 2) / get_big_value(lsta);
	mlx_loop_hook(mlx.mlx_ptr, print_frame, (void*)&p);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
