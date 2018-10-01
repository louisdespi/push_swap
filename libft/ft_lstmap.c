/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 09:22:56 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/06/22 17:01:10 by cvan-bee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*to_ret;
	t_list	*new;

	to_ret = NULL;
	while (lst)
	{
		new = (*f)(lst);
		new = ft_lstnew(new->content, new->content_size);
		ft_lstaddback(&to_ret, new);
		lst = lst->next;
	}
	return (to_ret);
}
