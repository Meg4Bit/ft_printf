#include <stdio.h>
#include "ft_printf.h"
#include <locale.h>
#include <wchar.h>

int main()
{
	setlocale(LC_ALL, "");
	int c = 1055;
	char b = 4;
	unsigned long long u = 18446744073709551615;
	ft_printf("%%-4i 42 == |%-4i|", 42);
	//printf("return :%d", printf("% .*x", 1, 32432423));
	//printf("return :%d", printf("%+010i", -1));
	//write(1, &b, 1);
	//printf("return :%d", printf("%s", line));
	//printf("return :%d", printf("%*ck%ss%d%10c", -1, '\0', "string", -100, 0));
	//printf("return :%d", printf("%hd", 32768));
	//printf("return :%d", printf("%hhx", 256));
	//printf("return :%d", ft_printf("%llu", u));
	//ft_printf("return :%d", ft_printf("%*ck%ss%d%10c", -1, '\0', "string", -100, 0));
	//printf("%5c", '\0');
	//ft_printf("%-5c", '\0');
}