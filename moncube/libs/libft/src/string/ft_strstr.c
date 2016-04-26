/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsimeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 20:33:14 by gsimeon           #+#    #+#             */
/*   Updated: 2015/11/30 16:15:40 by gsimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;

	if (*s2)
	{
		while (*s1)
		{
			i = 0;
			while (s1[i] == s2[i])
			{
				if (!s2[++i])
					return ((char *)s1);
			}
			s1++;
		}
		return (NULL);
	}
	return ((char *)s1);
}
