/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsimeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:32:22 by gsimeon           #+#    #+#             */
/*   Updated: 2015/12/01 17:57:52 by gsimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;

	if ((s = ft_strnew((size_t)ft_strlen(s1) + ft_strlen(s2))) == NULL)
		return (s);
	ft_strcpy(s, s1);
	ft_strcat(s, s2);
	return (s);
}
