/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpowlows <hpowlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 18:23:48 by mmraz             #+#    #+#             */
/*   Updated: 2019/01/06 18:09:14 by hpowlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef	struct	s_point{

	int i;
	int j;
}				t_point;

typedef struct	s_piece{

	unsigned char	letter;
	t_point			conf[4];
	short			used;
	int				i_max;
	int				i_min;
	int				j_max;
	int				j_min;
	int				i_start;
	int				j_start;
}				t_piece;

typedef struct	s_map{

	int				**tab;
	int				size;
	int				count;
}				t_map;

int				check_file(int fd, t_piece **pieces, int *cnt, int ok);
t_piece			*to_piece(char **tab, unsigned int index, int *ok);
void			generate(t_piece **pieces, unsigned int cnt);
int				find_position(t_map *map, t_piece *piece);
void			clean(t_map *map, t_piece *piece);
void			reset_start_position(t_piece *piece);
void			ft_putchar(char c);
void			ft_putstr(const char *s);
char			**ft_strsplit(char const *s, char c);
void			ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
int				check_newline(char *file, int count);

#endif
