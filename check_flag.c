/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 00:18:26 by ametapod          #+#    #+#             */
/*   Updated: 2020/06/12 00:18:26 by ametapod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	add_flag(char *flag, char **percent)
{
	char *join;
	char *tmp;

	if (!(tmp = (char *)malloc(sizeof(char) * 2)))
		return (0);
	tmp[0] = *flag;
	tmp[1] = 0;
	if (!(join = ft_strjoin(*percent, tmp)))
		return (ft_free_mem(tmp));
	free(*percent);
	free(tmp);
	*percent = join;
	return (1);
}

static void	skip_symbol(char *line, const char **format)
{
	char *begin;

	begin = line;
	while (*line)
	{
		if (**format == *line)
		{
			(*format)++;
			line = begin;
		}
		else
			line++;
	}
}

int			check_flag(const char **format, char **percent)
{
	char *flag;
	char *begin;

	flag = "-0";
	begin = flag;
	while (*flag)
	{
		skip_symbol(*percent, format);
		if (**format == *flag)
		{
			if (add_flag(flag, percent) != 1)
				return (0);
			(*format)++;
			flag = begin;
		}
		else
			flag++;
	}
	return (1);
}
