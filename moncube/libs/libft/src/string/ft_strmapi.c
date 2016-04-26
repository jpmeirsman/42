/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsimeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 10:47:08 by gsimeon           #+#    #+#             */
/*   Updated: 2015/12/01 10:55:14 by gsimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*rslt;
	unsigned int	i;

	i = ft_strlen(s);
	if ((rslt = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	rslt[i] = '\0';
	while (i--)
		rslt[i] = (*f)(i, s[i]);
	return (rslt);
}
