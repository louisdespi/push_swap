/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 11:19:00 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/09/24 19:26:09 by cvan-bee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		reader(t_list **lsta, t_list **lstb)
{
	char	*line;
	int		ret;
	int		tmp;

	ret = 0;
	while (sget_next_line(0, &line))
	{
		tmp = ret;
		if (*line == 's')
			ret += swap(line, lsta, lstb);
		else if (*line == 'p')
			ret += push(line, lsta, lstb);
		else if (*line == 'r')
			ret += rotate(line, lsta, lstb);
		ft_strdel(&line);
		if (ret <= tmp)
		{
			ret = -1;
			break ;
		}
	}
	return (ret);
}
