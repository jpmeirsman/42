/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstshift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsimeon <gsimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 18:47:41 by gsimeon           #+#    #+#             */
/*   Updated: 2015/12/07 18:59:51 by gsimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstshift(t_list **lst)
{
	t_list	*rslt;

	rslt = *lst;
	if (*lst)
	{
		*lst = (*lst)->next;
		rslt->next = NULL;
	}
	return (rslt);
}
