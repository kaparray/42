/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpowlows <hpowlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 16:12:17 by hpowlows          #+#    #+#             */
/*   Updated: 2018/12/19 16:41:06 by hpowlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>


# define TR '#'

/**
 *
 * All types of Tetriminos
 *
*/

# define T1 1		// 3 + 1 up
# define T2 2		// 3 + 1 down
# define T3 3		// 3 + 1 left
# define T4 4		// 3 + 1 right
# define T5 5		// 4 little square in row
# define T6 6		// 4 little square in column
# define T7 7		// square []
# define T8 8		// s normal
# define T9 9		// z normal
# define T10 10		// s on hip
# define T11 11	// z on hip
# define T12 12	// j on long down
# define T13 13	// l on long down
# define T14 14	// j on sort down
# define T15 15	// l on short down
# define T16 16	// l on long up
# define T17 17	// j on long up
# define T18 18	// l on short up
# define T19 19 // j on short up



typedef struct	 s_lstttr
{
	int			*arr;
	ssize_t		len;
}				t_lstttr;


int				*g_ttr;
t_lstttr		g_lstttr;


char			*reader(int fd);
int				start_validation(char *ttr);
int				separator(char *ttr, int normal);
int				tetra_separator(char *ttr, int normal);
int				valid(char *ttr, int j);
int				checker(char *ttr, int j);
int				is_tetramino(int j);
int				type_of_tetramino(int i);
int				equ_tetramino_2(int t1, int t2, int t3, int i);
int				equ_tetramino_1(int t1, int t2, int t3, int i);


#endif
