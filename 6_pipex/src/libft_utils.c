/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 15:00:23 by roaraujo          #+#    #+#             */
/*   Updated: 2021/12/31 00:14:18 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	int	qtd_caracteres;

	qtd_caracteres = 0;
	while (*s)
	{
		qtd_caracteres++;
		s++;
	}
	return (qtd_caracteres);
}

void	ft_free_ptr(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	char			*c;

	i = 0;
	c = (char *) s;
	while (i < n)
	{
		c[i] = '\0';
		i++;
	}
	return ;
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*allocdmem;

	allocdmem = (void *) malloc (nmemb * size);
	if (allocdmem == NULL)
		return (NULL);
	ft_bzero(allocdmem, nmemb * size);
	return (allocdmem);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((char *) dest)[i] = ((char *) src)[i];
		i++;
	}
	return (dest);
}

char	*ft_strdup(const char *s)
{
	unsigned int	strlength;
	char			*newstr;

	strlength = ft_strlen(s);
	newstr = ft_calloc((strlength + 1), sizeof(const char));
	if (newstr == NULL)
		return (NULL);
	newstr = ft_memcpy(newstr, s, strlength);
	return (newstr);
}

char	*ft_slashcat(const char* str1, const char *str2)
{
	char	*concat;
	int		i;

	concat = ft_calloc(ft_strlen(str1) + ft_strlen(str2) + 2, sizeof(char));
	if (concat == NULL || str1 == NULL || str2 == NULL)
		return (NULL);
	i = 0;
	while(*str1)
	{
		concat[i] = *str1;
		str1++;
		i++;
	}
	concat[i++] = '/';
	while (*str2)
	{
		concat[i] = *str2;
		str2++;
		i++;
	}
	concat[i] = '\0';
	return (concat);
}