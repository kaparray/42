/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 02:41:34 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/12/21 17:18:16 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


/* return side of optimal square */

static unsigned int			square_side(ssize_t len)
{
	ssize_t		side;

	side = 2;
	while (len * 4 > side * side)
		side++;
	return (side);
}

/* выделяет память под строку длинной len_tet + 2. 
приравнивает созданную строку к **cosa = *head в исходной функции
в начале ставит значение -1, в конце -2
промежуточные значения запоняет порядковым номером эллемента начиная с 0
*/
/* Как я понял, здесь выделяется память размером 4 под количество кубиков в тетраминке */

static int					*mem_ttr(unsigned int len_tet, int **cosa)
{
	size_t	i;
	int		*aux_tetrim;

	i = 0;
	if (!(aux_tetrim = ft_memalloc(sizeof(int) * (len_tet + 2))))
		return (NULL);
	*cosa = aux_tetrim;
	aux_tetrim[0] = -1;
	aux_tetrim++;
	aux_tetrim[len_tet] = -2;
	while (i < len_tet)
	{
		aux_tetrim[i] = i;
		i++;
	}
	return (aux_tetrim);
}

/*  */

static unsigned char		*mem_sqr(ssize_t side)
{
	unsigned char	*sqr;

	if (!(sqr = (unsigned char *)ft_memalloc(sizeof(char) *
					((side + 1) * side + 1)))) 
		return (NULL);
	sqr = (unsigned char *)fill_sqr(sqr, (side + 1) * side, side);
	return (sqr);
}



/* Entry point for solution part */
unsigned char				*ft_filler(int *ttr, ssize_t len)
{
	unsigned int	side;
	unsigned char	*sqr;
	int				*aux_tetrim;
	int				*head;

	head = NULL;
	side = square_side(len); 
	while (1)
	{
		aux_tetrim = head;
		if (aux_tetrim)
			free(aux_tetrim);
		aux_tetrim = mem_ttr(len, &head);  // выделяется память под тетраминку
		if (!(sqr = mem_sqr(side))) //
			return (NULL);
		while (*aux_tetrim >= 0)
			ft_dealer(sqr, side, ttr, &aux_tetrim);
		if (*aux_tetrim == -2)
			return (sqr);
		free(sqr);
		side++;
	}
	return (NULL);
}
