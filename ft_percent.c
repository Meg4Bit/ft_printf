/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 19:44:59 by ametapod          #+#    #+#             */
/*   Updated: 2020/06/14 15:51:01 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_percent(void)
{
	char *line;

	if (!(line = (char *)ft_calloc(2, sizeof(char))))
		return (NULL);
	*line = '%';
	return (line);
}
