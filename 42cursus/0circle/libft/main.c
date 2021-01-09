#include "libft.h"
#include <stdio.h>
#include <ctype.h>

int dp[1001];

int main(void)
{
	char **ret = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
	int	i = 0;
	while (ret[i])
	{
		printf("|%s|\n", ret[i++]);
	}
	return (0);
}
