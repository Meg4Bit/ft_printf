/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 18:20:17 by ametapod          #+#    #+#             */
/*   Updated: 2020/06/12 18:20:17 by ametapod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_free_arr(void **content, int len)
{
	if (content)
	{
		while (len--)
		{
			free(content[len]);
			content[len] = NULL;
		}
		free(content);
	}
	return (-1);
}
