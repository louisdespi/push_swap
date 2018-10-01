/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 17:12:54 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/09/24 19:51:09 by cvan-bee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	handle_uint(va_list ap, t_formspec *fs, char specif, char *ac)
{
	if (fs->qual == 'l' || specif == 'U' || specif == 'O')
		fs->uim = (uintmax_t)va_arg(ap, unsigned long);
	else if (fs->qual == 'H')
		fs->uim = (uintmax_t)(unsigned char)va_arg(ap, unsigned int);
	else if (fs->qual == 'h')
		fs->uim = (uintmax_t)(unsigned short)va_arg(ap, unsigned int);
	else if (fs->qual == 0)
		fs->uim = (uintmax_t)va_arg(ap, unsigned int);
	else if (fs->qual == 'L')
		fs->uim = (uintmax_t)va_arg(ap, unsigned long long);
	else if (fs->qual == 'j')
		fs->uim = va_arg(ap, uintmax_t);
	else
		fs->uim = va_arg(ap, size_t);
	if (fs->flags & FNO && fs->uim != 0)
	{
		ac[fs->n0++] = '0';
		if (specif == 'x' || specif == 'X')
			ac[fs->n0++] = specif;
	}
	fs->s = &ac[fs->n0];
	uimtob(fs, specif);
}
