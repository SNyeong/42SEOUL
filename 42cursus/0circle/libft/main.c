#include "libft.h"
#include <stdio.h>
#include <ctype.h>

int dp[1001];

int main(void)
{
	char **str;
	char *s = "lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse";
	char c = ' ';
	printf("%s\n", s);
	str = ft_split(s, c);
	printf("%s\n", s);
	int i = 0;
	while (str[i] != NULL)
	{
		printf("%s\n", str[i]);
		++i;
	}
	
	printf("%d\n", i);
	return (0);
}
