/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailleu <tbailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 14:43:39 by tbailleu          #+#    #+#             */
/*   Updated: 2018/01/04 13:50:08 by tbailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		get_first_line(char **savedlinesfd, char **line)
{
	char	*nl_pos;

	if ((nl_pos = ft_strchr(*savedlinesfd, (int)'\n')))
	{
		*line = ft_strsub(*savedlinesfd, 0, nl_pos - *savedlinesfd);
		ft_memmove(*savedlinesfd, nl_pos + 1, ft_strlen(nl_pos));
		nl_pos = NULL;
		return (1);
	}
	return (0);
}

int		read_fd_save_lines(const int fd, char **savedlinesfd, char **line)
{
	char	*buff;
	int		ret;

	if (!(buff = ft_strnew(BUFF_SIZE)))
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (savedlinesfd && *savedlinesfd && *savedlinesfd)
			*savedlinesfd = ft_strjoinfree(*savedlinesfd, buff);
		else
			*savedlinesfd = ft_strdup(buff);
		if (get_first_line(savedlinesfd, line))
		{
			free(buff);
			return (1);
		}
	}
	free(buff);
	return (ret);
}

int		get_next_line(const int fd, char **line)
{
	int			ret;
	static char	*savedlines[FD_MAX];

	if (fd < 0 || read(fd, 0, 0) == -1 || !line || BUFF_SIZE < 1 || fd > FD_MAX)
		return (-1);
	if (savedlines[fd] && get_first_line(&savedlines[fd], line))
		return (1);
	if ((ret = read_fd_save_lines(fd, &savedlines[fd], line)) != 0)
		return (ret);
	if (savedlines[fd] == NULL || savedlines[fd][0] == '\0')
		return (0);
	*line = savedlines[fd];
	savedlines[fd] = NULL;
	return (1);
}
