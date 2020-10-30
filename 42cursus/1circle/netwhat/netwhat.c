#include <stdio.h>

int main()
{
	int i = 32 - 13;
	int ret = 1;

	for(int ti = 0; ti < i; ti++)
	{
		ret *= 2;
	}
	ret = ret - 2;
	printf("%d\n\n\n", ret);

	int og = 213;
	int ma = 4;
	int start, end;

	start = (og / ma) * ma;
	end = start + ma - 1;
	printf("%d  --  %d", start, end);
	return (0);
}

/* 마스크 넘버
1 9  17 25 ==== 128 128
2 10 18 26 ==== 192 64
3 11 19 27 ==== 224 32
4 12 20 28 ==== 240 16
5 13 21 29 ==== 248 8
6 14 22 30 ==== 252 4
7 15 23 31 ==== 254 2
8 16 24 32 ==== 255 1
*/
