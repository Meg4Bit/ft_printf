/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flag_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 14:47:56 by ametapod          #+#    #+#             */
/*   Updated: 2020/06/22 16:44:03 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	delete_zeros(char **line, char *type)
{
	const char	*point;
	const char	*tmp;
	char		*sub;

	if (!(ft_strchr(type, 'g')))
		return (1);
	if (!(point = ft_strchr(*line, '.')))
		return (1);
	while (*(point + 1))
	{
		tmp = point + 1;
		if (!(tmp = ft_revstrchr(tmp, '0')))
		{
			if (*point != '.')
				point++;
			if (!(sub = ft_substr(*line, 0, point - *line)))
				return (0);
			free(*line);
			*line = sub;
			return (1);
		}
		point = tmp;
	}
	return (1);
}

static int	apply_point(char **line)
{
	char	*join;
	char	*tmp;

	if (ft_strchr(*line, '.'))
		return (1);
	if (ft_strchr(*line, 'e'))
	{
		if (!(join = ft_substr(*line, 0, ft_strchr(*line, 'e') - *line)))
			return (0);
		if (!(tmp = ft_strjoin(join, ".")))
			return (ft_free_mem(join));
		free(join);
		if (!(join = ft_strjoin(tmp, ft_strchr(*line, 'e'))))
			return (ft_free_mem(tmp));
		free(tmp);
	}
	else
	{
		if (!(join = ft_strjoin(*line, ".")))
			return (0);
	}
	free(*line);
	*line = join;
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
		return (delete_zeros(line, type));
	if ((ft_strchr(type, 'x') || ft_strchr(type, 'X')))
	{
		if (!(ft_revstrchr(*line, '0')))
			return (1);
		x = "0x";
		if (ft_strchr(type, 'X'))
			x = "0X";
		if (!(join = ft_strjoin(x, *line)))
			return (0);
		free(*line);
		*line = join;
	}
	else
	{
		if ((apply_point(line) != 1))
			return (0);
	}
	return (1);
}

int			apply_flag_bonus(char **line, int *farr, char *type)
{
	char *decimal;
	char *hashtag;

	decimal = "diuefg";
	hashtag = "xXefg";
	if (ft_strnstr(*line, "nan", 4) || ft_strnstr(*line, "inf", 4))
	{
		farr[3] = 0;
		farr[4] = 0;
	}
	while (*decimal)
		if (ft_strchr(type, *decimal++))
			if (apply_decimal(line, farr) != 1)
				return (0);
	while (*hashtag)
		if (ft_strchr(type, *hashtag++))
			if (apply_hashtag(line, farr, type) != 1)
				return (0);
	return (1);
}
