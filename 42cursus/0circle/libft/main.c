#include "libft.h"
#include <stdio.h>
#include <ctype.h>

int dp[1001];

int main(void)
{
	char **ret =  ft_split("asdfa  sdf  as  d  f", ' ');
	while (**ret)
	{
		printf("%s\n", *ret++);
	}
	return (0);
}
