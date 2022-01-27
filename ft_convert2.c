/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fminardi <fminardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:34:39 by fminardi          #+#    #+#             */
/*   Updated: 2021/03/11 16:37:50 by fminardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_d_i(t_list *flags, va_list args)
{
	int				x;
	size_t			count;

	x = va_arg(args, int);
	flags->type = 'd';
	if (flags->prec == 0 && x == 0)
	{
		flags->towrite = malloc(1 * sizeof(char));
		flags->towrite[0] = '\0';
	}
	else
	{
		flags->type = 'd';
		count = ft_count(x, flags);
		ft_itoa_d(x, flags, count);
	}
}

void	wonderful_conversion(t_list *flags, unsigned int x, char *set)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = malloc((ft_count(x, flags)) * sizeof(char));
	while (x > 0)
	{
		tmp[i++] = set[x % 16];
		x = x / 16;
	}
	flags->towrite = malloc((i + 1) * sizeof(char));
	while (--i >= 0)
		flags->towrite[j++] = tmp[i];
	flags->towrite[j] = '\0';
	free(tmp);
}

void	ft_convert_x(t_list *flags, va_list args)
{
	unsigned int	x;
	char			*set;

	set = "0123456789abcdef";
	flags->type = 'x';
	x = va_arg(args, unsigned int);
	if (x == 0 && flags->prec != 0)
	{
		flags->towrite = malloc(2 * sizeof(char));
		flags->towrite[0] = '0';
		flags->towrite[1] = '\0';
		return ;
	}
	else if (flags->prec == 0 && x == 0)
	{
		flags->towrite = malloc(1 * sizeof(char));
		flags->towrite[0] = '\0';
		return ;
	}
	if (x < 0)
		x += 4294967296;
	if (x > 0)
		wonderful_conversion(flags, x, set);
}

void	ft_convert_xx(t_list *flags, va_list args)
{
	unsigned int	x;
	char			*set;

	flags->type = 'X';
	set = "0123456789ABCDEF";
	x = va_arg(args, unsigned int);
	if (x == 0 && flags->prec != 0)
	{
		flags->towrite = malloc(2 * sizeof(char));
		flags->towrite[0] = '0';
		flags->towrite[1] = '\0';
	}
	else if (flags->prec == 0 && x == 0)
	{
		flags->towrite = malloc(1 * sizeof(char));
		flags->towrite[0] = '\0';
	}
	if (x < 0)
		x += 4294967296;
	if (x > 0)
		wonderful_conversion(flags, x, set);
}
