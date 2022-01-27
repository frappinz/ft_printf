/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_pn_integer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fminardi <fminardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:07:28 by fminardi          #+#    #+#             */
/*   Updated: 2021/03/11 16:07:29 by fminardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_precision_width(t_list *flags)
{
	int i;
	int x;

	i = 0;
	x = ft_strlen(flags->towrite);
	while (i < flags->prec - x)
	{
		write(1, "0", 1);
		i++;
		flags->count++;
	}
	i = 0;
	while (i < x)
	{
		write(1, &flags->towrite[i], 1);
		i++;
		flags->count++;
	}
	free(flags->towrite);
}

void	ft_width_precision(t_list *flags)
{
	int i;
	int x;

	i = 0;
	x = ft_strlen(flags->towrite);
	while (i < flags->width - flags->prec)
	{
		write(1, " ", 1);
		i++;
		flags->count++;
	}
	while (i < flags->width - x)
	{
		write(1, "0", 1);
		i++;
		flags->count++;
	}
	i = 0;
	while (flags->towrite[i])
	{
		write(1, &flags->towrite[i], 1);
		i++;
		flags->count++;
	}
	free(flags->towrite);
}

void	ft_minus_width_precision(t_list *flags)
{
	int i;
	int x;

	i = 0;
	x = ft_strlen(flags->towrite);
	while (i < flags->prec - x)
	{
		write(1, "0", 1);
		i++;
		flags->count++;
	}
	i = 0;
	while (flags->towrite[i])
	{
		write(1, &flags->towrite[i++], 1);
		flags->count++;
	}
	free(flags->towrite);
	i = 0;
	while (i < (flags->width - flags->prec))
	{
		write(1, " ", 1);
		i++;
		flags->count++;
	}
}

void	ft_zero_width(t_list *flags)
{
	int i;
	int x;

	i = 0;
	x = ft_strlen(flags->towrite);
	while (i < flags->width - x)
	{
		write(1, "0", 1);
		i++;
		flags->count++;
	}
	i = 0;
	while (flags->towrite[i])
	{
		write(1, &flags->towrite[i], 1);
		flags->count++;
		i++;
	}
	free(flags->towrite);
}

void	ft_towrite(t_list *flags)
{
	int i;

	i = 0;
	while (flags->towrite[i])
	{
		write(1, &flags->towrite[i], 1);
		i++;
		flags->count++;
	}
	free(flags->towrite);
}
