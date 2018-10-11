/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 11:19:00 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/10/05 03:04:53 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		read_all(t_list **lsta, t_list **lstb)
{
	char	*line;
	int		ret;

	ret = 0;
	while (sget_next_line(0, &line))
	{
		if (*line == 's')
			swap(line, lsta, lstb);
		else if (*line == 'p')
			push(line, lsta, lstb);
		else if (*line == 'r')
			rotate(line, lsta, lstb);
		ret++;
		ft_strdel(&line);
	}
	return (ret);
}

void	read_once(t_list **lsta, t_list **lstb)
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
