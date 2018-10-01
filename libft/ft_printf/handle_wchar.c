/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 13:25:52 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/09/24 19:51:18 by cvan-bee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	handle_wchar(va_list ap, t_formspec *fs, char *ac)
{
	wchar_t	wc;

	wc = va_arg(ap, wchar_t);
	fs->wc = &wc;
	fs->s = ac;
	wctob(fs);
}
