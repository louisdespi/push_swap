/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_formated.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 13:03:40 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/09/24 19:51:59 by cvan-bee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_put(const char *restrict *format, t_formspec *fs)
{
	const char *restrict	s;

	s = *format;
	while (*s && *s != '%')
		s++;
	fs->size += (size_t)(s - *format);
	return (write(1, *format, (size_t)(s - *format)));
}

int					print_formated(const char *restrict format, va_list ap)
{
	t_formspec				fs;
	char					ac[32];

	fs.size = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			get_formspec(&format, &fs);
			dispatch(ap, &fs, *format, ac);
			ordered_release(&fs, ac, *format);
			format++;
		}
		else
			format += ft_put(&format, &fs);
	}
	return ((int)fs.size);
}
