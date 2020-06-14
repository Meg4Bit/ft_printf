/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_acc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 22:27:08 by ametapod          #+#    #+#             */
/*   Updated: 2020/06/11 22:27:08 by ametapod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			check_acc(const char **format, char **percent)
{
	char	*join;

	if (**format != '.')
		return (1);
	if (!(join = ft_strjoin(*percent, ".")))
		return (0);
	free(*percent);
	*percent = join;
	(*format)++;
	if (!(check_width(format, percent)))
		return (0);
	return (1);
}
