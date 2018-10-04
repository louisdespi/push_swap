/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 18:56:53 by lode-spi          #+#    #+#             */
/*   Updated: 2018/10/04 02:48:51 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	divide_screen(t_mlx mlx)
{
	int		i;

	i = 0;
	while (i < WIN_WIDTH)
	{
		mlx.img.data[i * WIN_WIDTH + WIN_WIDTH / 2] = 0x00FFFFFF;
		i++;
	}
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

int		get_big_value(t_list *lst)
{
	int		max;

	max = *((int*)lst->content);
	while (lst)
	{
		if (max < *((int*)lst->content))
			max = *((int*)lst->content);
		lst = lst->next;
	}
	return (max);
}

void	draw_pile(t_mlx mlx, t_list *lst, int x, int heigth, int coef,
		int colorcode)
{
	int		curr_y;

	curr_y = 0;
	while (lst)
	{
		draw_line(mlx, x, curr_y, heigth, *((int*)lst->content) * coef, colorcode);
		curr_y += heigth;
		lst = lst->next;
	}
}

int		print_frame(t_params *p)
{
	system("clear");
	if (!is_sorted(p->lsta) || p->lstb)
		ft_putendl("KO");
	else
	{
		ft_putendl("OK");
		exit(0);
	}
	reader(&p->lsta, &p->lstb);
	usleep(5000);
	p->mlx.img.img_ptr = mlx_new_image(p->mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGTH);
	p->mlx.img.data = (int*)mlx_get_data_addr(p->mlx.img.img_ptr, 
			&p->mlx.img.bpp, &p->mlx.img.ll, &p->mlx.img.e);
	divide_screen(p->mlx);
	draw_pile(p->mlx, p->lsta, 0, p->heigth, p->coef, 0x1000ff00);
	draw_pile(p->mlx, p->lstb, WIN_WIDTH / 2, p->heigth, p->coef, 0x10ff0000);
	mlx_put_image_to_window(p->mlx.mlx_ptr, p->mlx.win_ptr,
			p->mlx.img.img_ptr, 0, 0);
	mlx_destroy_image(p->mlx.mlx_ptr, p->mlx.img.img_ptr);
	return (0);
}
