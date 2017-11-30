/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_am_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 21:53:48 by sjimenez          #+#    #+#             */
/*   Updated: 2017/11/30 05:58:50 by sjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		i_am_d(char *s, t_ptf *ptf, va_list ap)
{
	int		n;
	char	*temp;

	n = va_arg(ap, int);
	temp = ft_itoa(n);
	ft_strcat(ptf->sr, temp);
	free(temp);
	(void)s;
}
