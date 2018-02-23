/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailleu <tbailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:29:42 by tbailleu          #+#    #+#             */
/*   Updated: 2017/11/28 13:26:39 by tbailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

size_t	ft_nbrlen(int n)
{
	size_t size;

	size = 0;
	if (n < 0)
		size++;
	while (n / 10 != 0)
	{
		n /= 10;
		size++;
	}
	size++;
	return (size);
}
