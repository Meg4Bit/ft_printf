/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_acc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 15:38:04 by ametapod          #+#    #+#             */
/*   Updated: 2020/06/13 15:38:04 by ametapod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_acc(va_list tmp, char *acc)
{
	int		i;

	if (*acc != '.')
		return (0);
	acc++;
	if (*acc == '*')
		i = va_arg(tmp, int);
	else
		i = ft_atoi(acc);
	return (i);
}
