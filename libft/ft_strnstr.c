/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 17:15:51 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/06/21 16:50:25 by cvan-bee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*temp_haystack;
	const char	*temp_needle;
	size_t		i;
	size_t		y;

	if (!*needle)
		return ((char*)haystack);
	i = 0;
	while (*haystack && i < len)
	{
		temp_haystack = haystack;
		temp_needle = needle;
		y = i;
		while (y < len && *temp_needle && *temp_needle == *temp_haystack)
		{
			temp_haystack++;
			temp_needle++;
			y++;
		}
		if (!*temp_needle)
			return ((char*)haystack);
		haystack++;
		i++;
	}
	return (NULL);
}
