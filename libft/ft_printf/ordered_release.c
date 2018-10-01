/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordered_release.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 23:29:36 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/09/24 19:51:36 by cvan-bee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	format_put(char *s, int n, t_formspec *fs)
{
	if (n > 0)
	{
		write(1, s, n);
		fs->size += n;
	}
}

static void	format_pad(char *s, int n, t_formspec *fs)
{
	int		i;
	int		j;

	if (n > 0)
	{
		i = n;
		j = n;
		while (j > 0)
		{
			if (j > MAX_PAD)
				i = MAX_PAD;
			else
				i = j;
			format_put(s, i, fs);
			j -= i;
		}
	}
}

static void	putwstr(t_formspec *fs, char *ac)
{
	while (*(fs->wc))
	{
		fs->s = ac;
		wctob(fs);
		if (fs->prec >= 0 && fs->prec < fs->n1)
			break ;
		format_put(fs->s, fs->n1, fs);
		fs->prec -= fs->n1;
		(fs->wc)++;
	}
}

void		ordered_release(t_formspec *fs, char *ac, char specif)
{
	char		*zeroes;
	char		*spaces;

	zeroes = "00000000000000000000000000000000";
	spaces = "                                ";
	fs->width -= fs->n0 + fs->nz0 + fs->n1;
	if (!(fs->flags & FMI))
		format_pad(spaces, fs->width, fs);
	if ((specif == 's' && fs->qual != 'l' && fs->s == NULL) || ((specif == 'S'
					|| (specif == 's' && fs->qual == 'l')) && fs->wc == NULL))
		format_put("(null)", 6, fs);
	else if (specif == 'S' || (specif == 's' && fs->qual == 'l'))
		putwstr(fs, ac);
	else
	{
		format_put(ac, fs->n0, fs);
		format_pad(zeroes, fs->nz0, fs);
		format_put(fs->s, fs->n1, fs);
	}
	if (fs->flags & FMI)
		format_pad(spaces, fs->width, fs);
}
