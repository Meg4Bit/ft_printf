/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 13:40:13 by ametapod          #+#    #+#             */
/*   Updated: 2020/06/22 13:40:13 by ametapod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_n(va_list *tmp, char *type, int len)
{
	char		*line;

	if (ft_strnstr(type, "ll", 2))
		*(va_arg(*tmp, long long *)) = len;
	else if (ft_strnstr(type, "hh", 2))
		*(va_arg(*tmp, signed char *)) = len;
	else if (ft_strnstr(type, "l", 1) && !ft_strnstr(type, "ll", 2))
		*(va_arg(*tmp, long *)) = len;
	else if (ft_strnstr(type, "h", 1) && !ft_strnstr(type, "hh", 2))
		*(va_arg(*tmp, short *)) = len;
	else
		*(va_arg(*tmp, int *)) = len;
	line = (char *)ft_calloc(1, sizeof(char));
	return (line);
}