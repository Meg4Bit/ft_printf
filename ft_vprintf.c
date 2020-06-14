/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 14:36:44 by ametapod          #+#    #+#             */
/*   Updated: 2020/06/09 14:36:44 by ametapod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	submit_percent(char **percent, va_list tmp, char **line)
{
	int		width;
	int		acc;
	char	*type;
	char	*join;

	width = ft_width(tmp, percent[1]);
	if ((acc = ft_acc(tmp, percent[2])) < 0)
		acc = 0;
	if (!(type = ft_print_type(percent[3], tmp)))
		return (0);
	if (!(ft_transform_type(&type, width, acc, percent)))
		return (ft_free_mem(type));
	if (!(join = ft_strjoin(*line, type)))
		return (ft_free_mem(type));
	free(*line);
	free(type);
	*line = join;
	return (1);
}

static int	write_percent(const char **format, va_list tmp, char **line)
{
	char	**percent;
	int		len;

	len = -1;
	if (!(percent = (char **)malloc(sizeof(char *) * 4)))
		return (0);
	while (++len < 4)
		if (!(percent[len] = (char *)ft_calloc(1, sizeof(char))))
			return (ft_free_arr((void **)percent, len));
	(*format)++;
	if (check_flag(format, percent) != 1)
		return (ft_free_arr((void **)percent, 4));
	if (check_width(format, percent + 1) != 1)
		return (ft_free_arr((void **)percent, 4));
	if (check_acc(format, percent + 2) != 1)
		return (ft_free_arr((void **)percent, 4));
	if (check_type(format, percent + 3) != 1)
		return (ft_free_arr((void **)percent, 4));
	if (submit_percent(percent, tmp, line) != 1)
		return (ft_free_arr((void **)percent, 4));
	ft_free_arr((void **)percent, 4);
	return (1);
}

static int	write_line(const char **format, va_list tmp, char **line)
{
	char	*sub;
	char	*join;

	if (!(sub = ft_substr(*format, 0, ft_strchr(*format, '%') - *format)))
		return (0);
	if (!(join = ft_strjoin(*line, sub)))
		return (ft_free_mem(sub));
	free(*line);
	free(sub);
	*line = join;
	*format = ft_strchr(*format, '%');
	if ((write_percent(format, tmp, line)) != 1)
		return (0);
	return (1);
}

int			ft_vprintf(const char *format, va_list tmp)
{
	char	*line;
	char	*ptr;
	int		len;

	if (!format)
		return (0);
	if (!(line = (char *)malloc(sizeof(char) * 1)))
		return (-1);
	*line = 0;
	while (ft_strchr(format, '%'))
		if (write_line(&format, tmp, &line) != 1)
			return (ft_free_mem(line));
	if (!(ptr = ft_strjoin(line, format)))
		return (ft_free_mem(line));
	free(line);
	line = ptr;
	ft_putstr_fd(line, 0);
	len = ft_strlen(line);
	free(line);
	return (len);
}
