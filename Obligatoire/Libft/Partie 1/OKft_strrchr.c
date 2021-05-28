#include "libft.h"
char	*ft_strrchr(const char *s, int c)
{
	int	length;

	length = ft_strlen(s);
	while (--length >= 0)
	{
		if (s[length] == c)
			return ((char *) s + length);
	}
	return (NULL);
}
