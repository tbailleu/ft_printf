/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailleu <tbailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 23:37:51 by tbailleu          #+#    #+#             */
/*   Updated: 2017/11/27 23:39:48 by tbailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*ft_strcat_swap(char *s1, const char *s2)
{
	char	tmp[ft_strlen(s1) + 1];

	ft_strcpy(tmp, s1);
	ft_strcpy(s1, s2);
	ft_strcat(s1, tmp);
	return (s1);
}
