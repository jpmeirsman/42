/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsimeon <gsimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 18:48:19 by gsimeon           #+#    #+#             */
/*   Updated: 2015/12/05 05:33:40 by gsimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstend(t_list **lst, t_list *new)
{
	if (*lst)
		ft_lstend(&((*lst)->next), new);
	else
		ft_lstadd(lst, new);
}
