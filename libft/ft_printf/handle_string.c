/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 22:50:04 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/09/24 19:51:00 by cvan-bee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	handle_string(va_list ap, t_formspec *fs)
{
	fs->s = va_arg(ap, char*);
	if (fs->s)
		fs->n1 = (int)ft_strlen(fs->s);
	else
		fs->n1 = 0;
	if (fs->prec >= 0 && fs->prec < fs->n1)
		fs->n1 = fs->prec;
}
