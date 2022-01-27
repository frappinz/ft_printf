/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fminardi <fminardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:58:36 by fminardi          #+#    #+#             */
/*   Updated: 2021/03/11 15:58:39 by fminardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_strlen(char *s)
{
	int		c;

	c = 0;
	while (s[c])
		c++;
	return (c);
}

void		ft_struct_analyze(t_list *flags)
{
	if (flags->type == 'd' || flags->type == 'i' || flags->type == 'x'
	|| flags->type == 'X' || flags->type == 'u')
		ft_write_integer(flags);
	else if (flags->type == 'c')
		ft_write_width_char(flags);
	else if (flags->type == 's')
		ft_write_string(flags);
	else if (flags->type == 'p')
		ft_write_width(flags);
}

size_t		ft_count(int n, t_list *flags)
{
	size_t	count;

	count = 1;
	if (flags->type == 'd' || flags->type == 'i' || flags->type == 'u')
	{
		while (n <= -10 || n >= 10)
		{
			n = n / 10;
			count++;
		}
		if (n < 0)
			return (count + 1);
	}
	else
	{
		while (n <= -16 || n >= 16)
		{
			n = n / 16;
			count++;
		}
	}
	return (count);
}
