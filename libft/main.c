
# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <stddef.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/errno.h>

#include "libft.h"

int	ft_strncmp1(const char *s1, const char *s2, size_t n)
{
	// unsigned char	*s1_ptr;
	// unsigned char	*s2_ptr;
	const char	*s1_ptr;
	const char	*s2_ptr;
	size_t			i;

	// s1_ptr = (unsigned char *)s1;
	// s2_ptr = (unsigned char *)s2;
	s1_ptr = s1;
	s2_ptr = s2;
	i = 0;
	while (i < n)
	{
		if (s1_ptr[i] != s2_ptr[i] || s1_ptr[i] == '\0')
			return ((int)s1_ptr[i] - (int)s2_ptr[i]);
		i++;
	}
	return (0);
}

int main() {
    char c1[245] = "aaaaa";
    char c2[245] = "aaaaa";
    c2[1] += 254;
    printf("%d,%d\n", ft_strncmp(c1, c2, 5), ft_strncmp1(c1, c2, 5));
    for (int i = -100; i < 256; i++)
    {
        char cc1 = 'a';
        unsigned char cc2 = 'a';
        cc1 += i;
        cc2 += i;
        printf("%d", (int)(cc1 == cc2));
    }
    printf("%c\n", (unsigned char)c2[1]);
    
}
