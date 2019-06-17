#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	unsigned int	i;
	char		*cpy;

	if (!(cpy = (char *)malloc(sizeof(*cpy) * (n + 1))))
		return (NULL);
	i = 0;
	while (*s && i < n)
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
