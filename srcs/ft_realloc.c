/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailleu <tbailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 10:13:49 by tbailleu          #+#    #+#             */
/*   Updated: 2017/11/27 10:15:41 by tbailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	*ft_realloc(void *data, int size)
{
	void *new;

	new = ft_memalloc(size);
	ft_memcpy(new, data, ft_strlen(data));
	ft_memdel(&data);
	return (new);
}
