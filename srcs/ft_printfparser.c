/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfparser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailleu <tbailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 09:33:49 by tbailleu          #+#    #+#             */
/*   Updated: 2018/01/06 10:08:35 by tbailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*ft_printf_parse_flags(char **format, t_data *data)
{
	if (**format == '#' || **format == '0' || **format == '-' ||
			**format == '+' || **format == ' ')
	{
		if (**format == '#')
			data->prefix = 1;
		else if (**format == '0')
			data->zero_pad = 1;
		else if (**format == '-')
			data->right_pad = 1;
		else if (**format == '+')
			data->force_sign = 1;
		else if (**format == ' ')
			data->no_sign = 1;
		(*format)++;
		if (data->right_pad)
			data->zero_pad = 0;
		return (ft_printf_parse_flags(format, data));
	}
	return (*format);
}

char	*ft_printf_parse_accuracy(char **format, va_list *list, t_data *data)
{
	int acc;

	if (**format == '.')
	{
		while (*(++*format) == '.')
			;
		if (**format == '*')
		{
			(*format)++;
			if ((acc = va_arg(*list, int)) >= 0)
			{
				data->got_accuracy = 1;
				data->accuracy = acc;
			}
			return (*format);
		}
		else
		{
			while (ft_isdigit(**format) || (**format == '-' && (*format)++))
				data->accuracy = data->accuracy * 10 + (*(*format)++ - '0');
			data->got_accuracy = 1;
			return (*format);
		}
	}
	return (*format);
}

char	*ft_printf_parse_width(char **format, va_list *list, t_data *data)
{
	int		got;

	data->width = 0;
	while (**format == '*' || ft_isdigit(**format))
	{
		if (**format == '*')
		{
			(*format)++;
			got = va_arg(*list, int);
			if (got < 0)
				data->right_pad = 1;
			data->width = (got < 0) ? -got : got;
			data->got_width = 1;
		}
		if (ft_isdigit(**format))
		{
			data->got_width = 1;
			data->width = 0;
			while (ft_isdigit(**format))
				data->width = data->width * 10 + (*(*format)++ - '0');
		}
	}
	return (*format);
}

char	*ft_printf_parse_length(char **format, t_data *data)
{
	if (**format == 'h' && *(*format + 1) == 'h')
	{
		data->length = 6;
		return (*format += 2);
	}
	else if (**format == 'l' && *(*format + 1) == 'l')
	{
		data->length = 5;
		return (*format += 2);
	}
	else if (**format == 'h' || **format == 'l' || **format == 'j' ||
			**format == 'z')
	{
		if (**format == 'h')
			data->length = 1;
		else if (**format == 'l')
			data->length = 2;
		else if (**format == 'j')
			data->length = 3;
		else if (**format == 'z')
			data->length = 4;
		return ((*format)++);
	}
	return (*format);
}
