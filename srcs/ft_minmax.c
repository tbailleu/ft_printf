/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailleu <tbailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 13:04:16 by tbailleu          #+#    #+#             */
/*   Updated: 2018/01/05 13:04:45 by tbailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

unsigned	ft_minmax(unsigned m, unsigned a, unsigned b)
{
	if (m)
		return (ft_max(a, b));
	return (ft_min(a, b));
}
