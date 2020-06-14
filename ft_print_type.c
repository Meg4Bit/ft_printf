/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 19:20:57 by ametapod          #+#    #+#             */
/*   Updated: 2020/06/12 19:20:57 by ametapod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_print_type(char *type, va_list *tmp, int acc)
{
	char	*line;

	if (*type == 'c')
		line = ft_char(tmp);
	else if (*type == 's')
		line = ft_string(tmp);
	else if (*type == 'p')
		line = ft_pointer(tmp);
	else if (*type == 'i' || *type == 'd')
		line = ft_int(tmp, acc);
	else if (*type == 'u')
		line = ft_unsigned(tmp, acc);
	else if (*type == 'x')
		line = ft_sixteen(tmp, acc);
	else if (*type == 'X')
		line = ft_big_sixteen(tmp, acc);
	else if (*type == '%')
		line = ft_percent();
	else
		line = (char *)ft_calloc(1, sizeof(char));
	return (line);
}
