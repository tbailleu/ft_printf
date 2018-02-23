/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailleu <tbailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:44:36 by tbailleu          #+#    #+#             */
/*   Updated: 2017/11/25 10:12:19 by tbailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *dest;
	unsigned char *sour;

	dest = (unsigned char *)dst;
	sour = (unsigned char *)src;
	if (dst > src)
	{
		dest += len - 1;
		sour += len - 1;
		while (len-- > 0)
			*dest-- = *sour--;
	}
	else
		ft_memcpy(dst, src, len);
	return ((void *)dst);
}
