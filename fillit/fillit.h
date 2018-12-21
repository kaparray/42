/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 16:12:17 by hpowlows          #+#    #+#             */
/*   Updated: 2018/12/21 17:20:58 by mmraz            ###   ########.fr       */
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

# define T1 411		// 3 + 1 up
# define T2 114		// 3 + 1 down
# define T3 415		// 3 + 1 left
# define T4 514		// 3 + 1 right
# define T5 555		// 4 little square in row
# define T6 111		// 4 little square in column
# define T7 141		// square []
# define T8 131		// s normal
# define T9 151		// z normal
# define T10 515		// s on hip
# define T11 414	// z on hip
# define T12 511	// j on long down
# define T13 311	// l on long down
# define T14 541	// j on sort down
# define T15 551	// l on short down
# define T16 113	// l on long up
# define T17 115	// j on long up
# define T18 155	// l on short up
# define T19 145 // j on short up



typedef struct	 s_lstttr
{
	int			*arr;
	ssize_t		len;
}				t_lstttr;


int				*g_ttr;
t_lstttr		g_lstttr;


char			*reader(int fd);
int				loop_validation(int *cnt, int *nmrl, char *ttr, int i);
int				start_validation(char *ttr);
int				separator(char *ttr, int normal);
int				tetra_separator(char *ttr, int normal);
int				valid(char *ttr, int j);
int				checker(char *ttr, int j);
int				is_tetramino(int j);
int				type_of_tetramino(int i);
int				equ_tetramino_2(int t1, int t2, int t3, int i);
int				equ_tetramino_1(int t1, int t2, int t3, int i);


// Solution
void	ft_swap(int *a, int *b);
void	ft_sort_pos_int(int *arr);
unsigned char				*ft_filler(int *ttr, ssize_t len);
int		*ft_decoder(size_t side, int tet, int i);
//static void		cosa(int **aux_tetrim, int *aux, int **min);
//static int		update_aux_tetrim(int **aux_tetrim,
//		unsigned char *sqr, unsigned int side, int *tetrim);
void			ft_dealer(unsigned char *sqr,
		unsigned int side, int *tetrim, int **aux_tetrim);
void	*fill_sqr(void *dest, size_t n, size_t size);
int	ft_erase(unsigned char *sqr, unsigned int side,
		unsigned int pos, int *tetrim);
int			ft_fill(unsigned char *sqr, size_t side, int tet, unsigned int pos);
//static unsigned int			min_square(unsigned int *len_pos, int *tetrim);
//static int					*memaux_tetrim(unsigned int len_tet, int **cosa);
//static unsigned char		*memsqr(unsigned int side);


#endif
