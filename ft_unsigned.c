/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 19:43:59 by ametapod          #+#    #+#             */
/*   Updated: 2020/06/12 19:43:59 by ametapod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_unsigned(va_list *tmp, int acc)
{
	unsigned	i;
	char		*line;

	i = va_arg(*tmp, unsigned);
	if (acc == 0 && i == 0)
		line = (char *)ft_calloc(1, sizeof(char));
	else
		line = ft_utoa(i);
	return (line);
}
