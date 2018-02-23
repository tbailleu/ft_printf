/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbline_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailleu <tbailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 09:28:09 by tbailleu          #+#    #+#             */
/*   Updated: 2018/01/04 13:48:29 by tbailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		ft_nbline_file(char *file)
{
	int		fd;
	int		nb_lines;
	char	buf;

	fd = 0;
	nb_lines = 0;
	ft_throw_error((fd = open(file, O_RDONLY)) < 0,
		"open(): No such file or directory");
	while (read(fd, &buf, 1))
		if (buf == '\n')
			nb_lines++;
	close(fd);
	return (nb_lines);
}
