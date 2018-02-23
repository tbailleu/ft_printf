/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailleu <tbailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 13:23:49 by tbailleu          #+#    #+#             */
/*   Updated: 2018/01/05 15:00:46 by tbailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

uint32_t	ft_printf_maxstrlen(uintmax_t nb, char *base, char *p, t_data *data)
{
	uint32_t	len;
	uint32_t	result;

	len = ft_nbrlen_base(nb, base);
	if (!nb && data->got_accuracy && !data->accuracy)
		result = 0;
	else if (data->got_accuracy)
		result = ft_max(len, data->accuracy);
	else
		result = len;
	if (data->prefix && p && nb)
		result += ft_strlen(p);
	return (result);
}

void		ft_printf_width_pad(int nbrstrlen, int width, char padwith)
{
	while (nbrstrlen < width)
	{
		ft_putchar(padwith);
		nbrstrlen++;
	}
}

uintmax_t	ft_printf_get_unsigned_from_length(va_list *datas, t_data *data)
{
	uintmax_t	nbr;

	nbr = va_arg(*datas, uintmax_t);
	if (data->length == 6)
		nbr = (unsigned char)nbr;
	else if (data->length == 1)
		nbr = (unsigned short int)nbr;
	else if (data->length == 2)
		nbr = (unsigned long int)nbr;
	else if (data->length == 5)
		nbr = (unsigned long long int)nbr;
	else if (data->length == 3)
		nbr = (uintmax_t)nbr;
	else if (data->length == 4)
		nbr = (size_t)nbr;
	else
		nbr = (uint32_t)nbr;
	return (nbr);
}

intmax_t	ft_printf_get_signed_from_length(va_list *args, t_data *data)
{
	intmax_t	nbr;

	nbr = va_arg(*args, intmax_t);
	if (data->length == 6)
		nbr = (char)nbr;
	else if (data->length == 1)
		nbr = (short int)nbr;
	else if (data->length == 2)
		nbr = (long int)nbr;
	else if (data->length == 5)
		nbr = (long long int)nbr;
	else if (data->length == 3)
		nbr = (intmax_t)nbr;
	else if (data->length == 4)
		nbr = (size_t)nbr;
	else
		nbr = (int)nbr;
	return (nbr);
}

ssize_t		ft_printf_nbrprefix(uintmax_t nb, char *base, t_data *data, char *p)
{
	unsigned	len;
	size_t		cut;

	len = ft_printf_maxstrlen(nb, base, NULL, data) + ft_strlen(p);
	cut = ft_strlen(p);
	if (data->got_width && !data->right_pad && !data->zero_pad)
	{
		ft_printf_width_pad(len, data->width, ' ');
		cut += (data->width - len > 0) ? data->width - len : 0;
		data->got_width = 0;
	}
	else if (data->got_width)
		data->width -= ft_strlen(p);
	ft_putstr(p);
	return (ft_printfu(nb, data, base, NULL) + cut);
}
