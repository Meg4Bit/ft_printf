/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_zeros.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 18:26:56 by ametapod          #+#    #+#             */
/*   Updated: 2020/06/13 18:26:56 by ametapod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	skip_format(char *line, char *tmp, int *i)
{
	char *small;
	char *big;

	small = "0x";
	big = "0X";
	if (ft_strnstr(line, small, 2) || ft_strnstr(line, big, 2))
		while (*i < 2)
			tmp[(*i)++] = *line++;
}

int		ft_add_zeros(int acc, char **line, int skip)
{
	char	*tmp;
	int		i;
	int		j;
	int		len;

	i = 0;
	if (**line == '-' && skip)
		acc++;
	if ((size_t)acc <= ft_strlen(*line))
		return (1);
	len = acc - ft_strlen(*line);
	if (!(tmp = (char *)ft_calloc(acc + 1, sizeof(char))))
		return (0);
	if (**line == '-' || **line == '+' || **line == ' ')
		tmp[i++] = **line;
	skip_format(*line, tmp, &i);
	j = i;
	while (len--)
		tmp[i++] = '0';
	while ((*line)[j])
		tmp[i++] = (*line)[j++];
	free(*line);
	*line = tmp;
	return (1);
}
