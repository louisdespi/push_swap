/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 16:00:06 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/06/15 16:06:51 by cvan-bee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *s1, const char *s2)
{
	char	*final;

	final = s1;
	while (*final)
		final++;
	while (*s2)
	{
		*final++ = *s2++;
	}
	*final = '\0';
	return (s1);
}
