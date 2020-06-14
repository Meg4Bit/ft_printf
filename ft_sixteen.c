/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sixteen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 19:44:14 by ametapod          #+#    #+#             */
/*   Updated: 2020/06/12 19:44:14 by ametapod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_sixteen(va_list *tmp, int acc)
{
	unsigned	u;
	char		*line;

	u = va_arg(*tmp, unsigned);
	if (acc == 0 && u == 0)
		line = (char *)ft_calloc(1, sizeof(char));
	else
		line = ft_xtoa(u);
	return (line);
}
