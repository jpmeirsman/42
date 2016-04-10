/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddfront.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoden <ncoden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:40:48 by ncoden            #+#    #+#             */
/*   Updated: 2015/10/03 00:17:35 by ncoden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/containers/list.h"

void			ft_lstaddfront(t_lst **alst, t_lst *node)
{
	node->next = *alst;
	*alst = node;
}
