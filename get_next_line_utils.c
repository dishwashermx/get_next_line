/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:34:42 by ghwa              #+#    #+#             */
/*   Updated: 2023/08/15 09:36:50 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <limits.h>

char	*ft_strjoin(char *s1, char *s2)
{
	int		count1;
	int		totalsize;
	int		destcount;
	char	*dest;

	if (!s1 || !s2)
		return (NULL);
	count1 = 0;
	totalsize = ft_strlen(s1) + ft_strlen(s2);
	destcount = 0;
	dest = malloc(totalsize + 1);
	if (!dest)
		return (NULL);
	while (s1[destcount] != '\0')
		dest[destcount++] = s1[count1++];
	count1 = 0;
	while (s2[count1] != '\0')
		dest[destcount++] = s2[count1++];
	dest[totalsize] = '\0';
	free (s1);
	return (dest);
}

char	*ft_calloc(size_t nitems, size_t size)
{
	size_t	totalsize;
	char	*ptr;
	int		i;

	i = 0;
	if (size == (SIZE_MAX) && nitems == (SIZE_MAX))
		return (NULL);
	else if ((size == 0 && nitems > (SIZE_MAX / 2))
		|| (nitems == 0 && size > (SIZE_MAX / 2)))
		i++;
	else if (size >= (SIZE_MAX / 2) || nitems >= (SIZE_MAX / 2))
		return (NULL);
	totalsize = size * nitems;
	ptr = malloc(totalsize);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, totalsize);
	return (ptr);
}

void	*ft_bzero(void *s, size_t n)
{
	int				ref;
	unsigned char	*dest;

	dest = (unsigned char *)s;
	ref = 0;
	while ((size_t)ref < n)
	{
		dest[ref] = 0;
		ref++;
	}
	return (dest);
}

int	ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	chrt;

	chrt = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == chrt)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	int		ref;
	int		temp;

	ref = start;
	temp = 0;
	if (!s)
		return (NULL);
	if (len == 0 || (((unsigned int)ft_strlen(s) <= (start)) && (start != 0)))
		return (ft_calloc(1, 1));
	if ((size_t)ft_strlen(s) > len)
		subs = malloc(len + 1);
	else
		subs = malloc(ft_strlen(s) + 1);
	if (!subs)
		return (NULL);
	while ((size_t)temp < len && s[ref] != '\0')
		subs[temp++] = s[ref++];
	subs[temp] = '\0';
	return (subs);
}
