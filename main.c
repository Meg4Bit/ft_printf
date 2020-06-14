#include "ft_printf.h"
#include <stdio.h>

int main()
{
	//char *ptr = "d";
	int i = 255;
	ft_printf("kk%-04i[", i);
	printf("prt%*Xh", -9, 0);
	ft_printf("%*.*X", 0, 0, 0);
	ft_printf("st17 %0.*d\n", 0, 0);
	ft_printf("st8 %*.*s\n", 1, 0, "coucou");
	//ft_printf("st7 %*.*s\n", 1, 50, "hey");
	return 0;
}