/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpowlows <hpowlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:51:10 by hpowlows          #+#    #+#             */
/*   Updated: 2018/12/17 21:20:52 by hpowlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_next_line(const int fd, char **line)
{
	ssize_t		rdbl;
	char		buff[BUFF_SIZE + 1];
	static char	*str[FD_LIMIT];
	int			eol;
	char		*tmp;

	if (fd < 0 || (!str[fd] && !(str[fd] = ft_strnew(1))) || !line)
		return (-1);
	while (!ft_strchr(str[fd], '\n') && (rdbl = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[rdbl] = 0;
		tmp = str[fd];
		str[fd] = ft_strjoin(str[fd], buff);
		ft_strdel(&tmp);
	}
	if (rdbl == -1 || !*(tmp = str[fd]))
		return (rdbl == -1 ? -1 : 0);
	if ((eol = !!(ft_strchr(str[fd], '\n'))))
		*line = ft_strsub(str[fd], 0, ft_strchr(str[fd], '\n') - str[fd]);
	else
		*line = ft_strdup(str[fd]);
	str[fd] = ft_strsub(str[fd], (unsigned int)(ft_strlen(*line) + eol),
			(size_t)(ft_strlen(str[fd]) - (ft_strlen(*line) + eol)));
	ft_strdel(&tmp);
	return (!(!str[fd] && !ft_strlen(*line)));
}
