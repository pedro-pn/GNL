/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 01:53:36 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/05/03 19:48:34 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	char			*s_buffer;
	int				fd;
	struct s_list	*next;
}					t_list;

// From libft
t_list	*new_node(int fd);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
// GNL only
void	check_buffer(int fd, char *buffer, char ***s_buffer);
void	fill_buffer(int fd, char **s_buffer);
char	*fill_line(char *s_buffer, char **line);
void	*get_node(t_list **data, int fd);
char	*get_next_line(int fd);

#endif
