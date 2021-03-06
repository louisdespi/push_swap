/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 14:59:31 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/10/06 02:51:22 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <time.h> // TO DELETE
# include <stdio.h> // POUR AFFICHAGE PLUS OPTI A SUPPRIMER
# include "mlx.h"

# define A_COLOR 44
# define B_COLOR 41

# define DEBUG_MODE 1
# define VISUAL_MODE 2
# define NORMAL_MODE 3

# define PS_MODE NORMAL_MODE


//MINILIBX
# define WIN_WIDTH 1200
# define WIN_HEIGTH 600

# define REFRESH_TIME 10000
# define INITIAL_REFRESH_COEF 1

# define A_PCOLOR 0x0000FF
# define A_NCOLOR 0x8080FF
# define B_PCOLOR 0xFF0000
# define B_NCOLOR 0xFF8080

// PENSER A FREE LES LISTES DANS LES 2 MAINS
// CHECKER LEAKS GET_NEXT_LINE !!!!!!

typedef struct	s_func
{
	int		(*func)(char *inst, t_list **lsta, t_list **lstb);
	char	*key;
}				t_func;

typedef struct	s_img
{
	void	*img_ptr;
	int		*data;
	int		ll; //Line length
	int		bpp; //Bits per pixel
	int		e; //Endian
}				t_img;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}				t_mlx;

typedef struct	s_params
{
	t_mlx	mlx;
	t_list	*lsta;
	t_list	*lstb;
	int		heigth_coef;
	int		time_coef;
	int		width_coef;
	int		acc;
}				t_params;

void			ps_print_list(t_list *lst, int colorcode);

int				ps_build_list(char **argv, t_list **lst);

void			read_once(t_list **lsta, t_list **lstb);
int				read_all(t_list **lsta, t_list **lstb);

int				swap(char *line, t_list **lsta, t_list **lstb);
int				push(char *line, t_list **lsta, t_list **lstb);
int				rotate(char *line, t_list **lsta, t_list **lstb);

int				is_sorted(t_list *lsta);
int				ismin(t_list *lst);
int				count_sorted(t_list *lst);
int				index_min(t_list *lst, int *min);
int				index_max(t_list *lst, int *max);

void			print_do_action(char *instr, t_list **lsta, t_list **lstb,
		int (*f)(char*, t_list**, t_list**), int *i);

void			insertion_sort(t_list **lsta, t_list **lstb);
void			sort_sl(t_list **lsta, t_list **lstb);
void			quicksort(t_list **lsta, t_list **lstb, int size_partition, int *i);
int				get_median_partition(t_list *lst, int size_partition);
void			quicksortA(t_list **lsta, t_list **lstb, int size_partition, int *i);
void			quicksortB(t_list **lsta, t_list **lstb, int size_partition, int *i);
int				get_big_value(t_list *lst);

void			hidden_quicksort(int *t, int first, int last);
void			print_table(int *t, size_t size); // TO DELETE

int				build_table(t_list *lst, int **t);
int				get_median(int *t, int first, int last);

void			draw_line(t_mlx mlx, int x, int y, int height, int width,
		int colorcode);
void			draw_pileA(t_mlx mlx, t_list *lst, int height, int coef);
void			draw_pileB(t_mlx mlx, t_list *lst, int height, int coef);
int				print_frame(t_params *p);
int				handle_key(int kc, t_params *p);

void			launch_visualizer(t_list *lsta, t_list *lstb);

#endif
