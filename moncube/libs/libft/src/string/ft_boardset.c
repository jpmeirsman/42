/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boardset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsimeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 02:01:04 by gsimeon           #+#    #+#             */
/*   Updated: 2015/12/20 02:08:23 by gsimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		**ft_boardset(int x, int y, char c)
{
	char	**rslt;
	int		i;
	int		j;

	j = 0;
	rslt = (char**)malloc((sizeof(char*) * y) + (x * y));
	if (!rslt)
		return (NULL);
	while (j < y)
	{
		i = 0;
		rslt[j] = (char*)((char*)rslt) + y * sizeof(char*) + x * j;
		while (i < x)
		{
			rslt[j][i] = c;
			i++;
		}
		j++;
	}
	return (rslt);
}
