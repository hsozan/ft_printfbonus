int	nbrcount(unsigned int n, int base)
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
int	*ft_neghandle(long long int n, char *input)
{
	char	*t1;
	char	*t2;

	if (n < 0)
	{
		n = -n;
		t1 = ft_putnbr(n, 10, input);
		if (!t1)
			return (0);
		t2 = t1;
		t1 = ft_strjoin("-", t2);
		free (t2);
		return (t1);
	}
	return (ft_putnbr(n, 10, input));
}

int	*ft_nbrtoa_toprint(unsigned int n, int base, const char *s)
{
	int		digits;
	char	*res;

	if (!n)
		return (putstr(ft_strdup("0")));
	digits = nbrcount(n, base);
	res = malloc(sizeof(*res) * (digits + 1));
	if (!res)
		return (0);
	res[digits] = '\0';
	while (--digits > -1)
	{
		if ((n % base) > 9)
			res[digits] = (n % base) + '0';
		else
			res[digits] = (n % base) + '0';
		n /= base;
	}
	return (putstr(res));
}