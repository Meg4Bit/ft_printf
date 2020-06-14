/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sixteen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 19:44:46 by ametapod          #+#    #+#             */
/*   Updated: 2020/06/12 19:44:46 by ametapod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_big_sixteen(va_list tmp)
{
	char	*line;
	int		i;

	i = 0;
	if ((line = ft_sixteen(tmp)))
	{
		while (line[i])
		{
			line[i] = ft_toupper(line[i]);
			i++;
		}
	}
	return (line);
}
