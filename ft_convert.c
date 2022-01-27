/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fminardi <fminardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:28:16 by fminardi          #+#    #+#             */
/*   Updated: 2021/03/11 15:28:19 by fminardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_s(t_list *flags, va_list args)
{
	char	*str;
	int		i;

	i = 0;
	str = va_arg(args, char *);
	if (flags->prec == 0)
		flags->towrite = "";
	if (str == NULL)
		str = "(null)";
	flags->type = 's';
	while (str[i])
		i++;
	flags->towrite = malloc((i) * sizeof(char));
	i = 0;
	while (str[i])
	{
		flags->towrite[i] = str[i];
		i++;
	}
	flags->towrite[i] = '\0';
	return ;
}

void	ft_convert_c(t_list *flags, va_list args)
{
	int		i;

	i = 0;
	flags->charizard = (char)va_arg(args, int);
	flags->type = 'c';
}

char	*ft_convert_x_p(size_t c)
{
	int		i;
	int		j;
	char	*set;
	char	*tmp;
	char	*wow;

	i = 0;
	set = "0123456789abcdef";
	tmp = malloc(17 * sizeof(char));
	while (c > 0)
	{
		tmp[i++] = set[c % 16];
		c = c / 16;
	}
	tmp[i] = '\0';
	wow = malloc((i + 3) * sizeof(char));
	wow[0] = '0';
	wow[1] = 'x';
	j = 2;
	while (i >= 1)
		wow[j++] = tmp[(i--) - 1];
	wow[j] = '\0';
	free(tmp);
	return (wow);
}

void	ft_convert_p(t_list *flags, va_list args)
{
	size_t	c;

	flags->type = 'p';
	c = va_arg(args, size_t);
	if (c == (unsigned int)NULL)
	{
		flags->towrite = malloc(4 * sizeof(char));
		flags->towrite[0] = '0';
		flags->towrite[1] = 'x';
		flags->towrite[2] = '0';
		flags->towrite[3] = '\0';
		return ;
	}
	flags->towrite = ft_convert_x_p(c);
}

void	ft_convert_u(t_list *flags, va_list args)
{
	unsigned int x;

	flags->type = 'u';
	x = va_arg(args, unsigned int);
	if (flags->prec == 0 && x == 0)
	{
		flags->towrite = malloc(1 * sizeof(char));
		flags->towrite[0] = '\0';
		return ;
	}
	else if (x < 0)
		x += 4294967296;
	ft_itoa_u(x, flags, ft_count(x, flags));
}
