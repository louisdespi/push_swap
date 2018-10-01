/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 17:47:49 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/06/21 16:26:42 by cvan-bee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*first;
	char	*last;
	size_t	len;
	size_t	finlen;
	char	*ret;

	len = ft_strlen(s);
	first = (char*)s;
	last = (char*)&s[len - 1];
	while (*first && (*first == ' ' || *first == '\t' || *first == '\n'))
		first++;
	while (last > first && (*last == ' ' || *last == '\t' || *last == '\n'))
		last--;
	finlen = ft_strlen(first) - ft_strlen(last) + 1;
	if (!(ret = (char*)malloc(finlen + 1)))
		return (NULL);
	len = 0;
	while (len < finlen)
	{
		ret[len] = first[len];
		len++;
	}
	ret[len] = '\0';
	return (ret);
}
