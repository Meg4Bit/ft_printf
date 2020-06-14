/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 19:43:00 by ametapod          #+#    #+#             */
/*   Updated: 2020/06/12 19:43:00 by ametapod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_string(va_list tmp)
{
	char *str;
	char *line;

	str = va_arg(tmp, char *);
	if (!str)
		line = ft_strdup("(null)");
	else
		line = ft_strdup(str);
	return (line);
}
