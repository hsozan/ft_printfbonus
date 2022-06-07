/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 03:51:54 by hsozan            #+#    #+#             */
/*   Updated: 2022/02/27 03:51:54 by hsozan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*charwidth(char	*str, t_specs *s)
{
	char	*add;

	add = ft_calloc(sizeof(*add), s->width + 1);
	if (s->zero && !s->eksi)
		strfill(add, '0', s->width - 1);
	else
		strfill(add, ' ', s->width - 1);
	if (s->eksi)
		str = freejoin(str, add);
	else
		str = freejoin(add, str);
	return (str);
}

void	charprec(t_specs *s, char *str, int *count)
{
	int		zero;

	zero = 0;
	if (!str[0])
	{
		*count += 1;
		zero++;
	}
	if (s->width > 1)
		str = charwidth(str, s);
	if (zero && s->eksi)
		ft_putchar_fd(0, 1);
	ft_putstr_fd(str, 1);
	free(str);
	*count += ft_strlen(str);
	if (zero && !s->eksi)
		ft_putchar_fd(0, 1);
}

char	*nbrprec(t_specs *s, char *str)
{
	char	*add;
	int		len;

	len = ft_strlen(str);
	if (s->precision == -1 && !ft_atoi(str))
		str[0] = 0;
	if (s->arti && ft_atoi(str) >= 0 && s->format != 'u')
		str = freejoin(ft_strdup("+"), str);
	if (s->precision > len)
	{
		add = ft_calloc(sizeof(*add), (s->precision - len) + 1);
		strfill(add, '0', s->precision - len);
		str = freejoin(add, str);
	}
	if (s->bosluk && !s->arti && ft_atoi(str) >= 0 && s->format != 'u')
		str = freejoin(ft_strdup(" "), str);
	str = nbrwidth(s, str);
	return (str);
}

char	*strprec(t_specs *s, char *str)
{
	int		len;
	char	*tmp;

	if (s->precision == -1)
		str[0] = 0;
	len = ft_strlen(str);
	if (s->precision < len && s->precision)
	{
		tmp = str;
		str = ft_substr(str, 0, s->precision);
		free(tmp);
	}
	str = strwidth(s, str);
	return (str);
}

char	*hexprec(t_specs *s, char *str)
{
	int		len;
	char	*add;

	if (s->precision == -1 && !ft_atoi(str))
		str[0] = 0;
	len = ft_strlen(str);
	if (s->precision > len)
	{
		add = ft_calloc(sizeof(*add), (s->precision - len) + 1);
		strfill(add, '0', s->precision - len);
		str = freejoin(add, str);
	}
	if (s->format == 'p' || (!charcheck(str, '0') && s->kare))
		str = freejoin(ft_strdup("0x"), str);
	str = hexwidth(s, str);
	return (str);
}
