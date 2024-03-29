/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnrcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@student.42kocaeli.com.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 10:29:46 by hsozan            #+#    #+#             */
/*   Updated: 2022/01/16 10:30:06 by hsozan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: N/A
** SYNOPSIS: reversely compare strings (size-bounded)
**
** DESCRIPTION:
** 		The strnrcmp() function lexicographically compare the null-terminated
**	strings s1 and s2.
** 		The strnrcmp() function reversely compares not more than n characters.
**	Because strnrcmp() is designed for comparing strings rather than binary
**	data, characters that appear after a `\0' character are not compared.
*/

#include "libft.h"

int	ft_strnrcmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	if (n == 0)
		return (0);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	while (s1[--i] == s2[--j] && i >= 0 && j >= 0)
	{
		n--;
		if (n == 0)
			return (0);
	}
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[j]));
}
