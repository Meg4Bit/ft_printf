/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flag_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 14:47:56 by ametapod          #+#    #+#             */
/*   Updated: 2020/06/16 14:47:56 by ametapod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	apply_point()
{
	return (1);
}

static int	apply_decimal(char **line, int *farr)
{
	char *join;

	if (farr[1])
	{
		if (**line != '-')
		{
			if (!(join = ft_strjoin("+", *line)))
				return (0);
			free(*line);
			*line = join;
		}
	}
	else if (!farr[1] && farr[2] && **line != '-')
	{
		if (!(join = ft_strjoin(" ", *line)))
			return (0);
		free(*line);
		*line = join;
	}
	return (1);
}

static int	apply_hashtag(char **line, int *farr, char *type)
{
	char *join;
	char *x;

	if (!farr[3])
		return (1);
	if ((ft_strchr(type, 'x') || ft_strchr(type, 'X')) && **line &&\
			**line != '0')
	{
		x = "0x";
		if (ft_strchr(type, 'X'))
			x = "0X";
		if (!(join = ft_strjoin(x, *line)))
			return (0);
		free(*line);
		*line = join;
	}
	else
		if (!(apply_point(line, type)))
			return (0);
	return (1);
}

int			apply_flag_bonus(char **line, int *farr, char *type)
{
	char *decimal;
	char *hashtag;

	decimal = "diuefg";
	hashtag = "xXefg";
	while (*decimal)
		if (ft_strchr(type, *decimal++))
			if(apply_decimal(line, farr) != 1)
				return (0);
	while (*hashtag)
		if (ft_strchr(type, *hashtag++))
			if(apply_hashtag(line, farr, type) != 1)
				return (0);
	return (1);
}
