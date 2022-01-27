/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fminardi <fminardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:57:15 by fminardi          #+#    #+#             */
/*   Updated: 2021/03/11 16:38:36 by fminardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_itoa_writing_u(unsigned long n, t_list *flags, size_t count)
{
	char	*tmp;
	int		j;
	int		i;

	i = 0;
	j = 0;
	tmp = malloc((count + 1) * sizeof(char));
	flags->towrite = malloc((count + 1) * sizeof(char));
	if (n < 0)
	{
		n *= -1;
		flags->towrite[0] = '-';
		j = 1;
	}
	while (n > 0)
	{
		tmp[i++] = (n % 10) + 48;
		n = n / 10;
	}
	while (i - 1 >= 0)
		flags->towrite[j++] = tmp[(i--) - 1];
	flags->towrite[j] = '\0';
	free(tmp);
}

void	ft_itoa_writing_d(long int n, t_list *flags, size_t count)
{
	char	*tmp;
	int		j;
	int		i;

	i = 0;
	j = 0;
	tmp = malloc((count + 1) * sizeof(char));
	flags->towrite = malloc((count + 1) * sizeof(char));
	if (n < 0)
	{
		n *= -1;
		flags->towrite[0] = '-';
		j = 1;
	}
	while (n > 0)
	{
		tmp[i++] = (n % 10) + 48;
		n = n / 10;
	}
	while (i - 1 >= 0)
		flags->towrite[j++] = tmp[(i--) - 1];
	flags->towrite[j] = '\0';
	free(tmp);
}

void	ft_writing_zero(t_list *flags)
{
	flags->towrite = malloc(2 * sizeof(char));
	flags->towrite[0] = '0';
	flags->towrite[1] = '\0';
}

void	ft_itoa_d(long int n, t_list *flags, size_t count)
{
	int		j;
	int		i;

	i = 0;
	j = 0;
	if (n == 0)
	{
		flags->towrite = malloc(2 * sizeof(char));
		flags->towrite[0] = '0';
		flags->towrite[1] = '\0';
	}
	else
		ft_itoa_writing_d(n, flags, count);
}

void	ft_itoa_u(unsigned long n, t_list *flags, size_t count)
{
	int		j;
	int		i;

	i = 0;
	j = 0;
	if (n == 0)
	{
		flags->towrite = malloc(2 * sizeof(char));
		flags->towrite[0] = '0';
		flags->towrite[1] = '\0';
	}
	else
		ft_itoa_writing_u(n, flags, count);
}
