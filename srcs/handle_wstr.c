/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailleu <tbailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 13:05:29 by tbailleu          #+#    #+#             */
/*   Updated: 2018/01/05 13:25:42 by tbailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void			ft_putnwstr(const wchar_t *str, size_t len)
{
	size_t	i;

	i = 0;
	while (*str && i < len)
	{
		if (*str <= 0x7F)
			i++;
		else if (*str <= 0x7FF)
			i += 2;
		else if (*str <= 0xFFFF)
			i += 3;
		else if (*str <= 0x10FFFF)
			i += 4;
		if (i <= len)
			ft_putwchar(*str++);
	}
}

ssize_t			ft_printf_handle_wchar(char **form, va_list *args, t_data *dat)
{
	wchar_t		chr;
	unsigned	len;

	(void)form;
	chr = (wchar_t)va_arg(*args, wint_t);
	len = 0;
	if (chr <= 0x7F)
		len = 1;
	else if (chr <= 0x7FF)
		len = 2;
	else if (chr <= 0xFFFF)
		len = 3;
	else if (chr <= 0x10FFFF)
		len = 4;
	if (dat->got_width && !dat->right_pad)
		ft_printf_width_pad(len, dat->width, dat->zero_pad ? '0' : ' ');
	ft_putwchar(chr);
	if (dat->got_width && dat->right_pad)
		ft_printf_width_pad(len, dat->width, dat->zero_pad ? '0' : ' ');
	return (dat->got_width ? ft_minmax(1, len, dat->width) : len);
}

static size_t	calc_wstrlen(wchar_t *str, int precision, size_t i)
{
	if (!*str || !precision)
		return (i);
	else if (*str <= 0x7F)
		return (calc_wstrlen(str + 1, precision - 1, i + 1));
	else if (*str <= 0x7FF && precision >= 2)
		return (calc_wstrlen(str + 1, precision - 2, i + 2));
	else if (*str <= 0xFFFF && precision >= 3)
		return (calc_wstrlen(str + 1, precision - 3, i + 3));
	else if (*str <= 0x10FFFF && precision >= 4)
		return (calc_wstrlen(str + 1, precision - 4, i + 4));
	else
		return (i);
}

ssize_t			ft_printf_handle_wstr(char **format, va_list *args,
		t_data *data)
{
	wchar_t	*str;
	size_t	strlen;

	(void)format;
	str = va_arg(*args, wchar_t*);
	if (!str)
		str = L"(null)";
	strlen = data->got_accuracy ? (size_t)(ft_minmax(0, calc_wstrlen(str,
		data->accuracy, 0), data->accuracy)) : ft_wstrlen(str);
	if (data->got_width && !data->right_pad)
		ft_printf_width_pad(strlen, data->width, data->zero_pad ? '0' : ' ');
	ft_putnwstr(str, strlen);
	if (data->got_width && data->right_pad)
		ft_printf_width_pad(strlen, data->width, ' ');
	return (data->got_width ? ft_minmax(1, strlen, data->width) : strlen);
}
