#include <stdio.h>

void	*ft_memset(void *s, const int c, size_t n);

int main()
{
	char a[10];
	char c = 'c';
	char *b = ft_memset(a, c, 5);
	printf("%s", b);
}