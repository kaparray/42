/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpowlows <hpowlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 16:21:17 by hpowlows          #+#    #+#             */
/*   Updated: 2018/12/19 16:27:27 by hpowlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*reader(int fd)
{
	char		*line;
	ssize_t		rdbl;
	char		buff[BUFF_SIZE + 1];
	char		*tmp;

	line = ft_strnew(1);
	while ((rdbl = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[rdbl] = 0;
		tmp = line;
		line = ft_strjoin(line, buff);
		ft_strdel(&tmp);
	}
	return (line);
}
