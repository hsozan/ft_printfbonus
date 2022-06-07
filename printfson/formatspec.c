/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatspec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 03:51:36 by hsozan            #+#    #+#             */
/*   Updated: 2022/03/01 02:21:46 by hsozan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	formatnull(const char *c, t_specs *s, int len, int *count)
{
	if (ft_isdigit(c[len + *count - 1]) || (!s->width && !len))
		return (len);
	while (s->width > 1)
	{
		if (s->zero)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		s->width--;
		*count += 1;
	}
	return (len - 1);
}

char	*formatstr(t_specs *s, char *s2)
{
	if (s->format == 's')
		return (strprec(s, s2));
	else if (s->format == 'x' || s->format == 'X' || s->format == 'p')
		return (hexprec(s, s2));
	else
		return (nbrprec(s, s2));
}

int	putnewstr(t_specs *s, va_list v, int *count, int len)
{
	char	*s2;

	s2 = printtype(s->format, v, s);
	if (!s2)
		return (0);
	if (s->format == 'c' || s->format == '%')
	{
		charprec(s, s2, count);
		return (len);
	}
	s2 = formatstr(s, s2);
	ft_putstr_fd(s2, 1);
	*count += ft_strlen(s2);
	free(s2);
	return (len);
}

int	formatspec(const char *c, t_specs *s, va_list v, int *count)
{
	char	*s1;
	int		len;

	s1 = paramaterfill((char *) c);
	if (!s1)
		return (0);
	len = ft_strlen(s1);
	flagfill(s, s1);
	if (!formatcheck(s1[len - 1]))
	{
		free(s1);
		return (formatnull(c, s, len, count));
	}
	s->format = s1[len - 1];
	free(s1);
	return (putnewstr(s, v, count, len));
}
