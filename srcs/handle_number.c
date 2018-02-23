/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailleu <tbailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 13:05:08 by tbailleu          #+#    #+#             */
/*   Updated: 2018/01/05 14:00:30 by tbailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

ssize_t				ft_printf_handle_longer(char **format, va_list *args,
		t_data *data)
{
	uintmax_t				nbr;

	(void)format;
	if (data->got_accuracy)
		data->zero_pad = 0;
	nbr = ft_printf_get_unsigned_from_length(args, data);
	return (ft_printfu(nbr, data, "0123456789", NULL));
}

ssize_t				ft_printf_handle_long(char **format, va_list *args,
		t_data *data)
{
	data->length = 2;
	return (ft_printf_get_handler(ft_tolower(**format))(format, args, data));
}

ssize_t				ft_printf_handle_int(char **format, va_list *args,
		t_data *data)
{
	intmax_t				nbr;
	char					*prefix;

	(void)format;
	if (data->got_accuracy)
		data->zero_pad = 0;
	nbr = ft_printf_get_signed_from_length(args, data);
	if (nbr < 0 || data->force_sign || data->no_sign)
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			prefix = "-";
		}
		else if (data->force_sign)
			prefix = "+";
		else if (data->no_sign)
			prefix = " ";
		else
			prefix = "";
		return (ft_printf_nbrprefix(nbr, "0123456789", data, prefix));
	}
	else
		return (ft_printfu(nbr, data, "0123456789", NULL));
}

ssize_t				ft_printf_handle_octal(char **format, va_list *args,
		t_data *data)
{
	uintmax_t	nbr;

	(void)format;
	nbr = ft_printf_get_unsigned_from_length(args, data);
	if (data->prefix && !nbr &&
			data->got_accuracy && !data->accuracy)
	{
		if (data->got_width && !data->right_pad)
			ft_printf_width_pad(1, data->width, data->zero_pad ? '0' : ' ');
		ft_putstr("0");
		if (data->got_width && data->right_pad)
			ft_printf_width_pad(1, data->width, ' ');
		return (data->got_width ? ft_minmax(1, data->width, 1) : 1);
	}
	else if (data->prefix && nbr)
	{
		data->got_accuracy = 1;
		data->accuracy = ft_minmax(1, data->accuracy,
			ft_nbrlen_base(nbr, "01234567") + 1);
	}
	return (ft_printfu(nbr, data, "01234567", NULL));
}

ssize_t				ft_printf_handle_hexa(char **format, va_list *args,
		t_data *data)
{
	uintmax_t	nbr;
	char		*base;
	char		*prefix;

	nbr = ft_printf_get_unsigned_from_length(args, data);
	if (**format == 'X')
	{
		base = "0123456789ABCDEF";
		prefix = "0X";
	}
	else
	{
		base = "0123456789abcdef";
		prefix = "0x";
	}
	if (data->prefix && nbr)
		return (ft_printf_nbrprefix(nbr, base, data, prefix));
	return (ft_printfu(nbr, data, base, prefix));
}
