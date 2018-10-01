/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 23:09:11 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/09/24 19:48:06 by cvan-bee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_wstrsize(t_formspec *fs)
{
	int		count;
	wchar_t	*tmp;
	int		prec;
	int		nbits;

	prec = fs->prec;
	tmp = fs->wc;
	count = 0;
	while (*tmp)
	{
		nbits = numbits(*tmp);
		if (prec >= 0 && prec < nbits)
			break ;
		count += nbits;
		prec -= nbits;
		tmp++;
	}
	return (count);
}

void		dispatch(va_list ap, t_formspec *fs, char specif, char *ac)
{
	fs->n0 = 0;
	fs->nz0 = 0;
	fs->n1 = 0;
	if (specif == 'C' || (specif == 'c' && fs->qual == 'l'))
		handle_wchar(ap, fs, ac);
	else if (specif == 'S' || (specif == 's' && fs->qual == 'l'))
	{
		fs->wc = va_arg(ap, wchar_t*);
		if (fs->wc)
			fs->n1 = get_wstrsize(fs);
	}
	else if (specif == 'c')
		ac[fs->n0++] = va_arg(ap, int);
	else if (specif == 'd' || specif == 'i' || specif == 'D')
		handle_sint(ap, fs, specif, ac);
	else if (specif == 'x' || specif == 'X' || specif == 'o' || specif == 'u' ||
			specif == 'U' || specif == 'O')
		handle_uint(ap, fs, specif, ac);
	else if (specif == '%')
		ac[fs->n0++] = '%';
	else if (specif == 's')
		handle_string(ap, fs);
	else if (specif == 'p')
		handle_ptr(ap, fs, ac);
}
