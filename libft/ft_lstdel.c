/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-bee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 08:54:53 by cvan-bee          #+#    #+#             */
/*   Updated: 2018/06/25 17:32:58 by cvan-bee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*current;
	t_list	*tmp;

	current = *alst;
	while (current)
	{
		tmp = *alst;
		current = current->next;
		(*del)((tmp)->content, (tmp)->content_size);
		free(tmp);
	}
	*alst = NULL;
}
