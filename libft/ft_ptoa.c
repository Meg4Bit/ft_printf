/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 01:01:15 by ametapod          #+#    #+#             */
/*   Updated: 2020/06/14 15:47:06 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ptoa_len(unsigned long long n)
{
	int		len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 16;
		len++;
	}
	return (len);
}

char		*ft_ptoa(unsigned long long n)
{
	char	*str;
	int		len;
	int		mod;

	len = ptoa_len(n);
	len += 2;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[0] = '0';
	str[1] = 'x';
	str[2] = '0';
	str[len--] = 0;
	while (n)
	{
		if ((mod = (n % 16)) < 10)
			str[len--] = mod + '0';
		else
			str[len--] = mod + 87;
		n /= 16;
	}
	return (str);
}
