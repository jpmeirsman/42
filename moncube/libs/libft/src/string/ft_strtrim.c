/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsimeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 18:04:18 by gsimeon           #+#    #+#             */
/*   Updated: 2015/12/01 20:41:34 by gsimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	int		i;
	char	*str;

	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	if (ft_strlen(s))
	{
		i = ft_strlen(s) - 1;
		while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && i > 0)
			i--;
		if ((str = (char *)malloc(sizeof(char) * (i + 2))) != NULL)
			ft_strcpy(str, ft_strsub(s, 0, i + 1));
		return (str);
	}
	return (ft_strdup(s));
}
