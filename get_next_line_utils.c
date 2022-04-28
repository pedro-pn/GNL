/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:00:25 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/04/28 02:41:06 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1);
	len += ft_strlen(s2);
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
	while (str[counter])
		counter++;
	return (counter);
}

char	*get_line(char *s, int call, size_t len)
{
	char	*sub;
	int		mem;
	int		start;
	int 	counter;
	
	start = 0;
	counter = 0;
	if (call != 1)
	{
		while (counter != call - 1)
		{
			if (!s[start] || s[start] == '\n')
				counter++;
			start++;
		}
	}
	mem = len - start;
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
	return (0);
}