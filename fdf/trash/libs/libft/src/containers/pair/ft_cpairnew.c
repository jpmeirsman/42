/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpairnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoden <ncoden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 09:31:15 by ncoden            #+#    #+#             */
/*   Updated: 2015/08/28 18:15:55 by ncoden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/containers/pair.h"

t_cpair			*ft_cpairnew(char index, void *data)
{
	t_cpair		*new;

	if (data)
	{
		if ((new = (t_cpair *)malloc(sizeof(t_cpair))))
		{
			new->index = index;
			new->data = data;
			return (new);
		}
	}
	return (NULL);
}
