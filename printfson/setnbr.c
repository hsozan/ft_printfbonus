/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 03:52:05 by hsozan            #+#    #+#             */
/*   Updated: 2022/03/01 02:23:01 by hsozan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nbrcount(size_t n, int base)
{
	int	count;

	count = 0;
	while (n)
	{
		n /= base;
		count++;
	}
	return (count);
}

char	*ft_nbrtoa(size_t n, int base, t_specs *s)
{
	int		digits;
	char	*res;

	if (!n)
		return (ft_strdup("0"));
	digits = nbrcount(n, base);
	if (base == 8 && s->kare)
		digits++;
	res = malloc(sizeof(*res) * (digits + 1));
	if (!res)
		return (NULL);
	res[digits] = '\0';
	while (--digits > -1)
	{
		if ((n % base) > 9)
			res[digits] = (n % base) + 87;
		else
			res[digits] = (n % base) + '0';
		n /= base;
	}
	if (base == 8 && s->kare)
		res[digits] = 0;
	return (res);
}

char	*ft_neghandle(long long int n, t_specs *s)
{
	char	*t1;
	char	*t2;

	if (n < 0)
	{
		n = -n;
		t1 = ft_nbrtoa(n, 10, s);
		if (!t1)
			return (NULL);
		t2 = t1;
		t1 = ft_strjoin("-", t2);
		free (t2);
		return (t1);
	}
	return (ft_nbrtoa(n, 10, s));
}
