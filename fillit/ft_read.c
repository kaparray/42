/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpowlows <hpowlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 16:21:17 by hpowlows          #+#    #+#             */
/*   Updated: 2018/12/23 20:15:23 by hpowlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_reader(char *arr, int x)
{
	int		fd;
	char	buf;
	char	*dest;

	fd = open(arr, 0x0000);
	while (read(fd, &buf, 1))
		x++;
	if (x < 20)
	{
		write(1, "error\n", 6);
		exit(0);
	}
	dest = ft_strnew(x);
	close(fd);
	x = 0;
	fd = open(arr, 0x0000);
	while (read(fd, &buf, 1))
		dest[x++] = buf;
	close(fd);
	return (dest);
}
