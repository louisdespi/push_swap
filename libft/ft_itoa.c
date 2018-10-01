/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 10:27:38 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/06/21 17:21:56 by cvan-bee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_size(int n)
{
	int	i;

	i = 0;
	if (!n)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*ret;
	int		size;
	int		isneg;
	long	tmp;

	tmp = (long)n;
	size = num_size(n);
	if ((isneg = n < 0))
	{
		size++;
		tmp = -tmp;
	}
	if (!(ret = (char*)malloc(size + 1)))
		return (NULL);
	ret[size] = '\0';
	size--;
	while (size != -1)
	{
		ret[size] = tmp % 10 + '0';
		tmp = tmp / 10;
		size--;
	}
	if (isneg)
		ret[0] = '-';
	return (ret);
}
