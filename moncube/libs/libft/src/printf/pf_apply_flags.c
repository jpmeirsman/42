/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_apply_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsimeon <gsimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 05:04:16 by gsimeon           #+#    #+#             */
/*   Updated: 2016/03/26 23:50:12 by gsimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline static char	*pf_int_precision(char *str, int precision, int flags)
{
	char	*tmp1;
	char	*tmp2;
	char	*c;
	int		i;

	i = 0;
	c = "";
	if (*str == '0' && precision == 0 && flags & 128)
		return (ft_strdup(c));
	if (*str == '-' && str++)
		c = "-";
	else if ((flags & 3072))
		c = ((flags & 1024) ? "+" : " ");
	if (precision > (int)ft_strlen(str))
		i = precision - ft_strlen(str);
	tmp1 = (char*)ft_memset((void*)ft_strnew(i), '0', i);
	tmp2 = ft_strjoin(tmp1, str);
	ft_strdel(&tmp1);
	c = ft_strlen(tmp2) ? c : "0";
	str = ft_strjoin(c, tmp2);
	ft_strdel(&tmp2);
	return (str);
}

inline static char	*pf_str_precision(void *ptr, int prec, int flags, char s)
{
	char		*out;
	int			i;

	i = 0;
	if (s == 's' || (s == 'S' && *((int*)ptr) > 1114111))
		out = ft_strdup((char *)ptr);
	else if (s == 'S')
		out = ft_wstrtostr((wchar_t*)ptr);
	else if (s == 'C' && (out = ft_wtoc((wchar_t)ptr)) && *out)
		;
	else
	{
		out = ft_strnew(1);
		out[0] = ((char)ptr != 0 ? (char)ptr : 'c');
	}
	if ((flags & 128) && ft_strlen(out) > (size_t)prec)
	{
		out[prec] = '\0';
		while (prec && (out[prec - 1] & 128) && !(out[prec - 1] & 64) && ++i)
			prec--;
		if (((--prec) >= 0 && (out[prec] & 128)) || prec++ < 0)
			out[prec] = (((out[prec] << i) & 64) ? '\0' : out[prec]);
	}
	return (out);
}

inline static char	*pf_set_width(char *tmp, int width, int i, int flags)
{
	char	*str;

	ft_strdel(&tmp);
	if (flags & 1)
		str = ft_memset((void*)ft_strnew(width - i), '0', width - i);
	else
		str = ft_memset((void*)ft_strnew(width - i), ' ', width - i);
	return (str);
}

inline static char	*pf_width(char *str, int width, int flags, char **src)
{
	char	*tmp;
	char	*tmp2;
	char	*out;
	char	*c;
	int		i;

	c = "";
	tmp = ft_strnew(0);
	if ((**src == 'x' || **src == 'p') && flags & 256)
		c = "0x";
	else if (**src == 'o' && flags & 256)
		c = (*str == '0' ? "" : "0");
	else if ((*str == '-' || *str == '+') && (str += 1))
		c = (*(str - 1) == '-' ? "-" : "+");
	if ((i = (ft_strlen(str) + ft_strlen(c))) < width)
		tmp = pf_set_width(tmp, width, i, flags);
	tmp2 = tmp;
	if ((*str == ' ' && (flags & 1) && (c = " ") && str++) || (flags & 1))
		tmp = ft_strjoin(c, tmp);
	else
		str = ft_strjoin(c, str);
	out = ((flags & 512) ? ft_strjoin(str, tmp) : ft_strjoin(tmp, str));
	(flags & 1 ? ft_strdel(&tmp2) : ft_strdel(&str));
	ft_strdel(&tmp);
	return (out);
}

char				*pf_apply_flags(char **str, void *ptr, va_list *ap)
{
	int		width;
	int		precision;
	int		flags;
	char	*out;
	char	*tmp;

	width = 0;
	precision = 0;
	flags = pf_solve_flags(str, &width, &precision, ap);
	va_end(*ap);
	if (**str == 'x' && (int)ptr == 0)
		flags = flags & ~(256);
	if (ft_strchr("bpdDioOuUxX", (int)**str))
	{
		out = pf_itoa(ptr, **str, flags);
		tmp = pf_int_precision(out, precision, flags);
		ft_strdel(&out);
	}
	else
		tmp = pf_str_precision(ptr, precision, flags, **str);
	out = pf_width(tmp, width, flags, str);
	ft_strdel(&tmp);
	return (out);
}
