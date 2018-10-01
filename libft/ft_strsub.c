/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 14:22:39 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/06/21 16:50:40 by cvan-bee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	i;

	if ((ret = ft_strnew(len)))
	{
		i = 0;
		while (len)
		{
			ret[i] = s[start];
			start++;
			len--;
			i++;
		}
	}
	return (ret);
}
