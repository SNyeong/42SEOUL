/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 20:27:23 by seungnle          #+#    #+#             */
/*   Updated: 2020/10/30 21:51:39 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putchar(char ch)
{
	write(1, &ch, 1);
}

void ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int	ft_pirntf(const char *str, ...)
{
	va_list ap;
	char ch;

	va_start(ap, str);
//str을 한글자씩 읽어서 %가 없으면 그냥 한글자씩 출력
	while (*str)
	{
		if (*str != '%')
		{
			ft_putchar(*str);
			++str;
		}
		else
		{
			++str;
			if (*str == 'd')
			{
				ft_putstr(ft_itoa(va_arg(ap, int)));
			}
			++str;
		}
		
	}
	
//%가 있으면 뒷글자들 확인
//arg number 확인
//flag 문자 확인
//width 문자 확인
//precision 문자 확인
//type 문자 확인
//상기 확인한 조건에 맞춰 출력
//반복

	va_end(ap);
	return (0);
}

int main()
{
	char *str = "abcd %d\na";

	ft_pirntf(str, -123);
	return (0);
}
