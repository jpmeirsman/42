/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsimeon <gsimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 02:28:32 by gsimeon           #+#    #+#             */
/*   Updated: 2015/12/07 01:53:46 by gsimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_words(char const *s, char c)
{
	int		w;

	w = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		while (*s != c && *s)
			s++;
		w++;
	}
	return (w);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		n;
	char	**rslt;

	n = 0;
	if ((rslt = (char **)malloc(sizeof(char *) * (ft_words(s, c) + 1))) == NULL)
		return (NULL);
	while (*s)
	{
		i = 0;
		while (*s == c)
			s++;
		while (s[i] != c && s[i])
			i++;
		if ((s[i] == '\0' || s[i] == c) && i)
			rslt[n++] = ft_strncpy(ft_strnew(i + 1), s, i);
		s += i;
	}
	rslt[n] = NULL;
	return (rslt);
}
