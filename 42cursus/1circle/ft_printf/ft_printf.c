/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 20:27:23 by seungnle          #+#    #+#             */
/*   Updated: 2020/11/19 07:12:42 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stddef.h>

int			check_type(char **str, va_list ap, t_option option)
{
	int		count;
	int		a;

	if (**str == 'c')
		return (ft_char_count((char)va_arg(ap, int)));
	else if (**str == 's')
	{
		++*str;
		return (ft_str_count(va_arg(ap, char *)));
	}
	a = option.len;
	return (0);
}

int			check_len(char **str, va_list ap, t_option option)
{
	if (**str == 'h')
	{
		++(*str);
		if (**str == 'h')
		{
			option.len = 1;
			++(*str);
		}
		else
			option.len = 2;
	}
	else if (**str == 'l')
	{
		++(*str);
		if (**str == 'l')
		{
			option.len = 3;
			++(*str);
		}
		else
			option.len = 4;
	}
	return (check_type(str, ap, option));
}

int			check_precision(char **str, va_list ap, t_option option)
{
	if (**str == '.')
	{
		++str;
		while (ft_isdigit(**str) || **str == '*')
		{
			if (ft_isdigit(**str))
			{
				option.precision = 0;
				while (ft_isdigit(**str))
					option.precision = option.precision * 10
					+ (*(*str++) - '0');
			}
			if (**str++ == '*')
				option.precision = va_arg(ap, int);
		}
	}
	return (check_len(str, ap, option));
}

int			check_width(char **str, va_list ap, t_option option)
{
	while (ft_isdigit(**str) || **str == '*')
	{
		if (ft_isdigit(**str))
		{
			option.width = 0;
			while (ft_isdigit(**str))
				option.width = option.width * 10 + (*(*str++) - '0');
		}
		if (**str++ == '*')
			option.width = va_arg(ap, int);
	}
	return (check_precision(str, ap, option));
}

int			check_flags(char **str, va_list ap)
{
	t_option	option;

	option = init_option();
	while (**str == '+' || **str == ' ' || **str == '#'
	|| **str == '-' || **str == '0')
	{
		if (**str == '#')
			option.flags[0] = 1;
		else if (**str == '+')
			option.flags[1] = 1;
		else if (**str == ' ')
			option.flags[2] = 1;
		else if (**str == '-')
			option.flags[3] = 1;
		else if (**str == '0')
			option.flags[4] = 1;
		++(*str);
	}
	return (check_width(str, ap, option));
}

int			ft_char_count(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int			ft_str_count(char *str)
{
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

t_option	init_option(void)
{
	int			a;
	t_option	option;

	a = -1;
	while (++a < 5)
	{
		option.flags[a] = 0;
	}
	option.precision = -1;
	option.width = -1;
	option.len = 0;
	option.type = 0;
	return (option);
}

int			count_n(char *str)
{
	int	count;

	while (*str && *(str + 1))
	{
		if (*str == '%' && *(str + 1) == 'n')
			++count;
		++str;
	}
	return (count);
}

int			ft_parse(char *str, va_list ap)
{
	int		count;
	int		*n_arr;
	void	**p_arr;
	int		n_count;

	n_count = count_n(str);
	n_arr = (int *)malloc(sizeof(int) * (n_count + 1));
	p_arr = (void **)malloc(sizeof(void *) * (n_count + 1));
	n_arr[n_count] = '\0';
	p_arr[n_count] = 0;
	count = 0;
	n_count = 0;
	while (*str)
	{
		while (*str && *str != '%')
			count += ft_char_count(*str++);
		if (*str)
		{
			++str;
			if (*str == '%')
				count += ft_char_count(*str++);
			else if (*str++ == 'n')
			{
				*n_arr++ = count;
				*p_arr++ = va_arg(ap, void *);
			}
			else
				count += check_flags(&str, ap);
		}
	}
	if (n_arr)
		free(n_arr);
	if (p_arr)
		free(p_arr);
	return (count);
}

int			ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;
	char	*s;

	s = (char *)str;
	if (!ft_strchr(s, '%'))
		ft_putstr_fd(s, 1);
	else
	{
		va_start(ap, str);
		count = ft_parse(s, ap);
		va_end(ap);
	}
	return (count);
}

int			test2(char **str)
{
	str[0]++;
	return (2);
}

int			test1(char **str)
{
	++*str;
	return (test2(str));
}

int			main(void)
{
	char	*str;
	int		a;

	a = 12;
	str = "0123456789";
	ft_printf("ab%nc%s\n", &a, str);
	printf("%d\n", a);
	return (0);
}
