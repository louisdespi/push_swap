/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 13:44:39 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/06/15 14:07:23 by cvan-bee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ss;

	ss = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)c == ss[i])
			return ((void*)&ss[i]);
		i++;
	}
	return (NULL);
}
