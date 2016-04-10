/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushby.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoden <ncoden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 20:00:00 by ncoden            #+#    #+#             */
/*   Updated: 2015/10/02 23:02:54 by ncoden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft/containers/list.h"

t_lst			*ft_lstpushby(t_lst **alst, void *data,
					int (*cmp)(const void *data1, const void *data2))
{
	t_lst		*node;

	if (!(node = ft_lstnew(data)))
		return (NULL);
	ft_lstaddby(alst, node, cmp);
	return (node);
}
