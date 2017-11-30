/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_damn_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 22:09:50 by sjimenez          #+#    #+#             */
/*   Updated: 2017/11/30 05:37:44 by sjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 ** get_damn_flags fills the "t_flags" structure by reading the main buffer
 ** (*s) and the calls the function needed to handle each case (%s, %d, ...).
*/

/*
 ** fill_flag_struct gets basic flags, asks width_precision to find this
 ** 2 parameters (width, preision) and returns i iterator.
*/

static int		width_precision(t_flags *flags, int i)
{
	char	temp[100];

	ft_bzero(temp, 100);
	while (ft_isdigit(flags->found_txt[i]))
	{
		temp[ft_strlen(temp)] = flags->found_txt[i++];
		temp[ft_strlen(temp) + 1] = '\0';
	}
	if (flags->found_txt[i] == '.')
	{
		flags->min_width = atoi(temp);
		ft_bzero(temp, 100);
		while (ft_isdigit(flags->found_txt[++i]))
		{
			temp[ft_strlen(temp)] = flags->found_txt[i];
			temp[ft_strlen(temp) + 1] = '\0';
		}
		if (temp[0] != 0)
			flags->precision = ft_atoi(temp);
	}
	return (i);
}

void			print_flags(t_flags *flags)
{
	if (flags->found_txt[0] != 0)
	{
		ft_putchar('\n');
		ft_putendl(flags->found_txt);
		ft_putstr("flags: ");
		ft_putstr(flags->flags);
		ft_putstr("\nmin_width: ");
		ft_putnbr(flags->min_width);
		ft_putstr("\nprecision: ");
		ft_putnbr(flags->precision);
		ft_putstr("\nlen_modif: ");
		ft_putstr(flags->len_modif);
		ft_putstr("\n\n");
	}
}

static void		fill_flag_struct(t_flags *flags)
{
	int		i;

	i = 0;
	while (flags->found_txt[i] == '#' || flags->found_txt[i] == '0'
		|| flags->found_txt[i] == '-' || flags->found_txt[i] == '+'
		|| flags->found_txt[i] == ' ')
		flags->flags[ft_strlen(flags->flags)] = flags->found_txt[i++];
	i = width_precision(flags, i);
	if (flags->found_txt[i] == 'h' || flags->found_txt[i] == 'l')
	{
		flags->len_modif[ft_strlen(flags->len_modif)] = flags->found_txt[i];
		i++;
		if (flags->found_txt[i] == 'h' || flags->found_txt[i] == 'l')
		{
			flags->len_modif[ft_strlen(flags->len_modif)] = flags->found_txt[i];
			i++;
		}
	}
	else if (flags->found_txt[i] == 'j' || flags->found_txt[i] == 'z')
		flags->len_modif[ft_strlen(flags->len_modif)] = flags->found_txt[i++];
	print_flags(flags);
}

void			get_damn_flags(char *s, t_ptf *ptf, va_list ap, t_flags *flags)
{
	fill_flag_struct(flags);
	if (flags->spec == 'd' || flags->spec == 'i')
		i_am_d(s, ptf, ap);
	if (flags->spec == 's')
		i_am_s(s, ptf, ap);
	if (flags->spec == 'p')
		i_am_p(s, ptf, ap);
}
