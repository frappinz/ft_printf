/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fminardi <fminardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:13:20 by fminardi          #+#    #+#             */
/*   Updated: 2021/03/11 16:13:21 by fminardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write_width_minus(t_list *flags)
{
	int i;

	i = 0;
	while (flags->towrite[i])
	{
		write(1, &flags->towrite[i++], 1);
		flags->count++;
	}
	while (i++ < flags->width)
	{
		write(1, " ", 1);
		flags->count++;
	}
	free(flags->towrite);
}

void	ft_write_width(t_list *flags)
{
	int		i;
	int		l;

	i = 0;
	l = ft_strlen(flags->towrite);
	if (flags->minus == 1)
		ft_write_width_minus(flags);
	else
	{
		while (i++ < flags->width - l)
		{
			write(1, " ", 1);
			flags->count++;
		}
		i = 0;
		while (flags->towrite[i])
		{
			write(1, &flags->towrite[i++], 1);
			flags->count++;
		}
		free(flags->towrite);
	}
}

void	ft_write_width_char(t_list *flags)
{
	int		i;

	i = 0;
	if (flags->minus == 1)
	{
		write(1, &flags->charizard, 1);
		flags->count++;
		while (i < (flags->width - 1))
		{
			write(1, " ", 1);
			i++;
			flags->count++;
		}
	}
	else
	{
		while (i < flags->width - 1)
		{
			write(1, " ", 1);
			i++;
			flags->count++;
		}
		write(1, &flags->charizard, 1);
		flags->count++;
	}
}
