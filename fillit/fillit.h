/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpowlows <hpowlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 16:12:17 by hpowlows          #+#    #+#             */
/*   Updated: 2018/12/15 21:55:40 by hpowlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

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

# define T1 "#.."
# define T2
# define T3
# define T4
# define T5
# define T6
# define T7
# define T8
# define T9
# define T10
# define T11
# define T12
# define T13
# define T14
# define T15
# define T16
# define T17
# define T18
# define T19


typedef struct	 s_ttr
{
	int		**arr;
}				t_ttr;

t_ttr g_ttr;


#endif
