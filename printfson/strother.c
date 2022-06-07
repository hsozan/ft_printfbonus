/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strother.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 03:52:12 by hsozan            #+#    #+#             */
/*   Updated: 2022/02/27 03:52:12 by hsozan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	specinit(t_specs *s)
{
	s->format = 0;
	s->width = 0;
	s->precision = 0;
	s->bosluk = 0;
	s->zero = 0;
	s->kare = 0;
	s->arti = 0;
	s->eksi = 0;
}

char	*strhandle(va_list v)
{
	char	*str;
	char	*tmp;

	tmp = va_arg(v, char *);
	if (!tmp)
		return (ft_strdup("(null)"));
	str = ft_strdup(tmp);
	if (!str)
		return (NULL);
	return (str);
}

char	*chartostr(char c)
{
	char	*str;

	str = malloc(sizeof(*str) * 2);
	if (!str)
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

int	charcheck(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != c)
			return (0);
		i++;
	}
	return (1);
}
