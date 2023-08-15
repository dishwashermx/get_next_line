/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:10:43 by ghwa              #+#    #+#             */
/*   Updated: 2023/08/15 09:35:01 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
// # define BUFFER_SIZE 1
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

char	*ft_strjoin(char *s1, char *s2);
char	*ft_calloc(size_t nitems, size_t size);
int		ft_strlen(const char *s);
void	*ft_bzero(void *s, size_t n);
char	*get_next_line(int fd);
int		ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif