/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 10:56:19 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/07/16 23:15:01 by cvan-bee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_file	*new_file(int fd)
{
	t_file	*ret;

	if (!(ret = (t_file*)malloc(sizeof(*ret))))
		return (NULL);
	ret->fd = fd;
	ret->rest = NULL;
	return (ret);
}

static t_list	*get_file(int fd, t_list **list)
{
	t_list	*ret;

	ret = *list;
	if (!ret)
		return (*list = ft_lstnew(new_file(fd), sizeof(t_file)));
	while (ret)
	{
		if (((t_file*)ret->content)->fd == fd)
		{
			return (ret);
		}
		ret = ret->next;
	}
	ret = ft_lstnew(new_file(fd), sizeof(t_file));
	ft_lstaddback(list, ret);
	return (ret);
}

static int		has_new_line(t_file *file, char **line)
{
	char	*new_line;
	char	*rest;

	rest = ft_strdup(file->rest);
	if (rest && (new_line = ft_strchr(rest, 10)))
	{
		if (!(*line = ft_strsub(rest, 0, new_line - rest)))
			return (0);
		file->rest = ft_strdup(new_line + 1);
		ft_strdel(&rest);
		return (1);
	}
	ft_strdel(&rest);
	return (0);
}

static char		*strforcejoin(char **s1, char const *s2)
{
	char	*ret;

	if (!(*s1))
		ret = ft_strdup(s2);
	else
		ret = (ft_strjoin(*s1, s2));
	ft_strdel(s1);
	return (ret);
}

int				get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static t_list	*list_files = NULL;
	t_file			*file;
	ssize_t			read_bytes;

	if (fd < 0 || !(file = (t_file*)get_file(fd, &list_files)->content))
		return (-1);
	if (file->rest && has_new_line(file, line))
		return (1);
	while ((read_bytes = read(fd, buf, BUFF_SIZE)))
	{
		if (read_bytes < 0)
			return (-1);
		buf[read_bytes] = '\0';
		file->rest = strforcejoin(&(file->rest), buf);
		if (has_new_line(file, line))
			return (1);
	}
	if (file->rest != NULL && *(file->rest) != '\0')
	{
		*line = ft_strdup(file->rest);
		ft_strdel(&(file->rest));
		return (1);
	}
	return (0);
}
