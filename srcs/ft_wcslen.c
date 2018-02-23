/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcslen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailleu <tbailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 15:15:26 by tbailleu          #+#    #+#             */
/*   Updated: 2017/11/26 18:22:36 by tbailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

size_t		ft_wcslen(const wchar_t *s)
{
	const wchar_t *p;

	p = s;
	while (*p)
		p++;
	return (p - s);
}
