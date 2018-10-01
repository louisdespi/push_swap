/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imtob.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 23:15:45 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/09/24 19:51:29 by cvan-bee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	imtob(t_formspec *fs)
{
	char		ac[24];
	int			i;
	uintmax_t	uim;

	ft_bzero(ac, 24);
	i = sizeof(ac);
	uim = (uintmax_t)fs->im;
	if (fs->im < 0)
		uim = -uim;
	if (uim || fs->prec)
		ac[--i] = uim % 10 + 48;
	fs->im = uim / 10;
	while (fs->im > 0 && i > 0)
	{
		ac[--i] = (fs->im) % 10 + 48;
		fs->im = fs->im / 10;
	}
	fs->n1 = sizeof(ac) - i;
	ft_memcpy(fs->s, &ac[i], fs->n1);
	if (fs->n1 < fs->prec)
		fs->nz0 = fs->prec - fs->n1;
	if (fs->prec < 0 && (fs->flags & (FMI | FZE)) == FZE
			&& (i = fs->width - fs->n0 - fs->nz0 - fs->n1) > 0)
		fs->nz0 += i;
}
