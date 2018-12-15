/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpowlows <hpowlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 21:15:37 by hpowlows          #+#    #+#             */
/*   Updated: 2018/12/15 22:21:12 by hpowlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// int main(void)
// {
//	t_ttr t;
//	g_lstttr lstt;




// 	return (0);
// }



int main(void) {

   	int     fd;
    char 	*arr;
   	char	*line;

	arr = ft_strnew(1);

    fd = open("val", O_RDONLY);

	while (get_next_line(fd, &line) > 0)
	{
		arr = ft_strjoin(arr, line);
		//free(&line);
	}

	if (validation(arr) != 0x0)
		printf("true");
	else
		printf("false");

	return (0);
}
