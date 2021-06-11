#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	if (*needle == '\0')
		return ((char *) haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && (i + j) < len) // e se acabar aqui o haystack?
		{
			j++;
			if (needle[j] == '\0')
				return ((char *) &(haystack[i]));
			else if (needle[j] != haystack[i + j] || haystack[i + j] == '\0')
				break;
		}
		i++;
	}
	return (NULL);
}
