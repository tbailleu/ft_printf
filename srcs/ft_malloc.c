/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailleu <tbailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 10:17:38 by tbailleu          #+#    #+#             */
/*   Updated: 2017/11/27 10:45:09 by tbailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	*ft_malloc(size_t size)
{
	void *var;

	var = malloc(size);
	if (!var)
		return (NULL);
	return (var);
}
