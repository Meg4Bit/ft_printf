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

char		*ft_int(va_list *tmp, int acc, char *type)
{
	char		*line;

	if (ft_strnstr(type, "ll", 2))
		line = ft_llitoa(va_arg(*tmp, long long));
	else if (ft_strnstr(type, "hh", 2))
		line = ft_itoa((signed char)va_arg(*tmp, int));
	else if (ft_strnstr(type, "l", 1) && !ft_strnstr(type, "ll", 2))
		line = ft_llitoa(va_arg(*tmp, long));
	else if (ft_strnstr(type, "h", 1) && !ft_strnstr(type, "hh", 2))
		line = ft_itoa((short)va_arg(*tmp, int));
	else
		line = ft_itoa(va_arg(*tmp, int));
	if (line)
		if (acc == 0 && *line == '0')
		{
			free(line);
			line = (char *)ft_calloc(1, sizeof(char));
		}
	return (line);
}
