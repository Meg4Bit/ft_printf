/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 13:25:11 by ametapod          #+#    #+#             */
/*   Updated: 2020/06/18 13:25:11 by ametapod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_float(va_list *tmp, int acc)
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
		return (ft_dtoa(uf.f, acc));
}
