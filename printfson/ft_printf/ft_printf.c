#include"ft_printf.h"

int ft_sort(va_list arg,const char *input)
{
    /*int res;
    if(*input=='c')
        res+=ft_putchar(va_arg(arg,int));
    else if(*input=='s')
        res+=ft_putstr(va_arg(arg,char*));
    else if(*input=='d'||*input=='i')
        res+=ft_putnbr(va_arg(arg,int));
    else if(*input=='p')
        res+=ft_puthex(va_arg(arg,unsigned long long));
    else if(*input=='x'||*input=='X')
        res+=ft_puthex(va_arg(arg,unsigned long long));
    else if(*input=='u')
        res+=ft_putunbr(va_arg(arg,unsigned int));
    else if(*input=='%')
        res+=ft_putchar('%');
    return (res);*/
    char c=*input;
	if (c == 'd' || c == 'i')
		return (ft_neghandle(va_arg(arg, int), input));
	if (c == 'u')
		return (ft_nbrtoa_toprint(va_arg(arg, unsigned int), 10, input));
	if (c == 'x' || c == 'X')
		return (ft_nbrtoa_toprint(va_arg(arg, unsigned int), 16, input));
	if (c == 'p')
		return (ft_nbrtoa_toprint(va_arg(arg, unsigned long), 16, input));
	if (c == 'o')
		return (ft_nbrtoa_toprint(va_arg(arg, unsigned int), 8, input));
	if (c == 's')
		return (putstr(arg));
	if (c == 'c')
		return (chartostr(va_arg(arg, int)));
	if (c == '%')
		return (chartostr('%'));
	return (NULL);

}
int	ft_printf(const char *input, ...)
{
    va_list		args;
    int			res;

    va_start(args, input);
    while (*input)
    {
        if (*input == '%')
        {
            input++;
            res = ft_sort(&input, args);
        }
        else
            res = write(1, &*input, 1);
        input++;
    }
va_end(args);
return (res);
    
}