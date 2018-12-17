/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpowlows <hpowlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 20:12:39 by hpowlows          #+#    #+#             */
/*   Updated: 2018/12/10 18:49:13 by hpowlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst_tempo;
	const unsigned char	*src_tempo;

	if (dst < src)
		ft_memcpy(dst, src, len);
	else if (dst > src)
	{
		dst_tempo = (unsigned char *)dst;
		src_tempo = (const unsigned char *)src;
		while (len--)
			dst_tempo[len] = src_tempo[len];
	}
	return (dst);
}
