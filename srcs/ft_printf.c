/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 21:24:45 by sjimenez          #+#    #+#             */
/*   Updated: 2017/11/30 06:44:28 by sjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	is_spec(char c, t_flags *flags)
{
	char	*spec_tab;

	spec_tab = "sSpdDioOuUxXcX%";
	while (spec_tab[0] && c != spec_tab[0])
	{
		spec_tab++;
	}
	if (ft_strlen(spec_tab) == 0)
		flags->found_txt[ft_strlen(flags->found_txt)] = c;
	else
		flags->spec = c;
	return (spec_tab[0]);
}

void	handle_percent(char *s, t_ptf *ptf, va_list ap)
{
	char	spec;
	t_flags	*flags;

	flags = (t_flags*)ft_memalloc(sizeof(t_flags));
	flags->found_txt = ft_memalloc(sizeof(char) * 20);
	flags->flags = ft_memalloc(sizeof(char) * 6);
	flags->len_modif = ft_memalloc(sizeof(char) * 4);
	ft_bzero(flags->found_txt, 20);
	ft_bzero(flags->flags, 6);
	ft_bzero(flags->flags, 4);
	spec = '\0';
	while (s[ptf->i + 1] && !spec)
		spec = is_spec(s[ptf->i++ + 1], flags);
	if (spec == '\0')
		ft_putendl("Bad format for %: No conv specifier");
	else
		get_damn_flags(s, ptf, ap, flags);
	free(flags->found_txt);
	free(flags->flags);
	free(flags);
}

void	check_char(char *s, t_ptf *ptf, va_list ap)
{
	if (s[ptf->i] == '%')
		handle_percent(s, ptf, ap);
	else
	{
		ptf->sr[ft_strlen(ptf->sr)] = s[ptf->i];
		ptf->sr[ft_strlen(ptf->sr) + 1] = '\0';
	}
}

int		ft_printf(char *s, ...)
{
	va_list		ap;
	t_ptf		ptf;

	va_start(ap, s);
	ptf.i = -1;
	ptf.sr = (char*)ft_memalloc(sizeof(char) * 2000000);
	while (s[++ptf.i])
		check_char(s, &ptf, ap);
	//ft_putendl("\n\033[0;32m--------\tft_printf   --------\033[0;36m\n");
	ft_putstr(ptf.sr);
	free(ptf.sr);
	va_end(ap);
	return (ft_strlen(ptf.sr));
}

int		main(void)
{
	int		nbr;

	nbr = 654321;
	//setlocale(LC_ALL, "");  AFFICHER UNICODE!!!
	ft_printf("Sam... %p %d - %#-10.5hhs - %i %3.5s ...maS\n", &nbr, nbr, "lol", 123456, "yes");
	printf("\033[0;33m-----------------------------------\033[0;36m\n");
	printf("Sam... %p %d - %s - %i %s ...maS\n", &nbr, nbr, "lol", 123456, "yes");
	printf("\n\033[0;32m--------\tReal printf --------\033[0;33m\n");

	return (0);
}
