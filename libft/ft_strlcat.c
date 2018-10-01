/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 16:13:37 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/06/22 17:50:03 by cvan-bee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size <= dstlen)
		return (size + srclen);
	size = size - (dstlen + 1);
	i = 0;
	while ((size > 0) && (src[i]))
	{
		dst[dstlen + i] = src[i];
		i++;
		size--;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}
