/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llutoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 23:46:50 by ametapod          #+#    #+#             */
/*   Updated: 2020/06/16 23:46:50 by ametapod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	llutoa_len(unsigned long long n)
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

char		*ft_llutoa(unsigned long long n)
{
	char	*str;
	int		len;

	len = llutoa_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[0] = '0';
	str[len--] = 0;
	while (n)
	{
		str[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
