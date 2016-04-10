/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_solve_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsimeon <gsimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 00:49:09 by gsimeon           #+#    #+#             */
/*   Updated: 2016/03/26 23:50:44 by gsimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline static void	pf_set_digits(char **src, int *w, int *p, va_list *ap)
{
	if (**src == '*' && *(*src - 1) == '.')
		*p = va_arg(*ap, int);
	else if (**src == '*')
		*w = va_arg(*ap, int);
	if (**src == '*')
		*src += 1;
	if (ft_isdigit(**src) && *(*src - 1) == '.')
		*p = ft_atoi(*src);
	else if (ft_isdigit(**src))
		*w = ft_atoi(*src);
	while (ft_isdigit(**src))
		*src += 1;
}

inline static int	pf_neg_worp(int *w, int *p, int flg)
{
	if (*w < 0)
	{
		*w = -*w;
		return (flg | 512);
	}
	if (*p < 0)
		return (flg & ~(128));
	return (flg);
}

/*
**			Remove Multiple Flags and catch the last good flags and digits.
*/

inline static int	pf_read_flags(char **src, int *w, int *p, va_list *ap)
{
	const char	*flags = "0hhllzj.#-+ ";
	int			n;
	int			flg;

	flg = 0;
	n = -1;
	while (++n != 12)
	{
		if (flags[n] == **src)
		{
			if ((n == 1 || n == 3) && flg & (ft_pwr(2, n) ^ ft_pwr(2, n + 1)))
				flg = flg ^ (ft_pwr(2, n) ^ ft_pwr(2, n + 1));
			else if ((flg = flg | ft_pwr(2, n)))
				*p = (n == 7 ? 0 : *p);
			n = -1;
			*src += 1;
		}
		n != -1 ? pf_set_digits(src, w, p, ap) : 0;
		flg = pf_neg_worp(w, p, flg);
	}
	if (*p == 0 && flg & 128 && **src == 'x')
		flg = flg & ~(256);
	if (**src == 'p')
		flg = flg | 272;
	return (flg);
}

/*
**			Remove Conflicting Flags and set *src on the output value
*/

int					pf_solve_flags(char **src, int *w, int *p, va_list *ap)
{
	int			flags;
	int			n;

	n = 7;
	flags = pf_read_flags(src, w, p, ap);
	if (ft_strchr("DOU", (int)**src) && (flags = (flags & ~(126)) | 8))
		**src = (char)ft_tolower((int)**src);
	if (ft_strchr("bdDioOuUxX", (int)**src))
		flags = (flags & ft_pwr(2, n) ? flags & ~(1) : flags);
	if (ft_strchr("bdDioOuUxX", (int)**src))
	{
		while (--n > 1 && !(ft_pwr(2, n) & flags))
			;
		while (--n > 1)
			flags = flags & ~(ft_pwr(2, n));
	}
	if (flags & 512 && flags & 1)
		flags = flags & ~(1);
	if (!ft_strchr("dDi", (int)**src))
		flags = flags & ~(3072);
	if (ft_strchr("cs", (int)**src) && (flags & 24))
		**src = (char)ft_toupper((int)**src);
	if (**src == 'c' || **src == 'C')
		flags = flags & ~(128);
	return (flags);
}
