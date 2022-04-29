/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:00:25 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/04/29 15:18:01 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	len;
	size_t	len_s1;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len = len_s1 + ft_strlen(s2);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while(*s1 != 0)
	{
		*str = *s1;
		str++;
		s1++;
	}
	while(*s2 != 0)
	{
		*str = *s2;
		str++;
		s2++;
	}
	*str = 0;
	free(s1 - len_s1);
	return (str - len);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	s_len;
	size_t	counter;

	if (!*s)
		return (NULL);
	s_len = ft_strlen(s);
	counter = 0;
	ptr = (char *) malloc((s_len * sizeof(char)) + 1);
	if (!ptr)
		return (NULL);
	while (counter < s_len + 1)
	{
		ptr[counter] = s[counter];
		counter++;
	}
	return (ptr);
}

size_t	ft_strlen(const char *str)
{
	size_t	counter;

	counter = 0;
	if (!str)
		return (0);
	while (str[counter])
		counter++;
	return (counter);
}

// char	*get_line(char *s, int call, size_t len)
// {
// 	char	*sub;
// 	int		mem;
// 	int		start;
// 	int 	counter;
	
// 	start = 0;
// 	counter = 0;
// 	if (call != 1)
// 	{
// 		while (counter != call - 1)
// 		{
// 			if (!s[start] || s[start] == '\n')
// 				counter++;
// 			start++;
// 		}
// 	}
// 	mem = len - start;
// 	sub = (char *) malloc((mem * sizeof(char)) + 1);
// 	if (sub == NULL)
// 		return (NULL);
// 	sub[mem] = 0;
// 	while (mem > 0)
// 	{
// 		sub[mem - 1] = s[start + mem - 1];
// 		mem--;
// 	}
// 	return (sub);
// }

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	int		mem;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	mem = s_len - start;
	if (mem > (int) len)
		mem = len;
	if (mem <= 0)
		mem = 0;
	sub = (char *) malloc((mem * sizeof(char)) + 1);
	if (sub == NULL)
		return (NULL);
	sub[mem] = 0;
	while (mem > 0)
	{
		sub[mem - 1] = s[start + mem - 1];
		mem--;
	}
	return (sub);
}

int	check_line(char *str, ssize_t bytes_read, int call)
{
	int	index;
	int	counter;
	
	index = 0;
	counter = 0;
	while (str[index])
	{
		if (str[index] == '\n')
		{
			counter++;
			if (counter == call)
				return (index);
		}
		else if (bytes_read < BUFFER_SIZE && !str[index+1])
			return (index);
		index++;
	}
	return (-1);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	int		index;

	ptr = malloc(nmemb * size);
	index = (nmemb * size) - 1;
	if (ptr == NULL)
		return (ptr);
	while (index >= 0)
	{
		((unsigned char *)ptr)[index] = 0;
		index--;
	}
	return (ptr);
}
