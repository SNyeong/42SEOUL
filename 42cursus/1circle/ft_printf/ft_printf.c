/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 20:27:23 by seungnle          #+#    #+#             */
/*   Updated: 2020/11/12 20:40:02 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stddef.h>

int			check_len(char *str, va_list ap, t_option option)
{
	if (*str == 'h')
	{
		++str;
		if (*str == 'h')
		{
			option.o_len = 1;
			++str;
		}
		else
			option.o_len = 2;
	}
	else if (*str == 'l')
	{
		++str;
		if (*str == 'l')
		{
			option.o_len = 3;
			++str;
		}
		else
			option.o_len = 4;
	}
	return (check_type(str, ap, option));
}

int			check_precision(char *str, va_list ap, t_option option)
{
	if (*str == '.')
	{
		++str;
		while (ft_isnum(*str) || *str == '*')
		{
			if (ft_isnum(*str))
			{
				option.o_precision = 0;
				while (ft_isnum(*str))
					option.o_precision = option.o_precision * 10
					+ (*(str++) - '0');
			}
			if (*str++ == '*')
				option.o_precision = va_arg(ap, int);
		}
	}
	return (check_len(str, ap, option));
}

int			check_width(char *str, va_list ap, t_option option)
{
	while (ft_isnum(*str) || *str == '*')
	{
		if (ft_isnum(*str))
		{
			option.o_width = 0;
			while (ft_isnum(*str))
				option.o_width = option.o_width * 10 + (*(str++) - '0');
		}
		if (*str++ == '*')
			option.o_width = va_arg(ap, int);
	}
	return (check_precision(str, ap, option));
}

int			check_flags(char *str, va_list ap)
{
	t_option	option;

	option = init_option(option);
	while (*str == '+' || *str == ' ' || *str == '#'
	|| *str == '-' || *str == '0')
	{
		if (*str == '#')
			option.o_flags[0] = 1;
		else if (*str == '+')
			option.o_flags[1] = 1;
		else if (*str == ' ')
			option.o_flags[2] = 1;
		else if (*str == '-')
			option.o_flags[3] = 1;
		else if (*str == '0')
			option.o_flags[4] = 1;
		++str;
	}
	return (check_width(str, ap, option));
}

int			ft_char_count(char c, int fd)
{
	ft_putchar_fd(c, fd);
	return (1);
}

t_option	init_option(t_option option)
{
	int	a;

	a = -1;
	while (++a < 5)
	{
		option.o_flags[a] = 0;
	}
	option.o_precision = -1;
	option.o_width = -1;
	option.o_len = 0;
	option.o_type = 0;
}

int			ft_parse(char *str, va_list ap)
{
	int count;

	count = 0;
	while (*str)
	{
		while (*str && *str != '%')
			count += ft_char_count(*str++, 1);
		if (*str)
		{
			++str;
			if (*str == '%')
			{
				count += ft_char_count(*str++, 1);
			}
			count += check_flags(str, ap);
		}
	}
	return (count);
}

int			ft_pirntf(const char *str, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, str);
	count = ft_parse((char *)str, ap);
	va_end(ap);
	return (count);
}
