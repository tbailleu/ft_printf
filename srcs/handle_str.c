/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailleu <tbailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 13:05:23 by tbailleu          #+#    #+#             */
/*   Updated: 2018/01/05 14:03:28 by tbailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

ssize_t	ft_printf_handle_char(char **format, va_list *args, t_data *data)
{
	(void)format;
	if (data->length == 2)
		return (ft_printf_handle_wchar(format, args, data));
	else
	{
		if (data->got_width && !data->right_pad)
			ft_printf_width_pad(1, data->width, data->zero_pad ? '0' : ' ');
		ft_putchar(va_arg(*args, int));
		if (data->got_width && data->right_pad)
			ft_printf_width_pad(1, data->width, ' ');
		return (data->got_width ? ft_minmax(1, data->width, 1) : 1);
	}
}

ssize_t	ft_printf_handle_str(char **format, va_list *args, t_data *data)
{
	char	*str;
	size_t	strlength;

	if (data->length == 2)
		return (ft_printf_handle_wstr(format, args, data));
	else
	{
		str = va_arg(*args, char*);
		if (!str)
			str = "(null)";
		strlength = data->got_accuracy ? (size_t)(ft_minmax(0, ft_strlen(str),
					data->accuracy)) : ft_strlen(str);
		if (data->got_width && !data->right_pad)
			ft_printf_width_pad(strlength, data->width, data->zero_pad ?
					'0' : ' ');
		write(1, str, strlength);
		if (data->got_width && data->right_pad)
			ft_printf_width_pad(strlength, data->width, ' ');
		return ((data->got_width) ? ft_minmax(1, strlength, data->width) :
			strlength);
	}
	return (ft_strlen(str));
}
