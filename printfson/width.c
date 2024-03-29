/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 03:52:18 by hsozan            #+#    #+#             */
/*   Updated: 2022/02/27 03:52:18 by hsozan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	strupper(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		str[i] = ft_toupper(str[i]);
}

char	*hexwidth(t_specs *s, char *str)
{
	char	*add;
	int		len;

	len = ft_strlen(str);
	if (s->width > len)
	{
		add = ft_calloc(sizeof(*add), (s->width - len) + 1);
		if (s->zero && !s->eksi && !s->precision)
			strfill(add, '0', s->width - len);
		else
			strfill(add, ' ', s->width - len);
		if (s->eksi)
			str = freejoin(str, add);
		else
			str = freejoin(add, str);
	}
	if (str[0] == '0' && str[1] == '0')
		charmod(&str[1], 'x');
	if (s->format == 'X')
		strupper(str);
	return (str);
}

char	*strwidth(t_specs *s, char *str)
{
	char	*add;
	int		len;

	len = ft_strlen(str);
	if (s->width > len)
	{
		add = ft_calloc(sizeof(*add), (s->width - len) + 1);
		if (s->zero && !s->eksi)
			strfill(add, '0', s->width - len);
		else
			strfill(add, ' ', s->width - len);
		if (s->eksi)
			str = freejoin(str, add);
		else
			str = freejoin(add, str);
	}
	return (str);
}

char	*nbrwidth(t_specs *s, char *str)
{
	char	*add;
	int		len;

	len = ft_strlen(str);
	if (s->width > len)
	{
		add = ft_calloc(sizeof(*add), (s->width - len) + 1);
		if (s->zero && !s->eksi && !s->precision)
			strfill(add, '0', s->width - len);
		else
			strfill(add, ' ', s->width - len);
		if (s->eksi)
			str = freejoin(str, add);
		else
			str = freejoin(add, str);
	}
	if (s->precision || s->zero)
		charmod(str, '-');
	if (s->arti)
		charmod(str, '+');
	if (s->bosluk)
		charmod(str, ' ');
	if (s->format != 'u' && s->precision)
		str = nbrmod(s, str);
	return (str);
}
