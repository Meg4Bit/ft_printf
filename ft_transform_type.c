/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 16:51:59 by ametapod          #+#    #+#             */
/*   Updated: 2020/06/14 15:48:36 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*join_width(char **line, char *tmp, int *farr, char **percent)
{
	char	*type;
	char	*dup;

	type = "pdiuxX";
	if (farr[0])
		return (ft_strjoin(*line, tmp));
	if (farr[4])
	{
		if (percent[2][0] == '.')
			while (*type)
				if (ft_strchr(percent[3], *type++))
					return (ft_strjoin(tmp, *line));
		if ((ft_add_zeros(ft_strlen(*line) + ft_strlen(tmp), line, 0)) != 1)
			return (0);
		dup = ft_strdup(*line);
		return (dup);
	}
	return (ft_strjoin(tmp, *line));
}

static int	apply_width(char **line, int width, int *farr, char **percent)
{
	char	*tmp;
	char	*join;
	int		len;

	len = width - ft_strlen(*line);
	if (len <= 0)
		return (1);
	if (!(tmp = ft_calloc(len + 1, sizeof(char))))
		return (0);
	ft_memset(tmp, ' ', len);
	if (!(join = join_width(line, tmp, farr, percent)))
		return (ft_free_mem(tmp));
	free(*line);
	free(tmp);
	*line = join;
	return (1);
}

static int	apply_flag(char **line, int width, char **percent)
{
	int		*farr;
	int		i;
	char	*flag;

	flag = "-+ #0";
	i = -1;
	if (!(farr = (int *)ft_calloc(5, sizeof(int))))
		return (0);
	if (width < 0)
	{
		width *= -1;
		farr[0] = 1;
	}
	while (flag[++i])
		if (ft_strchr(percent[0], flag[i]))
			farr[i] = 1;
	if (apply_flag_bonus(line, farr, percent[3]) != 1)
		return (ft_free_mem(farr));
	if (apply_width(line, width, farr, percent) != 1)
		return (ft_free_mem(farr));
	free(farr);
	return (1);
}

static int	apply_acc(char **line, int acc, char *type)
{
	if (acc < 0)
		return (1);
	if (ft_strchr(type, 'd') || ft_strchr(type, 'i') || ft_strchr(type, 'u')\
			|| ft_strchr(type, 'x') || ft_strchr(type, 'X'))
	{
		if ((ft_add_zeros(acc, line, 1)) != 1)
			return (0);
	}
	return (1);
}

int			ft_transform_type(char **type, int width, int acc, char **percent)
{
	if (percent[2][0] == '.')
		if ((apply_acc(type, acc, percent[3])) != 1)
			return (0);
	if ((apply_flag(type, width, percent)) != 1)
		return (0);
	return (1);
}
