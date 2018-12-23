/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpowlows <hpowlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 16:21:17 by hpowlows          #+#    #+#             */
/*   Updated: 2018/12/23 17:04:32 by hpowlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_reader(int a, char *arr)
{
	int fd;
	char buf;
	char *dst;

	fd = open(arr, 0x0000);
	while (read(fd, &buf, 1))
		a++;
	if (a < 20)
	{
		ft_putstr("error\n");
		exit(0);
	}
	dst = ft_strnew(a);
	close(fd);
	a = 0;
	fd = open(arr, 0x0000);
	while (read(fd, &buf, 1))
		dst[a++] = buf;
	close(fd);
	return (dst);
}
