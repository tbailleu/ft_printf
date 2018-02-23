/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_spec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailleu <tbailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 13:05:15 by tbailleu          #+#    #+#             */
/*   Updated: 2018/01/05 14:00:30 by tbailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

ssize_t	ft_printf_handle_ptr(char **format, va_list *args, t_data *data)
{
	(void)format;
	data->length = 4;
	if (data->got_accuracy)
		data->zero_pad = 0;
	return (ft_printf_nbrprefix(
				ft_printf_get_unsigned_from_length(args, data),
				"0123456789abcdef", data, "0x"));
}

ssize_t	ft_printf_handle_percent(char **format, va_list *args, t_data *data)
{
	(void)format;
	(void)args;
	if (data->got_width && !data->right_pad)
		ft_printf_width_pad(1, data->width, data->zero_pad ? '0' : ' ');
	ft_putchar('%');
	if (data->got_width && data->right_pad)
		ft_printf_width_pad(1, data->width, ' ');
	return (data->got_width ? ft_minmax(1, data->width, 1) : 1);
}

ssize_t	ft_printf_handle_null(char **format, va_list *args, t_data *data)
{
	(void)args;
	if (data->got_width && !data->right_pad)
		ft_printf_width_pad(1, data->width, data->zero_pad ? '0' : ' ');
	ft_putchar(**format);
	if (data->got_width && data->right_pad)
		ft_printf_width_pad(1, data->width, ' ');
	return (data->got_width ? ft_minmax(1, data->width, 1) : 1);
}
