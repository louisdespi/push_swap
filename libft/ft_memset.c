/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 19:29:18 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/06/15 13:42:16 by cvan-bee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			index;
	unsigned char	*d;

	d = (unsigned char*)b;
	index = 0;
	while (index < len)
	{
		d[index] = (unsigned char)c;
		index++;
	}
	return (b);
}
