/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fminardi <fminardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:04:22 by fminardi          #+#    #+#             */
/*   Updated: 2021/03/11 16:04:36 by fminardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init(t_list *flags)
{
	flags->minus = -1;
	flags->zero = -1;
	flags->width = 0;
	flags->prec = -1;
	flags->dot = -1;
}

int		ft_is_digit(char format)
{
	if (format >= '0' && format <= '9')
		return (1);
	return (0);
}

int		ft_parsing(const char *format, t_list *flags, va_list args)
{
	ft_check_flags(format, flags);
	ft_check_width(format, flags, args);
	ft_check_precision(format, flags, args);
	ft_check_type(format[flags->j], flags, args);
	return (1);
}

void	ft_printf_process(const char *format, t_list *flags, va_list args)
{
	flags->j++;
	ft_init(flags);
	ft_parsing(format, flags, args);
	ft_struct_analyze(flags);
	flags->j++;
	ft_init(flags);
}

int		ft_printf(const char *format, ...)
{
	t_list			*flags;
	va_list			args;

	flags = (t_list *)malloc(sizeof(t_list) * 1);
	flags->j = 0;
	flags->count = 0;
	va_start(args, format);
	while (format[flags->j] != 0)
	{
		while (format[flags->j] == '%')
			ft_printf_process(format, flags, args);
		if (format[flags->j] == 0)
			break ;
		write(1, &format[flags->j], 1);
		flags->count++;
		flags->j++;
	}
	va_end(args);
	free(flags);
	return (flags->count);
}
