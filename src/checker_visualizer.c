/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_visualizer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 00:55:50 by lode-spi          #+#    #+#             */
/*   Updated: 2018/10/06 02:52:06 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	launch_visualizer(t_list *lsta, t_list *lstb)
{
	t_mlx		mlx;
	t_params	p;

	if (ft_lstsize(lsta) > WIN_HEIGTH || get_big_value(lsta) > WIN_WIDTH / 2)
		return ;
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGTH,
					"Checker visualizer");
	p.mlx = mlx;
	p.lsta = lsta;
	p.lstb = lstb;
	p.heigth_coef = WIN_HEIGTH / ft_lstsize(lsta);
	p.width_coef = (WIN_WIDTH / 2) / get_big_value(lsta);
	p.time_coef = INITIAL_REFRESH_COEF;
	p.acc = 0;
	mlx_key_hook(mlx.win_ptr, handle_key, (void*)&p);
	mlx_loop_hook(mlx.mlx_ptr, print_frame, (void*)&p);
	mlx_loop(mlx.mlx_ptr);
}
