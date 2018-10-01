/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 19:11:29 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/09/24 19:50:38 by cvan-bee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	handle_sint(va_list ap, t_formspec *fs, char specif, char *ac)
{
	if (fs->qual == 'l' || specif == 'D')
		fs->im = (intmax_t)va_arg(ap, long);
	else if (fs->qual == 'H')
		fs->im = (intmax_t)(signed char)va_arg(ap, int);
	else if (fs->qual == 'h')
		fs->im = (intmax_t)(short)va_arg(ap, int);
	else if (fs->qual == 0)
		fs->im = (intmax_t)va_arg(ap, int);
	else if (fs->qual == 'L')
		fs->im = (intmax_t)va_arg(ap, long long int);
	else if (fs->qual == 'j')
		fs->im = va_arg(ap, intmax_t);
	else
		fs->im = (intmax_t)va_arg(ap, ssize_t);
	if (fs->im < 0)
		ac[fs->n0++] = '-';
	else if (fs->flags & FPL)
		ac[fs->n0++] = '+';
	else if (fs->flags & FSP)
		ac[fs->n0++] = ' ';
	fs->s = &ac[fs->n0];
	imtob(fs);
}
