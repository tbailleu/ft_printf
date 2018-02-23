/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailleu <tbailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 10:41:57 by tbailleu          #+#    #+#             */
/*   Updated: 2018/01/05 12:29:05 by tbailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

unsigned int	ft_nbrlen_base(uintmax_t nbr, char *base)
{
	size_t			base_nbr;
	unsigned int	i;

	base_nbr = ft_strlen(base);
	i = 0;
	if (!nbr)
		return (1);
	while (nbr && ++i)
		nbr /= base_nbr;
	return (i);
}
