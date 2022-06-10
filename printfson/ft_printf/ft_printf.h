# include <stdarg.h>
# include "libft/libft.h"

int	ft_printf(const char *input, ...);
int ft_sort(va_list arg,const char *input);
int	nbrcount(unsigned int n, int base);
int	*ft_neghandle(long long int n, char *input);
int	*ft_nbrtoa_toprint(unsigned int n, int base, const char *s);