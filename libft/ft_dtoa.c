/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 20:57:29 by ametapod          #+#    #+#             */
/*   Updated: 2020/06/17 20:57:29 by ametapod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	dtoa_len(double n)
{
	int		len;

	len = 0;
	if (n < 1 && n > -1)
		len++;
	while (n >= 1 || n <= -1)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	check_rounding(double n, int len, int acc, int minus)
{
	int reminder;

	while (len--)
	{
		reminder = (int)(n / ft_pow(10, len));
		n = n - ((double)reminder * ft_pow(10, len));
	}
	while (acc--)
	{
		n *= 10;
		n = n - (int)n;
	}
	return (n * 10 * minus >= 5 ? 1 : 0);
}

static void	add_int(char *str, double *n, int len, int minus)
{
	int i;
	int reminder;

	i = 0;
	while (len--)
	{
		reminder = (int)(*n / ft_pow(10, len));
		str[i++] = reminder * minus + '0';
		*n = *n - ((double)reminder * ft_pow(10, len));
	}
}

static void	add_float(char *str, double n, int acc, int minus)
{
	int i;

	i = 0;
	str[i++] = '.';
	while (i < acc)
	{
		n *= 10;
		str[i++] = (int)n * minus + '0';
		n = n - (int)n;
	}
}

char		*ft_dtoa(double n, int acc)
{
	char	*str;
	int		len;
	int		minus;
	int		i;

	i = 0;
	len = dtoa_len(n);
	minus = n < 0 ? -1 : 1;
	if (check_rounding(n, len, acc, minus))
		n += ((double)(1 / ft_pow(10, acc)) * minus);
	acc += acc ? 1 : 0;
	len += n < 0 ? 1 : 0;
	if (!(str = (char *)calloc(len + acc + 1, sizeof(char))))
		return (0);
	if (n < 0)
	{
		str[i++] = '-';
		len--;
	}
	add_int(str + i, &n, len, minus);
	if (acc)
		add_float(str + i + len, n, acc, minus);
	return (str);
}
