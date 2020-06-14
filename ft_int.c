/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 19:43:42 by ametapod          #+#    #+#             */
/*   Updated: 2020/06/12 19:43:42 by ametapod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_int(va_list *tmp, int acc)
{
	int		i;
	char	*line;

	i = va_arg(*tmp, int);
	if (acc == 0 && i == 0)
		line = (char *)ft_calloc(1, sizeof(char));
	else
		line = ft_itoa(i);
	return (line);
}
