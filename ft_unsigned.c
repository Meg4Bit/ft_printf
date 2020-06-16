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

char	*ft_unsigned(va_list *tmp, int acc, char *type)
{
	char		*line;

	if (ft_strnstr(type, "ll", 2))
		line = ft_llutoa(va_arg(*tmp, unsigned long long));
	else if (ft_strnstr(type, "hh", 2))
		line = ft_utoa((unsigned char)va_arg(*tmp, unsigned));
	else if (ft_strnstr(type, "l", 1) && !ft_strnstr(type, "ll", 2))
		line = ft_llutoa(va_arg(*tmp, unsigned long));
	else if (ft_strnstr(type, "h", 1) && !ft_strnstr(type, "hh", 2))
		line = ft_utoa((unsigned short)va_arg(*tmp, unsigned));
	else
		line = ft_utoa(va_arg(*tmp, unsigned));
	if (line)
		if (acc == 0 && *line == '0')
		{
			free(line);
			line = (char *)ft_calloc(1, sizeof(char));
		}
	return (line);
}
