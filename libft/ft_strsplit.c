/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 18:26:07 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/06/22 11:54:05 by cvan-bee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int		count;

	count = 0;
	while (*s)
	{
		if (*s == c)
		{
			while (*s == c)
				s++;
		}
		else
		{
			while (*s != c && *s)
				s++;
			count++;
		}
	}
	return (count);
}

static char	*get_word_by_index(const char *s, char c, int index)
{
	int	i;

	i = 0;
	while (*s && i < index)
	{
		if (*s == c)
		{
			while (*s == c)
				s++;
		}
		else
		{
			while (*s && *s != c)
				s++;
			i++;
		}
	}
	while (*s == c)
		s++;
	return ((char*)s);
}

static int	first_word_length(const char *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s != c)
	{
		s++;
		len++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		word_len;

	if (!(tab = (char**)malloc(sizeof(char*) * (count_words(s, c) + 1))))
		return (NULL);
	i = 0;
	while (i < count_words(s, c))
	{
		j = 0;
		word_len = first_word_length(get_word_by_index(s, c, i), c);
		if (!(tab[i] = (char*)malloc(sizeof(char) * (word_len + 1))))
			return (NULL);
		while (j < word_len)
		{
			tab[i][j] = get_word_by_index(s, c, i)[j];
			j++;
		}
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = 0;
	return (tab);
}
