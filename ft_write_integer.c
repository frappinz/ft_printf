/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fminardi <fminardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:06:16 by fminardi          #+#    #+#             */
/*   Updated: 2021/03/11 16:06:18 by fminardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_negative_number(t_list *flags)
{
	int x;

	x = ft_strlen(flags->towrite);
	if ((x > flags->width) && (x > flags->prec))
		ft_towrite(flags);
	else if (flags->zero == 1 && flags->width > 0 && flags->prec == -1)
		ft_nn_zero_width(flags);
	else if (flags->width > 0 && (x > flags->prec))
		ft_write_width(flags);
	else if (flags->width > flags->prec)
	{
		if (flags->minus == 1)
			ft_nn_minus_width_precision(flags);
		else
			ft_nn_width_precision(flags);
	}
	else if (flags->prec >= flags->width)
		ft_nn_precision_width(flags);
}

void	ft_positive_number(t_list *flags)
{
	int x;

	x = ft_strlen(flags->towrite);
	if ((x > flags->width) && (x > flags->prec))
		ft_towrite(flags);
	else if (flags->zero == 1 && flags->width > 0)
		ft_zero_width(flags);
	else if (flags->width > 0 && (x > flags->prec))
		ft_write_width(flags);
	else if (flags->width > flags->prec)
	{
		if (flags->minus == 1)
			ft_minus_width_precision(flags);
		else
			ft_width_precision(flags);
	}
	else if (flags->prec >= flags->width)
		ft_precision_width(flags);
}

void	ft_write_integer(t_list *flags)
{
	int x;

	x = ft_strlen(flags->towrite);
	if (flags->towrite[0] == '-')
		ft_negative_number(flags);
	else
		ft_positive_number(flags);
}
