/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpowlows <hpowlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 20:12:39 by hpowlows          #+#    #+#             */
/*   Updated: 2018/12/10 18:51:04 by hpowlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char const *tail;

	if (s == NULL)
		return (NULL);
	while (WHITESPACED(*s))
		s++;
	if (*s == '\0')
		return (ft_strnew(0));
	tail = s + ft_strlen(s) - 1;
	while (WHITESPACED(*tail))
		tail--;
	return (ft_strsub(s, 0, tail - s + 1));
}
