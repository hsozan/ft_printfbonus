/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 03:51:44 by hsozan            #+#    #+#             */
/*   Updated: 2022/03/01 02:22:25 by hsozan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*printtype(char c, va_list variable, t_specs *s)
{
	if (c == 'd' || c == 'i')
		return (ft_neghandle(va_arg(variable, int), s));
	if (c == 'u')
		return (ft_nbrtoa(va_arg(variable, unsigned int), 10, s));
	if (c == 'x' || c == 'X')
		return (ft_nbrtoa(va_arg(variable, unsigned int), 16, s));
	if (c == 'p')
		return (ft_nbrtoa(va_arg(variable, unsigned long), 16, s));
	if (c == 'o')
		return (ft_nbrtoa(va_arg(variable, unsigned int), 8, s));
	if (c == 's')
		return (strhandle(variable));
	if (c == 'c')
		return (chartostr(va_arg(variable, int)));
	if (c == '%')
		return (chartostr('%'));
	return (NULL);
}

int	ft_printf(const char *str, ...)
{
	t_specs	s;
	int		i;
	int		result;

	va_start(s.arg, str);
	result = 0;
	i = 0;
	while (str[i])
	{
		specinit(&s);
		if (str[i] == '%' && str[i++])
			i += formatspec(&str[i], &s, s.arg, &result);
		if (str[i] && str[i] != '%')
		{
			ft_putchar_fd(str[i], 1);
			i++;
			result++;
		}
	}
	va_end(s.arg);
	return (result);
}
