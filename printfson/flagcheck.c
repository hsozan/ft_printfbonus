/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagcheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 03:51:29 by hsozan            #+#    #+#             */
/*   Updated: 2022/02/27 03:51:29 by hsozan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	formatcheck(char c)
{
	if (c == 'c' || c == 's' || c == 'n' || c == 'd'
		|| c == 'i' || c == 'o' || c == 'x'
		|| c == 'X' || c == 'p' || c == 'f'
		|| c == 'u' || c == 'G' || c == 'g'
		|| c == 'e' || c == 'E' || c == '%')
		return (c);
	return (0);
}

int	flagcheck(char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '#'
		|| c == '0' || c == '*' || c == '.'
		|| c == 'l' || c == 'L' || c == 'h')
		return (c);
	if (ft_isdigit(c))
		return (c);
	return (0);
}

int	validitycheck(char *s)
{
	int	i;

	i = 0;
	while (s[i] && !formatcheck(s[i]))
	{
		if (!flagcheck(s[i]))
			return (i + 1);
		i++;
	}
	return (i + 1);
}

char	*paramaterfill(char *s)
{
	int		i;

	i = validitycheck(s);
	return (ft_substr(s, 0, i));
}
