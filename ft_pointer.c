/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 19:43:11 by ametapod          #+#    #+#             */
/*   Updated: 2020/06/12 19:43:11 by ametapod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_pointer(va_list *tmp, int acc)
{
	char	*line;
	char	*join;

	if (!(line = ft_llxtoa(va_arg(*tmp, unsigned long long))))
		return (0);
	if (acc > 0)
		if ((ft_add_zeros(acc, &line, 1)) != 1)
			return (0);
	if (acc == 0 && *line == '0')
	{
		free(line);
		if (!(line = (char *)ft_calloc(1, sizeof(char))))
			return (0);
	}
	join = ft_strjoin("0x", line);
	free(line);
	return (join);
}
