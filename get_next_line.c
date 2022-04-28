/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 00:53:11 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/04/28 16:25:57 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
// #include "../libft/ft_putstr_fd.c"
// #include "../libft/ft_putchar_fd.c"

// void	ft_putstr_fd(char *s, int fd);
// void	ft_putchar_fd(char c, int fd);

char	*check_null(char *str, ssize_t bytes_read)
{
	
	if (bytes_read == 0)
	{
		free(str);
	}
	// else if (bytes_read == 0)
	return NULL;
}

char	*get_next_line(int fd)
{
	static ssize_t	bytes_read = 0;
	static char		*acu;
	static char 			*str;
	static int		call = 0;
	static int		line = 0;

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
		//	call++;
		 	return (check_null(str, bytes_read));
		}
		str[bytes_read] = '\0';
		if (call == 0)
		{
			acu = ft_strdup(str);
			call++;
		}
		else
			acu = ft_strjoin(acu, str);
		//printf("acu: %s", acu);
		line++;
		if (check_line(acu, bytes_read, call) != -1 || bytes_read < BUFFER_SIZE)
		{	
			call++;
			line = 0;
			return (get_line(acu, call - 1, check_line(acu, bytes_read, call-1) + 1));
		}
	}
}
