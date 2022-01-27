/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fminardi <fminardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:27:20 by fminardi          #+#    #+#             */
/*   Updated: 2021/03/15 10:34:36 by fminardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_type_perc(t_list *flags)
{
	flags->towrite = malloc(2 * sizeof(char));
	flags->towrite[0] = '%';
	flags->towrite[1] = '\0';
	flags->type = '%';
	ft_write_integer(flags);
}

void	ft_check_type(char format, t_list *flags, va_list args)
{
	if ((format == 'd') || (format == 'i'))
		ft_convert_d_i(flags, args);
	else if (format == 'X')
		ft_convert_xx(flags, args);
	else if (format == 'x')
		ft_convert_x(flags, args);
	else if (format == 'u')
		ft_convert_u(flags, args);
	else if (format == 'c')
	{
		flags->zero = -1;
		flags->prec = -1;
		ft_convert_c(flags, args);
	}
	else if (format == 's')
	{
		flags->zero = -1;
		flags->type = 's';
		ft_convert_s(flags, args);
	}
	else if (format == 'p')
		ft_convert_p(flags, args);
	else if (format == '%')
		ft_check_type_perc(flags);
}

void	ft_check_precision(const char *format, t_list *flags, va_list args)
{
	if (format[flags->j] == '.')
	{
		flags->prec = 0;
		flags->dot = 1;
		flags->j++;
		if (ft_is_digit(format[flags->j]) == 1)
		{
			while (ft_is_digit(format[flags->j]) == 1)
			{
				flags->prec = (flags->prec * 10) + (format[flags->j] - '0');
				flags->j++;
			}
			flags->zero = -1;
		}
		else if (format[flags->j] == '*')
		{
			flags->prec = va_arg(args, int);
			flags->prec = flags->prec <= -1 ? -1 : flags->prec;
			flags->zero = flags->prec > -1 ? -1 : flags->zero;
			flags->j++;
		}
		else
			flags->prec = 0;
	}
}

void	ft_check_width(const char *format, t_list *flags, va_list args)
{
	if ((ft_is_digit(format[flags->j])) == 1)
	{
		while (ft_is_digit(format[flags->j]) == 1)
		{
			flags->width = (flags->width * 10) + (format[flags->j] - '0');
			flags->j++;
		}
	}
	else if (format[flags->j] == '*')
	{
		flags->width = va_arg(args, int);
		if (flags->width < 0)
		{
			flags->minus = 1;
			flags->zero = -1;
			flags->width *= (-1);
		}
		flags->j++;
	}
}

void	ft_check_flags(const char *format, t_list *flags)
{
	if (format[flags->j] == '-')
	{
		flags->minus = 1;
		flags->zero = -1;
		flags->j++;
		if (format[flags->j] == '0')
			flags->j++;
	}
	else if (format[flags->j] == '0')
	{
		if (format[flags->j + 1] == '-')
		{
			flags->minus = 1;
			flags->j += 2;
		}
		else
		{
			flags->zero = 1;
			flags->minus = -1;
			flags->j++;
		}
	}
}
