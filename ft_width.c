/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 15:37:50 by ametapod          #+#    #+#             */
/*   Updated: 2020/06/13 15:37:50 by ametapod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_width(va_list *tmp, char *width)
{
	int		i;

	if (*width == '*')
		i = va_arg(*tmp, int);
	else
		i = ft_atoi(width);
	return (i);
}
