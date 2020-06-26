/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 20:57:29 by ametapod          #+#    #+#             */
/*   Updated: 2020/06/25 12:53:33 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static int	ft_round(char *str)
{
	int i;

	i = 0;
	ft_strrev(str);
	str[i]++;
	while (str[i])
	{
		i += str[i] == '.' ? 1 : 0;
		if (str[i] > '9')
		{
			str[i] = '0';
			if (str[i + 1] == '.')
				str[i + 2]++;
			else if (!str[i + 1] || str[i + 1] == '-')
			{
				if (str[i + 1] == '-')
					str[i + 2] = '-';
				str[i + 1] = '1';
			}
			else
				str[i + 1]++;
		}
		i++;
	}
	return (ft_strrev(str) ? 1 : 0);
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

static void	add_float(char *str, double *n, int acc, int minus)
{
	int			i;
	long long	ll;

	i = 0;
	str[i++] = '.';
	if (acc < 20)
	{
		*n *= ft_pow(10, acc - 1);
		ll = *n;
		*n -= ll;
		while (acc-- > 1)
		{
			str[acc] = (ll % 10) * minus + '0';
			ll /= 10;
		}
	}
	else
		while (i < acc)
		{
			*n *= 10;
			str[i++] = (int)(*n) * minus + '0';
			*n = *n - (int)(*n);
		}
}

char		*ft_dtoa(double n, int acc)
{
	union u_float	uf;
	char			*str;
	int				len;
	int				minus;
	int				i;

	i = 0;
	uf.f = n;
	len = dtoa_len(n);
	minus = n < 0 || (uf.ll & 0x8000000000000000ull) ? -1 : 1;
	acc += acc ? 1 : 0;
	len += n < 0 || (uf.ll & 0x8000000000000000ull) ? 1 : 0;
	if (!(str = (char *)calloc(len + acc + 2, sizeof(char))))
		return (0);
	if (minus < 0)
	{
		str[i++] = '-';
		len--;
	}
	add_int(str + i, &n, len, minus);
	if (acc)
		add_float(str + i + len, &n, acc, minus);
	if (n * 10 * minus >= 5)
		ft_round(str);
	return (str);
}
