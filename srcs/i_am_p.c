/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_am_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 04:49:13 by sjimenez          #+#    #+#             */
/*   Updated: 2017/11/30 05:59:34 by sjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		i_am_p(char *s, t_ptf *ptf, va_list ap)
{
	int		n;
	char	*temp;

	n = va_arg(ap, int);
	temp = ft_strtolower(ft_itoa_base(n, 16));
	ft_strcat(ptf->sr, temp);
	free(temp);
	(void)s;
}
