/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailleu <tbailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 15:15:26 by tbailleu          #+#    #+#             */
/*   Updated: 2018/01/05 13:14:45 by tbailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

size_t		ft_wcharlen(wchar_t w)
{
	if (w <= 0x7F)
		return (1);
	else if (w <= 0x7FF)
		return (2);
	else if (w <= 0xFFFF)
		return (3);
	else if (w <= 0x10FFFF)
		return (4);
	return (-1);
}

size_t		ft_wstrlen(wchar_t *wstr)
{
	int		i;
	size_t	len;

	if (wstr)
	{
		i = 0;
		len = 0;
		while (wstr[i])
		{
			len += ft_wcharlen(wstr[i]);
			i++;
		}
		return (len);
	}
	return (0);
}
