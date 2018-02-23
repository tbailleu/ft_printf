/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailleu <tbailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 18:51:00 by tbailleu          #+#    #+#             */
/*   Updated: 2017/11/26 19:43:14 by tbailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		ft_putnchar(char c, int *n)
{
	int i;

	i = *n;
	while (--(*n) >= 0)
		ft_putchar(c);
	return (i);
}
