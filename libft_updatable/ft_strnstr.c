/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpowlows <hpowlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:51:10 by hpowlows          #+#    #+#             */
/*   Updated: 2018/12/10 18:55:04 by hpowlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *heystack, const char *needle, size_t len)
{
	size_t j;
	size_t index;

	if (ft_strlen(needle) == 0)
		return ((char *)heystack);
	index = 0;
	while (*heystack && index < len)
	{
		j = 0;
		if (*heystack == needle[j])
		{
			while (needle[j] && needle[j] == *(heystack + j)
				&& index + j < len)
				j++;
			if (needle[j] == '\0')
				return ((char *)heystack);
		}
		heystack++;
		index++;
	}
	return (NULL);
}
