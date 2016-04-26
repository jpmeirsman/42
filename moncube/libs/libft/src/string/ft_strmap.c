/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsimeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 10:29:35 by gsimeon           #+#    #+#             */
/*   Updated: 2015/12/01 10:50:58 by gsimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*rslt;
	size_t	i;

	i = ft_strlen(s);
	if ((rslt = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	rslt[i] = '\0';
	while (i--)
		rslt[i] = (*f)(s[i]);
	return (rslt);
}
