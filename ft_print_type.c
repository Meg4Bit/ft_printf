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

	if (ft_strchr(type, 'c'))
		line = ft_char(tmp);
	else if (ft_strchr(type, 's'))
		line = ft_string(tmp, acc);
	else if (ft_strchr(type, 'p'))
		line = ft_pointer(tmp);
	else if (ft_strchr(type, 'i') || ft_strchr(type, 'd'))
		line = ft_int(tmp, acc, type);
	else if (ft_strchr(type, 'u'))
		line = ft_unsigned(tmp, acc, type);
	else if (ft_strchr(type, 'x'))
		line = ft_sixteen(tmp, acc, type);
	else if (ft_strchr(type, 'X'))
		line = ft_big_sixteen(tmp, acc, type);
	else if (ft_strchr(type, '%'))
		line = ft_percent();
	else
		line = (char *)ft_calloc(1, sizeof(char));
	return (line);
}
