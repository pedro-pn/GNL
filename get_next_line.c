/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 00:53:11 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/04/29 15:24:38 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
// #include "../libft/ft_putstr_fd.c"
// #include "../libft/ft_putchar_fd.c"

// void	ft_putstr_fd(char *s, int fd);
// void	ft_putchar_fd(char c, int fd);

void	fill_buffer(int fd, char **s_buffer)
{
	/*na segunda chamada do fill buffer, ele não concatena*/
	int		index;
	int		b_read;
	char	*buffer;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buffer == NULL)
		return ;
	index = -1;
	b_read = read(fd, buffer, BUFFER_SIZE);
	if (*s_buffer == NULL && b_read >= 0)
		*s_buffer = ft_strdup(buffer);
	else if (buffer && *s_buffer)
		*s_buffer = ft_strjoin(*s_buffer, buffer);
	while (index++, buffer[index] && buffer[index] != '\n')
	{
		if (!buffer[index + 1])
		{
			b_read = read(fd, buffer, BUFFER_SIZE);
			buffer[b_read] = 0;
			if (b_read > 0)
				*s_buffer = ft_strjoin(*s_buffer, buffer);
			index = -1;
			continue ;
		}
	}
//	printf("%s", *s_buffer);
	free(buffer);
}

char	*fill_line(char *s_buffer)
{
	char	*line;
	int		index;
	int		l_len;

	if (s_buffer == NULL)
		return (NULL);
	index = 0;
	l_len = 0;
	while (s_buffer[index] && s_buffer[index] != '\n')
	{
		l_len++;
		index++;
	}
	if (s_buffer[index] == '\n')
		l_len++;
	line = ft_substr(s_buffer, 0, l_len);
	return (line);
}

char	*clean_sbuffer(char *s_buffer)
{
	int		index;
	char	*new_sbuffer;
		
	index = 0;
	new_sbuffer = NULL;
	if (s_buffer == NULL)
		return (NULL);
	while (s_buffer[index] != '\n' && s_buffer[index])
		index++;
	if (s_buffer[index] == '\n')
		index++;
//	if (s_buffer[index] == '\n' && s_buffer[index + 1]) // desativar essa condição é interessante as veis
		new_sbuffer = ft_substr(s_buffer, index, ft_strlen(s_buffer) - index);
	free(s_buffer);
	return (new_sbuffer);
}

char	*ft_strchr(const char *s, int c)
{
	int		counter;
	int		len_s;

	counter = 0;
	len_s = (int) ft_strlen(s);
	while (counter <= len_s)
	{
		if (s[counter] == (unsigned char) c)
			return (&((char *)s)[counter]);
		counter++;
	}
	return (NULL);
}

void	check_sbuffer(int fd, char **s_buffer)
{
	//int		index;
	int		b_read;
	char	*buffer;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buffer == NULL)
		return ;
//	index = 0;
	b_read = read(fd, buffer, BUFFER_SIZE);
	if (b_read < 0)
		return ;
	if (b_read > 0)
	{
		*s_buffer = ft_strjoin(*s_buffer, buffer);
	}
	free(buffer);

	
}

char	*get_next_line(int fd)
{
	static char		*s_buffer = NULL;
//	char 			*buffer;
	char			*line;

	if (fd < 0 || fd == 1000)
		return (NULL);
	
	if (!s_buffer)
		fill_buffer(fd, &s_buffer);
	if (s_buffer && !ft_strchr(s_buffer, '\n'))
		fill_buffer(fd, &s_buffer);
	
	line = fill_line(s_buffer);
	//printf("***%s***", s_buffer);
	s_buffer = clean_sbuffer(s_buffer);
//	printf("***%s***", s_buffer);
	if (ft_strlen(line) == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
