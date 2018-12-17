/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpowlows <hpowlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 20:12:39 by hpowlows          #+#    #+#             */
/*   Updated: 2018/12/10 18:52:06 by hpowlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*result;
	int		index;

	if (!s || !f)
		return (NULL);
	if (!(result = (char *)malloc(sizeof(*s) * ft_strlen(s) + 1)))
		return (NULL);
	index = 0;
	while (s[index])
	{
		result[index] = f(s[index]);
		index++;
	}
	result[index] = '\0';
	return (result);
}
