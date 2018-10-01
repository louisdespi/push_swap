/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_formspec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 15:29:22 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/09/24 19:50:17 by cvan-bee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	get_flags(const char *restrict *format, t_formspec *fs)
{
	const char	*t;
	const char	fchar1[] = {' ', '+', '-', '#', '0', 0};
	const char	fbit1[] = {FSP, FPL, FMI, FNO, FZE, 0};

	fs->flags = 0;
	while ((t = ft_strchr(fchar1, **format)) != NULL)
	{
		fs->flags |= fbit1[t - fchar1];
		(*format)++;
	}
}

static void	get_width(const char *restrict *format, t_formspec *fs)
{
	fs->width = 0;
	while (ft_isdigit(**format))
	{
		fs->width = fs->width * 10 + **format - 48;
		(*format)++;
	}
}

static void	get_prec(const char *restrict *format, t_formspec *fs)
{
	if (**format != '.')
		fs->prec = -1;
	else
	{
		fs->prec = 0;
		(*format)++;
		while (ft_isdigit(**format))
		{
			fs->prec = fs->prec * 10 + **format - 48;
			(*format)++;
		}
	}
}

static void	get_qual(const char *restrict *format, t_formspec *fs)
{
	fs->qual = ft_strchr("hljz", **format) ? *(*format)++ : '\0';
	if (**format == 'h')
	{
		fs->qual = 'H';
		(*format)++;
	}
	else if (**format == 'l')
	{
		fs->qual = 'L';
		(*format)++;
	}
}

void		get_formspec(const char *restrict *format, t_formspec *fs)
{
	get_flags(format, fs);
	get_width(format, fs);
	get_prec(format, fs);
	get_qual(format, fs);
}
