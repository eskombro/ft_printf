/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 20:06:07 by sjimenez          #+#    #+#             */
/*   Updated: 2017/11/12 06:57:23 by sjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ptr;
	char	*ptr2;
	size_t	i;

	i = 0;
	if (!(ptr = (char*)malloc(size)))
		return (NULL);
	ptr2 = (char*)ptr;
	while (i < size)
		ptr2[i++] = 0;
	return (ptr);
}
