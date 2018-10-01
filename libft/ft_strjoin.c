/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 14:31:14 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/06/18 14:46:16 by cvan-bee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	char	*ret;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if ((ret = ft_strnew(len1 + len2)))
	{
		i = 0;
		while (i < len1)
		{
			ret[i] = s1[i];
			i++;
		}
		while (i < len1 + len2)
		{
			ret[i] = s2[i - len1];
			i++;
		}
	}
	return (ret);
}
