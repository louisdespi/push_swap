/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 14:59:31 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/10/03 01:58:35 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <time.h> // TO DELETE
# include <stdio.h> // POUR AFFICHAGE PLUS OPTI A SUPPRIMER

# define A_COLOR 44
# define B_COLOR 41

# define DEBUG_MODE 1
# define VISUAL_MODE 2
# define NORMAL_MODE 3

# define PS_MODE VISUAL_MODE

// PENSER A FREE LES LISTES DANS LES 2 MAINS
// CHECKER LEAKS GET_NEXT_LINE !!!!!!

typedef struct	s_func
{
	int		(*func)(char *inst, t_list **lsta, t_list **lstb);
	char	*key;
}				t_func;

void			ps_print_list(t_list *lst, int colorcode);

int				ps_build_list(char **argv, t_list **lst);
int				reader(t_list **lsta, t_list **lstb);
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

void			hidden_quicksort(int *t, int first, int last);
void			print_table(int *t, size_t size); // TO DELETE

int				build_table(t_list *lst, int **t);
int				get_median(int *t, int first, int last);

#endif
