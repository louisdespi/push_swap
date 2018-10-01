/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 13:33:57 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/06/21 15:06:10 by cvan-bee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	long			i;
	unsigned char	*cdst;
	unsigned char	*csrc;

	cdst = (unsigned char*)dst;
	csrc = (unsigned char*)src;
	if (src >= dst)
		ft_memcpy(dst, src, len);
	else
	{
		i = (long)len - 1;
		while (i >= 0)
		{
			cdst[i] = csrc[i];
			i--;
		}
	}
	return (dst);
}
