/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 23:04:42 by ametapod          #+#    #+#             */
/*   Updated: 2020/06/16 23:04:42 by ametapod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	llitoa_len(long long n)
{
	int		len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_llitoa(long long n)
{
	char	*str;
	int		len;
	int		minus;

	minus = 1;
	len = llitoa_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		minus = -1;
	}
	str[len--] = 0;
	while (n)
	{
		str[len--] = (n % 10) * minus + '0';
		n /= 10;
	}
	return (str);
}
