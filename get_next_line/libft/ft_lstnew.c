/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpowlows <hpowlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 20:12:39 by hpowlows          #+#    #+#             */
/*   Updated: 2018/12/10 18:48:41 by hpowlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *tempo;

	if (!(tempo = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		tempo->content = NULL;
		tempo->content_size = 0;
	}
	else
	{
		if (!(tempo->content = malloc(content_size)))
		{
			free(tempo);
			return (NULL);
		}
		ft_memcpy(tempo->content, content, content_size);
		tempo->content_size = content_size;
	}
	tempo->next = NULL;
	return (tempo);
}
