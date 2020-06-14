/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 19:42:46 by ametapod          #+#    #+#             */
/*   Updated: 2020/06/12 19:42:46 by ametapod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_char(va_list tmp)
{
	char c;
	char *line;

	c = va_arg(tmp, int);
	if (!(line = (char *)ft_calloc(2, sizeof(char))))
		return (NULL);
	*line = c;
	return (line);
}
