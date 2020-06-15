/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 22:43:48 by ametapod          #+#    #+#             */
/*   Updated: 2020/06/16 00:08:38 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		put_null(int width, int minus, int null)
{
	int		len;
	char	ch;

	len = 1;
	if (width > 0)
		len = width;
	ch = ' ';
	if (null)
		ch = '0';
	if (minus)
	{
		ft_putchar_fd(0, 1);
		while (width-- > 1)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (width-- > 1)
			ft_putchar_fd(ch, 1);
		ft_putchar_fd(0, 1);
	}
	return (len);
}

int		ft_fchar(char **type, int width, char **percent, char **line)
{
	int		minus;
	int		null;
	int		len;
	char	*ptr;

	minus = 0;
	null = 0;
	if (width < 0)
	{
		width *= -1;
		minus = 1;
	}
	if (ft_strchr(percent[0], '-'))
		minus = 1;
	if (ft_strchr(percent[0], '0'))
		null = 1;
	if (!(ptr = (char *)ft_calloc(1, sizeof(char))))
		return (-1);
	ft_putstr_fd(*line, 1);
	len = ft_strlen(*line);
	free(*line);
	*line = ptr;
	free(*type);
	len += put_null(width, minus, null);
	return (len);
}
