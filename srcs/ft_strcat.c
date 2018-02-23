/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailleu <tbailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:36:35 by tbailleu          #+#    #+#             */
/*   Updated: 2018/01/05 10:00:05 by tbailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*ft_strcat(char *dst, const char *src)
{
	char *start;

	start = dst;
	dst += ft_strlen(dst);
	if (src)
		while (*src)
			*dst++ = *src++;
	*dst = 0;
	return (start);
}
