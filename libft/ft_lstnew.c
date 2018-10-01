/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 08:12:19 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/06/21 17:20:04 by cvan-bee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*newcont;

	if ((new = (t_list*)malloc(sizeof(*new))))
	{
		if (!content)
		{
			new->content = NULL;
			new->content_size = 0;
		}
		else
		{
			if (!(newcont = malloc(content_size)))
			{
				free(new);
				return (NULL);
			}
			new->content = ft_memcpy(newcont, content, content_size);
			new->content_size = content_size;
		}
		new->next = NULL;
	}
	return (new);
}
