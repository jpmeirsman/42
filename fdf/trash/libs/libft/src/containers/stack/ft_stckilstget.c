/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stckilstget.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoden <ncoden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 19:27:17 by ncoden            #+#    #+#             */
/*   Updated: 2015/08/28 18:25:56 by ncoden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft/containers/ilst.h"
#include "libft/containers/stack.h"

t_ilst			*ft_stckilstget(t_stck *stck, int index)
{
	t_ilst		*ilst;
	int			head;
	int			size;
	int			count;

	if (!stck)
		return (NULL);
	head = stck->head;
	size = stck->size;
	count = stck->count;
	while (count > 0)
	{
		head--;
		count--;
		if ((ilst = ft_ilstget(stck->datas[head], index)))
			return (ilst);
		if (head == 0)
		{
			head = size;
			stck = (t_stck *)stck->next;
		}
	}
	return (NULL);
}
