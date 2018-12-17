/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaparray <kaparray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 21:15:37 by hpowlows          #+#    #+#             */
/*   Updated: 2018/12/17 14:02:41 by kaparray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(void) {

   	int     fd;
    char 	*arr;
   	char	*line;

	arr = ft_strnew(1);

    fd = open("val", O_RDONLY);

	while (get_next_line(fd, &line) > 0)
	{
		arr = ft_strjoin(arr, line);
		free(line);
	}

	if (validation(arr) != 0x0)
		printf("true");
	else
		printf("false");

	return (0);
}

