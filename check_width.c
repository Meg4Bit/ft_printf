/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 22:27:18 by ametapod          #+#    #+#             */
/*   Updated: 2020/06/11 22:27:18 by ametapod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	add_star(const char **format, char **percent)
{
	char *join;

	if (!(join = ft_strjoin(*percent, "*")))
		return (0);
	free(*percent);
	*percent = join;
	(*format)++;
	return (1);
}

int			check_width(const char **format, char **percent)
{
	char	*tmp;
	char	*join;
	int		len;

	len = 0;
	if (**format == '*')
		return (add_star(format, percent));
	while (ft_isdigit((*format)[len]))
		len++;
	if (!(tmp = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	len = 0;
	while (ft_isdigit(**format))
		tmp[len++] = *(*format)++;
	tmp[len] = 0;
	if (!(join = ft_strjoin(*percent, tmp)))
		return (ft_free_mem(tmp));
	free(*percent);
	free(tmp);
	*percent = join;
	return (1);
}
