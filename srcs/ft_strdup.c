/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailleu <tbailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:21:08 by tbailleu          #+#    #+#             */
/*   Updated: 2017/11/25 10:12:19 by tbailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*ft_strdup(const char *src)
{
	char	*dst;

	dst = ft_strnew(ft_strlen(src));
	if (!dst)
		return (NULL);
	return (ft_strcpy(dst, (char *)src));
}
