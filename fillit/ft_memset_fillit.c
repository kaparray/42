/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_fillit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 21:40:06 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/12/21 17:16:34 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	*fill_sqr(void *dest, size_t n, size_t size)
{
	size_t			i;
	unsigned char	*aux;

	aux = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		if (!((i + 1) % (size + 1)))
			aux[i++] = '\n';
		else
			aux[i++] = '.';
	}
	return (dest);
}
