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

static char	*bonus_type(char *type, va_list *tmp, int acc, int len)
{
	char	*line;

	if (*type == 'f')
		line = ft_float(tmp, acc);
	else if (*type == 'e')
		line = ft_efloat(tmp, acc);
	else if (*type == 'g')
		line = ft_gfloat(tmp, acc);
	else if (ft_strchr(type, 'n'))
		line = ft_n(tmp, type, len);
	else
		line = (char *)ft_calloc(1, sizeof(char));
	return (line);
}

char		*ft_print_type(char *type, va_list *tmp, int acc, int len)
{
	char	*line;

	if (ft_strchr(type, 'c'))
		line = ft_char(tmp);
	else if (ft_strchr(type, 's'))
		line = ft_string(tmp, acc);
	else if (ft_strchr(type, 'p'))
		line = ft_pointer(tmp, acc);
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
		line = bonus_type(type, tmp, acc, len);
	return (line);
}
