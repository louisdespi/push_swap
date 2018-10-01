/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 14:09:09 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/06/21 10:46:37 by cvan-bee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			index;
	unsigned char	*string1;
	unsigned char	*string2;

	string1 = (unsigned char*)s1;
	string2 = (unsigned char*)s2;
	index = 0;
	while (index < n)
	{
		if (string1[index] != string2[index])
			return (string1[index] - string2[index]);
		index++;
	}
	return (0);
}
