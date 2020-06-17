/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revstrchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 13:27:02 by ametapod          #+#    #+#             */
/*   Updated: 2020/06/17 13:27:02 by ametapod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_revstrchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s != c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
