/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 23:01:00 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/09/24 19:50:29 by cvan-bee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	handle_ptr(va_list ap, t_formspec *fs, char *ac)
{
	fs->uim = (uintmax_t)((unsigned long)va_arg(ap, void*));
	ac[fs->n0++] = '0';
	ac[fs->n0++] = 'x';
	fs->s = &ac[fs->n0];
	uimtob(fs, 'x');
}
