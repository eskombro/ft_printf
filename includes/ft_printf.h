/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 21:26:20 by sjimenez          #+#    #+#             */
/*   Updated: 2017/11/30 05:44:21 by sjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <locale.h>
# include <stdarg.h>
# include "libft.h"

# include <stdio.h>

typedef struct	s_ptf
{
	char		*sr;
	int			i;
}				t_ptf;

typedef struct	s_flags
{
	char		*found_txt;
	char		*flags;
	int			min_width;
	int			precision;
	char		*len_modif;
	char		spec;
}				t_flags;

void			get_damn_flags(char *s, t_ptf *ptf, va_list ap, t_flags *flags);
void			i_am_d(char *s, t_ptf *ptf, va_list ap);
void			i_am_s(char *s, t_ptf *ptf, va_list ap);
void			i_am_p(char *s, t_ptf *ptf, va_list ap);

#endif
