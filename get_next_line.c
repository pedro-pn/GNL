/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 00:53:11 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/04/29 17:37:53 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	check_buffer(int fd, char *buffer, char ***s_buffer)
{
	int	index;
	int	b_read;

	index = 0;
	while (buffer[index] && buffer[index] != '\n')
	{
		if (!buffer[index + 1])
		{
			b_read = read(fd, buffer, BUFFER_SIZE);
			buffer[b_read] = 0;
			if (b_read > 0)
				**s_buffer = ft_strjoin(**s_buffer, buffer);
			index = -1;
		}
		index++;
	}
}

void	fill_buffer(int fd, char **s_buffer)
{
	int		b_read;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE * sizeof(char) + 1));
	if (buffer == NULL)
		return ;
	b_read = read(fd, buffer, BUFFER_SIZE);
	if (b_read >= 0)
		buffer[b_read] = 0;
	else
	{	
		free(buffer);
		return ;
	}
	if (*s_buffer == NULL && b_read >= 0)
		*s_buffer = ft_strdup(buffer);
	else if (buffer && *s_buffer)
		*s_buffer = ft_strjoin(*s_buffer, buffer);
	check_buffer(fd, buffer, &s_buffer);
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
	new_sbuffer = ft_substr(s_buffer, index, ft_strlen(s_buffer) - index);
	free(s_buffer);
	return (new_sbuffer);
}

char	*get_next_line(int fd)
{
	static char	*s_buffer = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!s_buffer)
		fill_buffer(fd, &s_buffer);
	if (s_buffer && !ft_strchr(s_buffer, '\n'))
		fill_buffer(fd, &s_buffer);
	line = fill_line(s_buffer);
	s_buffer = clean_sbuffer(s_buffer);
	if (ft_strlen(line) == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
