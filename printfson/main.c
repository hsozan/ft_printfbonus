#include"ft_printf.h"
#include<stdio.h>

int main()
{
	int a;
	/*printf("ORJİNAL :\n");
	printf("printf'in int değeri :|%i|\n",printf("10luk 16lık ve 8lik '100':|%d|\t|%x|\t|%o|\nkareli\t\t\t :|%#d|\t|%#x|\t|%#o|\n", 100, 100, 100, 100, 100,100));
	printf("|%i|\n",printf("|%c|\n----\n",'c'));
	ft_printf("BENİMKİ :\n");
	ft_printf("ft_printf'in int değeri :|%i|\n",ft_printf("10luk 16lık ve 8lik '100':|%d|\t|%x|\t|%o|\nkareli\t\t\t :|%#d|\t|%#x|\t|%#o|\n", 100, 100, 100, 100, 100,100));
	ft_printf("|%i|\n",ft_printf("|%c|\n",'c'));*/
	printf ("Preceding with empty spaces: %10d \n", 1997);
	printf ("Preceding with zeros: %010d \n", 1997);
	printf ("Width: %*d \n", 5,15);
	printf("_____________________________________________\n");
	ft_printf ("Preceding with empty spaces: %10d \n", 1997);
	ft_printf ("Preceding with zeros: %010d \n", 1997);
	ft_printf ("Width: %*d \n", 5,15);
	 char str[] = "123456";
    /*printf("%20s\n", str);
	printf("%+20s\n", str);
    printf("%-1s\n", str);
    printf("%20.5s\n", str);
    printf("%-20.5s\n", str);
    ft_printf("%20s\n", str);
	ft_printf("%+20s\n", str);
    ft_printf("%-1s\n", str);
    ft_printf("%20.5s\n", str);
    ft_printf("%-20.5s\n", str);*/
	//ft_printf("\n\n%i",-12);
	//ft_printf("%s\n%i\n",ft_itoa(666),ft_printf("%u\n",5323));
	//printf("# %s\n%i\n",ft_itoa(666),printf("%u\n",5323));
		
}
