/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 12:24:57 by ametapod          #+#    #+#             */
/*   Updated: 2020/06/09 12:24:57 by ametapod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *, ...);
int		ft_vprintf(const char *format, va_list tmp);
int		check_flag(const char **format, char **percent);
int		check_width(const char **format, char **percent);
int		check_acc(const char **format, char **percent);
int		check_type(const char **format, char **percent);
char	*ft_print_type(char *type, va_list tmp);
char	*ft_char(va_list tmp);
char	*ft_string(va_list tmp);
char	*ft_pointer(va_list tmp);
char	*ft_int(va_list tmp);
char	*ft_unsigned(va_list tmp);
char	*ft_sixteen(va_list tmp);
char	*ft_big_sixteen(va_list tmp);
char	*ft_percent();
int		ft_width(va_list tmp, char *width);
int		ft_acc(va_list tmp, char *acc);
int		ft_add_zeros(int acc, char **line, int skip);
int		ft_transform_type(char **type, int width, int acc, char **percent);

#endif