/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 07:51:41 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/09/24 19:41:05 by cvan-bee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

# define FSP 0x01
# define FPL 0x02
# define FMI 0x04
# define FNO 0x08
# define FZE 0x10

# define MAX_PAD 31

typedef struct	s_formspec
{
	uintmax_t	uim;
	intmax_t	im;
	wchar_t		*wc;
	size_t		size;
	char		*s;
	char		flags;
	int			width;
	int			prec;
	char		qual;
	int			n0;
	int			nz0;
	int			n1;
}				t_formspec;

int				ft_printf(const char *restrict format, ...);
int				print_formated(const char *restrict format, va_list ap);
void			get_formspec(const char *restrict *format, t_formspec *fs);
void			dispatch(va_list ap, t_formspec *fs, char specif, char *ac);
void			handle_wchar(va_list ap, t_formspec *fs, char *ac);
void			handle_sint(va_list ap, t_formspec *fs, char specif, char *ac);
void			handle_uint(va_list ap, t_formspec *fs, char specif, char *ac);
void			handle_string(va_list ap, t_formspec *fs);
void			handle_ptr(va_list ap, t_formspec *fs, char *ac);
int				numbits(wchar_t c);
void			wctob(t_formspec *fs);
void			uimtob(t_formspec *fs, char specif);
void			imtob(t_formspec *fs);
void			ordered_release(t_formspec *fs, char *ac, char specif);
#endif
