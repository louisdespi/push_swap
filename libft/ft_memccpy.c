/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 13:44:24 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/06/15 14:02:03 by cvan-bee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*cdst;
	unsigned char	*csrc;
	size_t			i;

	csrc = (unsigned char*)src;
	cdst = (unsigned char*)dst;
	i = 0;
	while (i < n)
	{
		if (csrc[i] == (unsigned char)c)
		{
			cdst[i] = csrc[i];
			return ((void*)&cdst[i + 1]);
		}
		cdst[i] = csrc[i];
		i++;
	}
	return (NULL);
}
