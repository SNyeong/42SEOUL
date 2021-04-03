/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 20:27:23 by seungnle          #+#    #+#             */
/*   Updated: 2021/04/04 06:08:32 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print(va_list ap, t_option *option)
{
	int		count;
	char	type;

	count = 0;
	type = option->type;
	if (type == 'c')
		count = ft_print_char(va_arg(ap, int), option);
	else if (type == '%')
		count = ft_print_char('%', option);
	else if (type == 's')
		count = ft_print_str(va_arg(ap, char *), option);
	else if (type == 'd' || type == 'i')
		count = ft_print_nb(va_arg(ap, int), option);
	else if (type == 'x' || type == 'X' || type == 'u')
		count = ft_print_nb(va_arg(ap, unsigned int), option);
	else if (type == 'p')
		count = ft_print_nb(va_arg(ap, unsigned long long), option);
	return (count);
}

void		check_wid_pr(char *str, va_list ap, t_option *option, int idx)
{
	if (ft_isdigit(str[idx]))
	{
		if (option->precision != -1)
			option->precision = option->precision * 10 + str[idx] - '0';
		else
			option->width = option->width * 10 + str[idx] - '0';
	}
	if (str[idx] == '*')
	{
		if (option->precision != -1)
			option->precision = va_arg(ap, int);
		else
		{
			option->width = va_arg(ap, int);
			if (option->width < 0)
			{
				option->minus = 1;
				option->width *= -1;
			}
		}
	}
}

void			check_flags(char *str, va_list ap, t_option *option, int idx)
{
	if (str[idx] == '0' && option->width == 0 && option->precision == -1)
		option->zero = 1;
	else if (str[idx] == '-')
		option->minus = 1;
	else if (str[idx] == '.')
		option->precision = 0;
	else if (ft_isdigit(str[idx]) || str[idx] == '*')
		check_wid_pr(str, ap, option, idx);
}

int			ft_parse(char *str, va_list ap)
{
	int			count;
	t_option	*option;
	int			idx;

	idx = 0;
	count = 0;
	if (!(option = malloc(sizeof(t_option))))
		return (-1);
	while (str[idx] != '\0')
	{
		while (str[idx] && str[idx] != '%')
			count += ft_putchar_fd(str[idx++]);
		if (str[idx] == '%')
		{
			init_option(option);
			while (str[++idx] && !ft_strchr(TYPE, str[idx]))
				check_flags(str, ap, option, idx);
			option->type = str[idx++];
			check_option(option);
			count += ft_print(ap, option);
		}
	}
	free(option);
	return (count);
}

int			ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;
	char	*s;

	s = (char *)str;
	count = 0;
	if (!ft_strchr(s, '%'))
		count = ft_putstr_fd(s);
	else
	{
		va_start(ap, str);
		count = ft_parse(s, ap);
		va_end(ap);
	}
	return (count);
}
