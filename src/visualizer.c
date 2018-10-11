/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 18:56:53 by lode-spi          #+#    #+#             */
/*   Updated: 2018/10/06 03:02:58 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int		get_big_value(t_list *lst)
{
	int		max;
	int		curr;

	max = ft_abs(*((int*)lst->content));
	while (lst)
	{
		curr = ft_abs(*((int*)lst->content));
		if (max < curr)
			max = curr;
		lst = lst->next;
	}
	return (max);
}


void	draw_line(t_mlx mlx, int x, int y, int height, int width, int colorcode)
{
	int		curr_x;
	int		curr_y;
	int		i;
	int		j;

	curr_y = y;
	i = 0;
	while (i < height)
	{
		j = 0;
		curr_x = x;
		while (j < width)
		{
			mlx.img.data[curr_y * WIN_WIDTH + curr_x] = colorcode;
			curr_x++;
			j++;
		}
		curr_y++;
		i++;
	}
}

void	draw_pileA(t_mlx mlx, t_list *lst, int heigth, int coef)
{
	int		curr_y;
	int		curr_val;

	curr_y = 0;
	while (lst)
	{
		curr_val = *((int*)lst->content);
		if (curr_val >= 0)
			draw_line(mlx, 0, curr_y, heigth, curr_val * coef, A_PCOLOR);
		else
			draw_line(mlx, 0, curr_y, heigth, ft_abs(curr_val) * coef, A_NCOLOR);
		curr_y += heigth;
		lst = lst->next;
	}
}

void	draw_pileB(t_mlx mlx, t_list *lst, int heigth, int coef)
{
	int		curr_y;
	int		curr_val;

	curr_y = 0;
	while (lst)
	{
		curr_val = *((int*)lst->content);
		if (curr_val >= 0)
			draw_line(mlx, WIN_WIDTH / 2, curr_y, heigth, curr_val * coef,
							B_PCOLOR);
		else
			draw_line(mlx, WIN_WIDTH / 2, curr_y, heigth, ft_abs(curr_val) * coef,
							B_NCOLOR);
		curr_y += heigth;
		lst = lst->next;
	}
}

int		handle_key(int kc, t_params *p)
{
	if (kc == 125)
	{
		if (p->time_coef > 7)
			return (0);
		p->time_coef++;
		mlx_loop_hook(p->mlx.mlx_ptr, print_frame, (void*)p);
	}
	else if (kc == 126)
	{
		if (p->time_coef < 1)
			return (0);
		p->time_coef--;
		mlx_loop_hook(p->mlx.mlx_ptr, print_frame, (void*)p);
	}
	else if (kc == 53)
		exit(0);
	else if (kc == 49)
	{
		mlx_loop_hook(p->mlx.mlx_ptr, NULL, NULL);
		read_all(&p->lsta, &p->lstb);
		print_frame((void*)p);
		if (is_sorted(p->lsta))
			ft_putendl("OK");
		else
			ft_putendl("KO");
	}
	return (0);
}

int		print_frame(t_params *p)
{
	system("clear");
	/*if (!is_sorted(p->lsta) || p->lstb)
		ft_putendl("KO");
	else
	{
		ft_putendl("OK");
		mlx_loop_hook(p->mlx.mlx_ptr, NULL, NULL);
	}*/
	ft_printf("%d\n", p->acc);
	p->acc++;
	p->mlx.img.img_ptr = mlx_new_image(p->mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGTH);
	p->mlx.img.data = (int*)mlx_get_data_addr(p->mlx.img.img_ptr, 
			&p->mlx.img.bpp, &p->mlx.img.ll, &p->mlx.img.e);
	draw_pileA(p->mlx, p->lsta, p->heigth_coef, p->width_coef);
	draw_pileB(p->mlx, p->lstb, p->heigth_coef, p->width_coef);
	mlx_put_image_to_window(p->mlx.mlx_ptr, p->mlx.win_ptr,
			p->mlx.img.img_ptr, 0, 0);
	read_once(&p->lsta, &p->lstb);
	usleep(REFRESH_TIME * p->time_coef);
	mlx_destroy_image(p->mlx.mlx_ptr, p->mlx.img.img_ptr);
	return (0);
}
