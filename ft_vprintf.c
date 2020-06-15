/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 14:36:44 by ametapod          #+#    #+#             */
/*   Updated: 2020/06/15 16:43:47 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	submit_percent(char **percent, va_list *tmp, char **line)
{
	int		width;
	int		acc;
	char	*type;
	char	*join;

	width = ft_width(tmp, percent[1]);
	acc = ft_acc(tmp, percent[2]);
	if (!(type = ft_print_type(percent[3], tmp, acc)))
		return (-1);
	if (percent[3][0] == 'c' && *type == 0)
		return (ft_fchar(&type, width, percent, line));
	if (!(ft_transform_type(&type, width, acc, percent)))
		return (ft_free_mem(type));
	if (!(join = ft_strjoin(*line, type)))
		return (ft_free_mem(type));
	free(*line);
	free(type);
	*line = join;
	ft_strlen(*line);
	return (0);
}

static int	write_percent(const char **format, va_list *tmp, char **line)
{
	char	**percent;
	int		len;
	int		fchar;

	len = -1;
	if (!(percent = (char **)malloc(sizeof(char *) * 4)))
		return (-1);
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
	if ((fchar = submit_percent(percent, tmp, line)) < 0)
		return (ft_free_arr((void **)percent, 4));
	ft_free_arr((void **)percent, 4);
	return (fchar);
}

static int	write_line(const char **format, va_list *tmp, char **line)
{
	char	*sub;
	char	*join;
	int		fchar;

	if (!(sub = ft_substr(*format, 0, ft_strchr(*format, '%') - *format)))
		return (-1);
	if (!(join = ft_strjoin(*line, sub)))
		return (ft_free_mem(sub));
	free(*line);
	free(sub);
	*line = join;
	*format = ft_strchr(*format, '%');
	if ((fchar = write_percent(format, tmp, line)) < 0)
		return (-1);
	return (fchar);
}

int			ft_vprintf(const char *format, va_list tmp, int len)
{
	char	*line;
	char	*ptr;
	int		fchar;
	va_list list;

	va_copy(list, tmp);
	if (!format)
		return (0);
	if (!(line = (char *)ft_calloc(1, sizeof(char))))
		return (-1);
	while (ft_strchr(format, '%'))
	{
		if ((fchar = write_line(&format, &list, &line)) < 0)
			return (ft_free_mem(line));
		len += fchar;
	}
	if (!(ptr = ft_strjoin(line, format)))
		return (ft_free_mem(line));
	free(line);
	ft_putstr_fd(ptr, 1);
	len += ft_strlen(ptr);
	free(ptr);
	va_end(list);
	return (len);
}
