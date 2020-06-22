/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoe_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 00:41:56 by ametapod          #+#    #+#             */
/*   Updated: 2020/06/22 00:41:56 by ametapod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	add_e(char **line, int len)
{
	char *join;
	char *e;

	e = len < 0 ? "e-" : "e+";
	if (!(join = ft_strjoin(*line, e)))
		return (ft_free_mem(*line));
	free(*line);
	*line = join;
	len *= len < 0 ? -1 : 1;
	if (!(join = ft_itoa(len)))
		return (ft_free_mem(*line));
	if (!(ft_add_zeros(2, &join, 0)))
	{
		free(join);
		return (ft_free_mem(*line));
	}
	if (!(e = ft_strjoin(*line, join)))
	{
		free(join);
		return (ft_free_mem(*line));
	}
	free(*line);
	free(join);
	*line = e;
	return (1);
}

char		*ftoe(double n, int acc)
{
	char	*line;
	int		len;

	len = 0;
	if (n < 1 && n > -1)
		while (n < 1 && n > -1)
		{
			n *= 10;
			len++;
		}
	else
		while (n >= 10 || n <= -10)
		{
			n /= 10;
			len++;
		}
	if (!(line = ft_dtoa(n, acc)))
		return (0);
	if (add_e(&line, len) != 1)
		return (0);
	return (line);
}
