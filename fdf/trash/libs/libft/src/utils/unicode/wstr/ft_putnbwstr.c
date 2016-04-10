/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbwstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoden <ncoden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/27 19:32:56 by ncoden            #+#    #+#             */
/*   Updated: 2015/08/28 23:38:44 by ncoden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft/utils/unicode.h"

void			ft_putnbwstr(const wchar_t *s, size_t byte_nbr)
{
	char		unicode;

	if (s)
	{
		unicode = ft_getunicode();
		if (unicode == UNI_UTF8)
			ft_putnbwstr_utf8(s, byte_nbr);
	}
}
