/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 12:55:58 by ametapod          #+#    #+#             */
/*   Updated: 2020/06/22 16:40:49 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_mod(const char **format, char **percent, int iter, char *type)
{
	char *join;
	char *tmp;

	while (*type && iter < 2)
	{
		if (**format == *type)
		{
			if (!(tmp = (char *)ft_calloc(2, sizeof(char))))
				return (0);
			*tmp = *type;
			if (!(join = ft_strjoin(*percent, tmp)))
				return (ft_free_mem(tmp));
			free(*percent);
			free(tmp);
			*percent = join;
			(*format)++;
			return (check_mod(format, percent, ++iter, *percent));
		}
		type++;
	}
	return (1);
}

int			check_type(const char **format, char **percent)
{
	char *join;
	char *tmp;
	char *type;

	type = "nfgecspdiuxX%";
	if (check_mod(format, percent, 0, "lh") != 1)
		return (0);
	while (*type)
	{
		if (**format == *type)
		{
			if (!(tmp = (char *)ft_calloc(2, sizeof(char))))
				return (0);
			*tmp = *type;
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
