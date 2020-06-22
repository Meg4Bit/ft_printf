/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 14:57:48 by ametapod          #+#    #+#             */
/*   Updated: 2020/06/18 14:57:48 by ametapod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_pow(int n, unsigned int pow)
{
	unsigned int	i;
	double			num;

	i = 0;
	num = 1;
	while (i++ < pow)
		num *= n;
	return (num);
}
