#include "libft.h"

//////////////////////////////////////////////////////////////     D E  B U G

// size_t	ft_strlen(const char *s)
// {
// 	int	qtd_caracteres;

// 	qtd_caracteres = 0;
// 	while (*s)
// 	{
// 		qtd_caracteres++;
// 		s++;
// 	}
// 	return (qtd_caracteres);
// }

// void	ft_bzero(void *s, size_t n)
// {
// 	unsigned int	i;
// 	char			*c;

// 	i = 0;
// 	c = (char *) s;
// 	while (i < n)
// 	{
// 		c[i] = '\0';
// 		i++;
// 	}
// 	return ;
// }

// void	*ft_calloc(size_t nmemb, size_t size)
// {
// 	void	*allocdmem;

// 	allocdmem = (void *) malloc (nmemb * size);
// 	if (allocdmem == NULL)
// 		return (NULL);
// 	ft_bzero(allocdmem, nmemb * size);
// 	return (allocdmem);
// }

// void	*ft_memcpy(void *dest, const void *src, size_t n)
// {
// 	unsigned int	i;

// 	if (dest == NULL && src == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (i < n)
// 	{
// 		((char *) dest)[i] = ((char *) src)[i];
// 		i++;
// 	}
// 	return (dest);
// }

// char	*ft_strdup(const char *s)
// {
// 	unsigned int	strlength;
// 	char			*newstr;

// 	strlength = ft_strlen(s);
// 	newstr = ft_calloc((strlength + 1), sizeof(const char));
// 	if (newstr == NULL)
// 		return (NULL);
// 	newstr = ft_memcpy(newstr, s, strlength);
// 	return (newstr);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*substring;
// 	size_t	slength;
// 	size_t	i;

// 	slength = ft_strlen(s);
// 	if (start >= slength)
// 		return (ft_strdup(""));
// 	if (slength - start < len)
// 		len = slength - start;
// 	substring = malloc((len + 1) * sizeof(char));
// 	i = 0;
// 	while (s[i + start] && (i < len))
// 	{
// 		substring[i] = s[start + i];
// 		i++;
// 	}
// 	substring[len] = '\0';
// 	return (substring);
// }

// char	*ft_strchr(const char *s, int c)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == (unsigned char) c)
// 			return ((char *)s + i);
// 		i++;
// 	}
// 	if (s[i] == (unsigned char) c)
// 		return ((char *)s + i);
// 	return (NULL);
// }

// char	*ft_strtrim(char const *s1, char const *set)
// {
// 	size_t	i;

// 	if (s1 == NULL || set == NULL)
// 		return (NULL);
// 	while (ft_strchr(set, *s1) && *s1)
// 		s1++;
// 	i = ft_strlen(s1);
// 	while (ft_strchr(set, s1[i - 1]) && i)
// 		i--;
// 	return (ft_substr(s1, 0, i));
// }

//////////////////////////////////////////////////////////////

static int	count_words(const char *s, char delimiter)
{
	size_t	word_count;

	word_count = 1;
	while((s = ft_strchr(s, delimiter)) && *s)
	{
		while (*s == delimiter)
			s++;
		word_count++;
	}
	return (word_count);
}

char	**ft_split(char const *s, char delimiter)
{
	char	**morsels;
	size_t	word_count;
	size_t	i;
	size_t	word_length;

	s = ft_strtrim(s, &delimiter);
	// if (*s == '\0')
	// 	return (ft_strdup(""));

	// contar qtas palavras tem
	word_count = count_words(s, delimiter);

	// alocar memória
	morsels = malloc((word_count + 1) * sizeof(*morsels));
	if (morsels == NULL)
		return (NULL);

	// montar palavras
	i = 0;
	while(++i <= word_count)
	{
		while (*s && *s == delimiter)
			s++;
		word_length = 0;
		while(s[word_length] != delimiter && s[word_length])
			word_length++;
		morsels[i - 1] = ft_substr(s, 0, word_length);
		if (morsels[i - 1] == NULL)
			return (NULL);
		s += word_length;
	}

	//devolver palavras
	morsels[word_count] = NULL;
	return (morsels);
}

// #include <stdio.h>
// int main()
// {
// 	char **tab = ft_split("tripouille", 0);
// 	printf("%s\n", tab[0]);
// 	return 0;
// }