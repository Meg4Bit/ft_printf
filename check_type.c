/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 12:55:58 by ametapod          #+#    #+#             */
/*   Updated: 2020/06/12 12:55:58 by ametapod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_type(const char **format, char **percent)
{
	char *join;
	char *tmp;
	char *type;

	type = "cspdiuxX%";
	while (*type)
	{
		if (**format == *type)
		{
			if (!(tmp = (char *)malloc(sizeof(char) * 2)))
				return (0);
			tmp[0] = *type;
			tmp[1] = 0;
			if (!(join = ft_strjoin(*percent, tmp)))
				return (ft_free_mem(tmp));
			free(*percent);
			free(tmp);
			*percent = join;
			(*format)++;
			return (1);
		}
		type++;
	}
	return (1);
}