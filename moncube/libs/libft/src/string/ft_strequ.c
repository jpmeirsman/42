/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsimeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 10:56:17 by gsimeon           #+#    #+#             */
/*   Updated: 2015/12/01 11:04:18 by gsimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	while (*s1 == *s2 && s1 && s2 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (1);
	return (0);
}