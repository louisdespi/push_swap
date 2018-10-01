/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 16:52:38 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/06/21 11:12:43 by cvan-bee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*temp_haystack;
	const char	*temp_needle;

	if (!*needle)
		return ((char*)haystack);
	while (*haystack)
	{
		temp_haystack = haystack;
		temp_needle = needle;
		while (*temp_needle && *temp_needle == *temp_haystack)
		{
			temp_haystack++;
			temp_needle++;
		}
		if (!*temp_needle)
			return ((char*)haystack);
		haystack++;
	}
	return (NULL);
}
