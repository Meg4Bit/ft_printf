/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 19:43:11 by ametapod          #+#    #+#             */
/*   Updated: 2020/06/12 19:43:11 by ametapod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_pointer(va_list tmp)
{
	unsigned long long	ull;
	char				*line;

	ull = va_arg(tmp, unsigned long long);
	line = ft_ptoa(ull);
	return (line);
}
