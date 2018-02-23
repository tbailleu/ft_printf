/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailleu <tbailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 13:39:40 by tbailleu          #+#    #+#             */
/*   Updated: 2017/11/28 15:41:54 by tbailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*ft_strrev(char *str)
{
	int		len;
	int		i;
	char	tmp;

	i = 0;
	len = 0;
	while (str[len] != '\0')
		len++;
	while (i < len / 2)
	{
		tmp = str[len - (i + 1)];
		str[len - (i + 1)] = str[i];
		str[i] = tmp;
		i++;
	}
	return (str);
}
