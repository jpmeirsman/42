/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsimeon <gsimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 20:27:11 by gsimeon           #+#    #+#             */
/*   Updated: 2015/12/07 21:55:00 by gsimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*rslt;

	rslt = NULL;
	if (!lst || !f)
		return (NULL);
	if (lst && (rslt = ft_lstnew(lst->content, lst->content_size)) != NULL)
	{
		rslt = (*f)(rslt);
		rslt->next = ft_lstmap(lst->next, f);
	}
	if (lst && lst->next && rslt && !rslt->next)
	{
		free(rslt);
		return (NULL);
	}
	return (rslt);
}
