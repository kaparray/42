/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpowlows <hpowlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 16:21:17 by hpowlows          #+#    #+#             */
/*   Updated: 2018/12/18 16:34:31 by hpowlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	reader(int fd, char *arr)
{
	ssize_t		rdbl;
	char		buff[BUFF_SIZE + 1];
	char		*tmp;


	while ((rdbl = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[rdbl] = 0;
		tmp = arr;
		arr = ft_strjoin(arr, buff);
		ft_strdel(&tmp);
	}
}
