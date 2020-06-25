/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gfloat_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 17:06:23 by ametapod          #+#    #+#             */
/*   Updated: 2020/06/21 17:06:23 by ametapod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	dtoa_len(double n)
{
	int		len;

	len = 0;
	while (n >= 1 || n <= -1)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*gtoa(double n, int acc)
{
	char	*line;
	int		len;

	len = dtoa_len(n);
	acc = acc ? acc : 1;
	if ((acc - len >= 0 && (n >= 0.0001 || n <= -0.0001)) || n == 0)
		line = ft_dtoa(n, acc - len);
	else
		line = ftoe(n, acc - 1);
	return (line);
}

char		*ft_gfloat(va_list *tmp, int acc)
{
	union u_float	uf;

	uf.f = va_arg(*tmp, double);
	if (acc < 0)
		acc = 6;
	if (uf.f != uf.f)
		if ((uf.ll & 0x8000000000000000ull) == 0)
			return (ft_strdup("nan"));
		else
			return (ft_strdup("-nan"));
	else if (uf.f > (1.7976931348623157e+308))
		return (ft_strdup("inf"));
	else if (uf.f < -(1.7976931348623157e+308))
		return (ft_strdup("-inf"));
	else
		return (gtoa(uf.f, acc));
}
