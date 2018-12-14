/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpowlows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:26:47 by hpowlows          #+#    #+#             */
/*   Updated: 2018/11/20 17:15:05 by hpowlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_inc.h"
#define BUF_SIZE 4096

int		main(int argc, char **argv)
{
	char	buf[BUF_SIZE + 1];
	int		file;
	int		readd;

	if (argc == 1)
		ft_putstr("File name missing.\n");
	else if (argc > 2)
		ft_putstr("Too many arguments.\n");
	else if (argc == 2)
	{
		file = open(argv[1], O_RDONLY);
		if (file == -1)
			return (1);
		while ((readd = read(file, buf, BUF_SIZE)))
		{
			buf[readd] = '\0';
			write(1, buf, readd);
		}
		if (close(file) == -1)
			return (1);
	}
	return (0);
}
