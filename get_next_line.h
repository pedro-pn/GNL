/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 01:53:36 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/04/28 19:07:19 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

char	*ft_strjoin(char *s1, char const *s2);
char	*get_line(char *s, int call, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
int		check_line(char *str, ssize_t bytes_read, int call);
char	*get_next_line(int fd);

#endif
