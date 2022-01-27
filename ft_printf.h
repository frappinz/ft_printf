/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fminardi <fminardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:36:57 by fminardi          #+#    #+#             */
/*   Updated: 2021/03/31 12:09:30 by fminardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <strings.h>
# include <stdarg.h>
# include <stddef.h>

typedef struct	s_list
{
	int			minus;
	int			dot;
	int			zero;
	int			width;
	int			prec;
	int			count;
	char		type;
	int			i;
	int			j;
	char		charizard;
	char		*towrite;
}				t_list;

int				ft_printf(const char *format, ...);
void			ft_printf_process(const char *format, t_list *flags,
va_list args);
int				ft_is_digit(char format);
int				ft_parsing(const char *format, t_list *flags, va_list args);
void			ft_init(t_list *flags);
void			ft_check_flags(const char *format, t_list *flags);
void			ft_check_width(const char *format, t_list *flags, va_list args);
void			ft_check_precision(const char *format, t_list *flags,
va_list args);
void			ft_check_type(char format, t_list *flags, va_list args);
void			ft_check_type_perc(t_list *flags);
void			ft_convert_s(t_list *flags, va_list args);
void			ft_convert_c(t_list *flags, va_list args);
char			*ft_convert_x_p(size_t c);
void			ft_convert_p(t_list *flags, va_list args);
void			ft_convert_u(t_list *flags, va_list args);
void			ft_convert_d_i(t_list *flags, va_list args);
void			ft_convert_x(t_list *flags, va_list args);
void			ft_convert_xx(t_list *flags, va_list args);
void			wonderful_conversion(t_list *flags, unsigned int x, char *set);
void			ft_itoa_d(long int n, t_list *flags, size_t count);
void			ft_itoa_u(size_t n, t_list *flags, size_t count);
void			ft_itoa_writing_u(unsigned long n, t_list *flags, size_t count);
void			ft_itoa_writing_d(long int n, t_list *flags, size_t count);
void			ft_struct_analyze(t_list *flags);
int				ft_strlen(char *s);
size_t			ft_count(int n, t_list *flags);
void			ft_write_integer(t_list *flags);
void			ft_positive_number(t_list *flags);
void			ft_negative_number(t_list *flags);
void			ft_nn_zero_width(t_list *flags);
void			ft_nn_width_precision(t_list *flags);
void			ft_nn_minus_width_precision(t_list *flags);
void			ft_nn_precision_width(t_list *flags);
void			ft_zero_width(t_list *flags);
void			ft_minus_width_precision(t_list *flags);
void			ft_width_precision(t_list *flags);
void			ft_precision_width(t_list *flags);
void			ft_towrite(t_list *flags);
void			ft_write_width_char(t_list *flags);
void			ft_write_width(t_list *flags);
void			ft_write_width_minus(t_list *flags);
void			ft_write_string(t_list *flags);
void			ft_string_minus(t_list *flags);
void			ft_string_no_minus(t_list *flags);

#endif
