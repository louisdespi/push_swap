/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uimtob.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 23:11:49 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/09/24 19:52:10 by cvan-bee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_base(char specif)
{
	if (specif == 'x' || specif == 'X')
		return (16);
	else if (specif == 'o' || specif == 'O')
		return (8);
	return (10);
}

static int	isofno(t_formspec *fs, char specif)
{
	return ((fs->flags & FNO) && (specif == 'o' || specif == 'O'));
}

void		uimtob(t_formspec *fs, char specif)
{
	char	ac[24];
	char	*digs;
	char	*ptr_digs;
	int		base;
	int		i;

	digs = "0123456789abcdef0123456789ABCDEF";
	ptr_digs = (specif == 'X') ? digs + 16 : digs;
	base = get_base(specif);
	i = (int)sizeof(ac);
	if (fs->uim != 0 || fs->prec != 0 || isofno(fs, specif))
		ac[--i] = ptr_digs[fs->uim % base];
	fs->uim /= base;
	while (fs->uim > 0 && i > 0)
	{
		ac[--i] = ptr_digs[fs->uim % base];
		fs->uim /= base;
	}
	fs->n1 = sizeof(ac) - i;
	ft_memcpy(fs->s, &ac[i], fs->n1);
	if (fs->n1 < fs->prec)
		fs->nz0 = fs->prec - fs->n1 - isofno(fs, specif);
	if (fs->prec < 0 && (fs->flags & (FMI | FZE)) == FZE && (i = fs->width
				- fs->n0 - fs->nz0 - fs->n1) > 0)
		fs->nz0 += i;
}
