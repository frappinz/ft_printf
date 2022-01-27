/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fminardi <fminardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:11:11 by fminardi          #+#    #+#             */
/*   Updated: 2021/03/11 16:11:12 by fminardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_string_no_minus(t_list *flags)
{
	int i;

	i = 0;
	while (i < flags->width - flags->prec)
	{
		write(1, " ", 1);
		i++;
		flags->count++;
	}
	i = 0;
	while (i < flags->prec && flags->towrite[i])
	{
		write(1, &flags->towrite[i], 1);
		i++;
		flags->count++;
	}
	free(flags->towrite);
}

void	ft_string_minus(t_list *flags)
{
	int i;

	i = 0;
	while (i < flags->prec && flags->towrite[i])
	{
		write(1, &flags->towrite[i], 1);
		i++;
		flags->count++;
	}
	while (i < flags->width)
	{
		write(1, " ", 1);
		i++;
		flags->count++;
	}
	free(flags->towrite);
}

void	ft_write_string(t_list *flags)
{
	int l;
	int i;

	i = 0;
	l = ft_strlen(flags->towrite);
	if (flags->prec <= l && flags->prec != -1)
	{
		if (flags->minus == 1)
			ft_string_minus(flags);
		else
			ft_string_no_minus(flags);
	}
	else if (flags->prec > l || flags->prec == -1)
		ft_write_width(flags);
}
