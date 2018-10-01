/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 16:11:19 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/09/25 10:23:06 by cvan-bee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 512

typedef struct s_file	t_file;
struct					s_file
{
	char	*rest;
	int		fd;
};

int						get_next_line(const int fd, char **line);
#endif
