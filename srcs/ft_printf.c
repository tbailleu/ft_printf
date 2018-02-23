/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailleu <tbailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 10:08:50 by tbailleu          #+#    #+#             */
/*   Updated: 2018/01/05 15:04:39 by tbailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int			handle_args(char **format, va_list *args, t_data *data)
{
	int			ret;
	t_handler	f;

	if (!(*(++*format)))
		return (0);
	if (!(ft_printf_parse_flags(format, data)) ||
			!(ft_printf_parse_width(format, args, data)) ||
			!(ft_printf_parse_flags(format, data)) ||
			!(ft_printf_parse_accuracy(format, args, data)) ||
			!(ft_printf_parse_flags(format, data)) ||
			!(ft_printf_parse_length(format, data)) ||
			!(ft_printf_parse_flags(format, data)))
		return (-1);
	if (!**format)
		return (0);
	if (!(f = ft_printf_get_handler(**format)))
		f = &ft_printf_handle_null;
	ret = f(format, args, data);
	(*format)++;
	return (ret);
}

int			my_printf(const char *format, va_list *args, int leng)
{
	char	*next;
	t_data	this_data;
	int		len;

	len = 0;
	next = ft_strchr(format, '%');
	if (!*format)
		return (leng);
	if (!next)
		return (leng + write(1, format, ft_strlen(format)));
	else if (next > format)
		return (my_printf(next, args, leng + write(1, format, next - format)));
	else
	{
		ft_bzero(&this_data, sizeof(this_data));
		if ((len = handle_args((char**)&format, args, &this_data)) == -1)
			return (-1);
		return (my_printf(format, args, leng + len));
	}
	return (-1);
}

int			ft_printf(const char *format, ...)
{
	va_list	args;
	int		result;

	va_start(args, format);
	result = my_printf(format, &args, 0);
	va_end(args);
	return (result);
}

static void	ft_putnbrbase_inner(uintmax_t nbr, char *base, t_data *data,
	uint32_t len)
{
	if (data->got_accuracy)
		ft_printf_width_pad(len, data->accuracy, base[0]);
	if (nbr != 0 || !data->got_accuracy || data->accuracy != 0)
		ft_putnbrbase(nbr, base);
}

ssize_t		ft_printfu(uintmax_t nbr, t_data *data, char *base, char *prefix)
{
	uint32_t	len;
	uint32_t	strlen;

	if (data->got_accuracy)
		data->zero_pad = 0;
	len = ft_nbrlen_base(nbr, base);
	if (data->got_width && !data->right_pad && data->zero_pad)
	{
		data->accuracy = ft_max(data->width, data->got_accuracy ?
			data->accuracy : len);
		data->got_accuracy = 1;
		data->got_width = 0;
	}
	strlen = ft_printf_maxstrlen(nbr, base, prefix, data);
	if (data->got_width && !data->right_pad)
		ft_printf_width_pad(strlen, data->width, ' ');
	if (data->prefix && prefix && nbr)
		ft_putstr(prefix);
	ft_putnbrbase_inner(nbr, base, data, len);
	if (data->got_width && data->right_pad)
		ft_printf_width_pad(strlen, data->width, ' ');
	return (data->got_width ? (ft_max(strlen, data->width)) : strlen);
}
