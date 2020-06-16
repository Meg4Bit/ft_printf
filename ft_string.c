/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 19:43:00 by ametapod          #+#    #+#             */
/*   Updated: 2020/06/12 19:43:00 by ametapod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_string(va_list *tmp, int acc)
{
	char	*str;
	char	*line;
	int		len;
	int		i;

	len = 0;
	i = 0;
	str = va_arg(*tmp, char *);
	if (!str)
		str = "(null)";
	if (acc >= 0)
	{
		while (len < acc && str[len])
			len++;
		if (!(line = (char *)ft_calloc(len + 1, sizeof(char))))
			return (NULL);
		while (i < len)
			line[i++] = *str++;
	}
	else
		line = ft_strdup(str);
	return (line);
}
