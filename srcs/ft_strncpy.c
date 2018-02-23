/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailleu <tbailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:33:47 by tbailleu          #+#    #+#             */
/*   Updated: 2017/11/25 10:12:19 by tbailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t counti;

	counti = 0;
	while (src[counti] != '\0' && counti < n)
	{
		dst[counti] = src[counti];
		counti++;
	}
	while (counti < n)
	{
		dst[counti] = '\0';
		counti++;
	}
	return (dst);
}
