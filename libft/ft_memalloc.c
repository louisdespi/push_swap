/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 17:49:52 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/06/15 13:41:32 by cvan-bee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void			*ret;
	unsigned char	*c;
	size_t			i;

	if ((ret = malloc(size)))
	{
		c = (unsigned char*)ret;
		i = 0;
		while (i < size)
		{
			c[i] = 0;
			i++;
		}
	}
	return (ret);
}
