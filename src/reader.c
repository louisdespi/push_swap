/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 11:19:00 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/10/03 22:33:22 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reader(t_list **lsta, t_list **lstb)
{
	char	*line;

	if (sget_next_line(0, &line) > 0)
	{
		if (*line == 's')
			swap(line, lsta, lstb);
		else if (*line == 'p')
			push(line, lsta, lstb);
		else if (*line == 'r')
			rotate(line, lsta, lstb);
		ft_strdel(&line);
	}
}
