/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llxtoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 23:47:06 by ametapod          #+#    #+#             */
/*   Updated: 2020/06/16 23:47:06 by ametapod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	llxtoa_len(unsigned long long n)
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

char		*ft_llxtoa(unsigned long long n)
{
	char	*str;
	int		len;
	int		mod;

	len = llxtoa_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[0] = '0';
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
