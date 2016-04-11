/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsimeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 17:22:01 by gsimeon           #+#    #+#             */
/*   Updated: 2015/12/05 01:38:45 by gsimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lst;

	if ((lst = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	lst->next = NULL;
	if (content == NULL)
	{
		lst->content_size = 0;
		lst->content = NULL;
	}
	else
	{
		lst->content_size = content_size;
		lst->content = (void *)malloc(lst->content_size);
		if (!lst->content)
		{
			ft_memdel((void**)&lst);
			return (NULL);
		}
		ft_memcpy(lst->content, content, lst->content_size);
	}
	return (lst);
}
