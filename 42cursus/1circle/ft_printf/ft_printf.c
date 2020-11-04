/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 20:27:23 by seungnle          #+#    #+#             */
/*   Updated: 2020/11/05 04:55:01 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stddef.h>

int	ft_pirntf(const char *str, ...)
{
	va_list	ap;
	char	ch;
	int		for_n;

	va_start(ap, str);
//str을 한글자씩 읽어서 %가 없으면 그냥 한글자씩 출력

//%가 있으면 뒷글자들 확인
//flag 문자 확인
//-(왼쪽정렬) 0() . *
//bonus # +b
//width 문자 확인
//크기 문자 확인
//bonus modifier 확인
//l(long(d i) or u long(o u x X)) ll(long long(d i) or u long long(o u x X)) h(short(d i) or u short(o u x X)) hh(char(d i) or u char(o u x X))
//type 문자 확인
//c s p d i u x X %
//bounus n f g e
//상기 확인한 조건에 맞춰 출력
//반복
	while (*str)
	{
		if (*str != '%')
		{
			ft_putchar_fd(*str, 1);
			++str;
		}
		else
		{
			++str;
			if (*str == 'c' || *str == '%')
			{
				ft_putchar_fd(va_arg(ap, int), 1);
				++str;
			}
			else if (*str == 's')
			{
				ft_putstr_fd(va_arg(ap, char *), 1);
				++str;
			}
			else if (*str == 'p')
			{
				++str;
			}
			else if (*str == 'd')
			{
				ft_putstr_fd(ft_itoa(va_arg(ap, int)), 1);
				++str;
			}
			else if (*str == 'i')
			{
				++str;
			}
			else if (*str == 'u')
			{
				++str;
			}
			else if (*str == 'x')
			{
				++str;
			}
			else if (*str == 'X')
			{
				++str;
			}
			else if (*str == 'n')
			{
				++str;
			}
			else if (*str == 'f')
			{
				++str;
			}
			else if (*str == 'g')
			{
				++str;
			}
			else if (*str == 'e')
			{
				++str;
			}
		}
		
	}
	


	va_end(ap);
	return (0);
}

int main()
{
	printf("================type====================\n");
    printf("12. 문자 출력: %c \n", 'a');
    printf("13. 문자열 출력: %s \n", "Hello");
    printf("15. 메모리 주소 출력: %p \n", "Hello");
    printf("1. 십진수로 출력: %d \n", 123);
    printf("2. 부호있는 십진수로 출력: %i \n", 123);
    
    printf("4. 부호없는 십진수로 출력: %u \n", 123);
    printf("5. 부호없는 16진수로 출력(소문자): %x \n", 123);
    printf("6. 부호없는 16진수로 출력(대문자): %X \n", 123);
    printf("7. 부동 소수점 표기로 출력: %f \n", 123.45);
    printf("8. 지수형 표기로 출력(소문자): %e  \n", 123.45);
    
    printf("10. 간단한 표기로 출력(소문자): %g \n", 123.45);
    
    printf("14. 퍼센트 문자 출력: %%\n");
    
 
    printf("================flag====================\n");
    printf("1. flag 지정하지 않고 10진수로 출력: %8d \n", 123);
    printf("2. flag에 -를 지정하여 10진수로 출력: %-8d \n", 123);
    printf("3. flag에 +를 지정하여 10진수로 출력: %+d\n", 123);
    printf("4. flag 지정하지 않고 8진수로 출력: %o\n", 123);
    printf("5. flag에 #을 지정하여 8진수로 출력: %#o\n", 123);
    printf("6. flag 지정하지 않고 16진수로 출력:%X\n", 123);
    printf("7. flag에 #을 지정하여 16진수로 출력:%#X\n", 123);
 
    printf("===========width와 .prec, modifier ======\n");
    printf("1.flag #을 지정하여 16진수로 출력(대문자): %#X \n", 0x123456);
    printf("2.flag #, modifier h를 지정하여 16진수로 출력(대문자): %#hX \n", (unsigned short)0x123456);
    printf("3.flag #, width 12 지정하여 16진수로 출력(대문자): %#12X \n", 0x123456);
    printf("4.flag #, width 012 지정하여 16진수로 출력(대문자): %#012X \n", 0x123456);
    printf("5. .prec를 .3을 지정하여 부동 소수점 표기로 출력: %.3f \n", 123.456789);
 
 
    printf("===========1234567890123 출력 ===========\n");
    printf("1.hhd 사용: %hhd\n", (char)1234567890123);
    printf("2.hd 사용:%hd\n", (short)1234567890123);
    printf("3.ld 사용:%ld\n", 1234567890123);
    printf("4.lld 사용:%lld\n", (long long)1234567890123);
	
	int a = 0, b = 0;
	
	printf("===========%%n 출력 ===========\n");
	printf("1%n\n", &a);
	printf("a = %d\n", a);
	printf("123%n\na = %d\n456%n\n", &a, a, &b);
	printf("a = %d, b = %d\n", a, b);
	return (0);
}
