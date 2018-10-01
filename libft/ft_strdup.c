/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 14:23:47 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/06/21 12:22:31 by cvan-bee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	len;
	size_t	ind;

	len = ft_strlen(s1);
	if (!(copy = (char*)malloc(sizeof(*copy) * (len + 1))))
		return (NULL);
	ind = 0;
	while (ind <= len)
	{
		copy[ind] = s1[ind];
		ind++;
	}
	return (copy);
}
