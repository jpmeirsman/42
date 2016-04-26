/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsimeon <gsimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 18:53:21 by gsimeon           #+#    #+#             */
/*   Updated: 2016/03/26 23:49:35 by gsimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*pf_arg(va_list *ap, void *arg, char **src, int i)
{
	int		n;

	n = 0;
	while (n != i)
		src[0][n++] == '*' ? va_arg(*ap, void *) : 0;
	if (src[0][i] && (ft_strchr("ncCsSbpdDioOuUxX", (int)src[0][i])))
		arg = va_arg(*ap, void *);
	if (!arg && (src[0][i] == 's' || src[0][i] == 'S'))
		arg = "(null)";
	return (arg);
}

static char		*pf_no(char **src, int i)
{
	*src += i;
	return (ft_strnew(0));
}

static void		pf_flag_n(char **src, int *arg, int *len)
{
	int		h;
	int		l;

	h = 0;
	l = 0;
	while (**src != 'n')
	{
		if (**src == 'h')
			h++;
		if (**src == 'l')
			l++;
		*src += 1;
	}
	if (l && !(l % 2))
		*arg = (unsigned long long)*len;
	else if ((l % 2))
		*arg = (unsigned long)*len;
	else if ((h % 2))
		*arg = (unsigned short)*len;
	else if (h)
		*arg = (unsigned char)*len;
	else
		*arg = *len;
}

static void		pf_preset(va_list *ap, char **src, int *len, int i)
{
	void		*arg;
	char		*tmp;
	va_list		ap2;

	va_copy(ap2, *ap);
	while (src[0][i] && (ft_strchr("0123456789hlzj.#+- *", (int)src[0][i])))
		i++;
	arg = pf_arg(ap, NULL, src, i);
	if (src[0][i] == 'n' && (tmp = ft_strnew(0)))
		pf_flag_n(src, (int*)arg, len);
	else if (src[0][i] && (ft_strchr("cCsSbpdDioOuUx", (int)src[0][i])))
		tmp = pf_apply_flags(src, arg, &ap2);
	else if (src[0][i] == 'X' && (src[0][i] = 'x'))
		ft_strtoupper(tmp = pf_apply_flags(src, arg, &ap2));
	else
	{
		arg = (void*)((ssize_t)src[0][i]);
		src[0][i] = (src[0][i] ? 'c' : src[0][i]);
		tmp = (src[0][i] == 0 ? pf_no(src, i) : pf_apply_flags(src, arg, &ap2));
	}
	i = (int)ft_strlen(tmp);
	if ((*len += i) && i && (int)arg == 0 && (**src == 'c' || **src == 'C'))
		ft_memset((void *)ft_strchr(tmp, 'c'), '\0', 1);
	ft_putnstr(tmp, i);
	ft_strdel(&tmp);
}

int				ft_printf(const char *str, ...)
{
	va_list		ap;
	int			len;
	int			i;
	char		*tmp2;
	char		*src;

	len = 0;
	src = ft_strdup(str);
	tmp2 = src;
	va_start(ap, str);
	while (*src)
	{
		i = 0;
		while (src[i] != '%' && src[i] && ++len && ++i)
			;
		ft_putnstr(src, i);
		if ((src += i) && *src && ++src && *src)
		{
			pf_preset(&ap, &src, &len, 0);
			src++;
		}
	}
	va_end(ap);
	ft_strdel(&tmp2);
	return (len);
}
