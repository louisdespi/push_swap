/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 16:48:51 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/06/21 11:02:07 by cvan-bee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	long	len;

	len = (long)ft_strlen(s);
	while (len != -1)
	{
		if (s[len] == (char)c)
			return ((char*)&s[len]);
		len--;
	}
	return (NULL);
}
