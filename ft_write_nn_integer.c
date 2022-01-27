/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_nn_integer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fminardi <fminardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:06:42 by fminardi          #+#    #+#             */
/*   Updated: 2021/03/11 16:06:43 by fminardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_nn_precision_width(t_list *flags)
{
	int i;
	int x;

	i = 0;
	x = ft_strlen(flags->towrite);
	write(1, "-", 1);
	flags->count++;
	while (i <= flags->prec - x)
	{
		write(1, "0", 1);
		i++;
		flags->count++;
	}
	i = 1;
	while (flags->towrite[i])
	{
		write(1, &flags->towrite[i], 1);
		i++;
		flags->count++;
	}
	free(flags->towrite);
}

void	ft_nn_width_precision(t_list *flags)
{
	int i;
	int x;

	i = 0;
	x = ft_strlen(flags->towrite);
	while (i++ < flags->width - flags->prec - 1)
	{
		write(1, " ", 1);
		flags->count++;
	}
	write(1, "-", 1);
	flags->count++;
	while (i++ <= flags->width - x)
	{
		write(1, "0", 1);
		flags->count++;
	}
	i = 1;
	while (flags->towrite[i] != 0)
	{
		write(1, &flags->towrite[i++], 1);
		flags->count++;
	}
	free(flags->towrite);
}

void	ft_nn_minus_width_precision(t_list *flags)
{
	int i;
	int x;

	i = 0;
	x = ft_strlen(flags->towrite);
	write(1, "-", 1);
	flags->count++;
	while (i++ <= flags->prec - x)
	{
		write(1, "0", 1);
		flags->count++;
	}
	i = 1;
	while (flags->towrite[i])
	{
		write(1, &flags->towrite[i], 1);
		i++;
		flags->count++;
	}
	while (i++ < flags->width - flags->prec - 1 + x)
	{
		write(1, " ", 1);
		flags->count++;
	}
	free(flags->towrite);
}

void	ft_nn_zero_width(t_list *flags)
{
	int i;
	int x;

	i = 0;
	x = ft_strlen(flags->towrite);
	write(1, "-", 1);
	flags->count++;
	while (i < flags->width - x)
	{
		write(1, "0", 1);
		i++;
		flags->count++;
	}
	i = 1;
	while (flags->towrite[i])
	{
		write(1, &flags->towrite[i], 1);
		i++;
		flags->count++;
	}
	free(flags->towrite);
}
