/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 00:53:11 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/04/28 19:45:13 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
// #include "../libft/ft_putstr_fd.c"
// #include "../libft/ft_putchar_fd.c"

// void	ft_putstr_fd(char *s, int fd);
// void	ft_putchar_fd(char c, int fd);

char	*check_null(char *str, ssize_t bytes_read, char *acu, int call)
{
	
	if (bytes_read == 0)
	{
		free(str);
		if (call) // remover essa condição se consertar 41_with_nl
			free(acu);
	}
	// else if (bytes_read == 0)
	return NULL;
}

void	fill_null(char *str, ssize_t bytes_read)
{
	int	index;
	// str tem 43 bytes INDEX_MAX= 42
	index = 0;

	while (index <= BUFFER_SIZE)
	{
		if (index >= bytes_read)
			str[index] = 0;
		index++;
	}

}

int	check_acu(char *acu, int call)
{
	int	index;
	int flag;

	flag = 0;
	index = 0;
	
	if (BUFFER_SIZE == 1)
		return (1);
	while (acu[index])
	{
		if (acu[index] == '\n')
			flag++;
		if (acu[index] == '\n' && acu[index + 1] && flag == call)
			return 0;
		index++;
	}
	return 1;
}

char	*get_next_line(int fd)
{
	static ssize_t	bytes_read = 0;
	static char		*acu;
	static char 	*str;
	static int		call = 0;
	static int		line = 0;
	char			*line_read;
//	static int				lr_len = 0;

	if (fd < 0 || fd == 1000)
		return (NULL);
	if (call == 0)
		str = malloc((sizeof(char) * BUFFER_SIZE) + 1);
//	printf("fora acu: %s\n", acu);
	while (1)
	{
		bytes_read = read(fd, str, BUFFER_SIZE);
		if (bytes_read <= 0 && line == 0)
		{	
		 	return (check_null(str, bytes_read, acu, call)); // remover call, talvez n seja necessario
		}
		fill_null(str, bytes_read); // talvez essa função, não seja necessaria ( str[BYTES_READ] = 0)
		if (call == 0)
		{
			acu = ft_strdup(str);
			call++;
		}
		else
			acu = ft_strjoin(acu, str);
	//	printf("acu: %s", acu);
		line++;
		if (check_line(acu, bytes_read, call) != -1 || bytes_read < BUFFER_SIZE)
		{	
			call++;
			line_read = get_line(acu, call - 1, check_line(acu, bytes_read, call-1) + 1);
			if (check_acu(acu, call - 1) || bytes_read < BUFFER_SIZE)
				line = 0;
			//lr_len = ft_strlen(line_read);
			return (line_read);
		}
	}
}
