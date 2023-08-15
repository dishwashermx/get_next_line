/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:10:57 by ghwa              #+#    #+#             */
/*   Updated: 2023/08/15 09:36:40 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <limits.h>

int	ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*getorder(int customer, char *order)
{
	char	*sheet;
	int		letters;

	if (!order)
		order = ft_calloc(1, 1);
	letters = 0;
	sheet = ft_calloc(BUFFER_SIZE + 2, 1);
	if (!sheet)
		return (NULL);
	while (!ft_strchr(order, '\n'))
	{
		letters = read(customer, sheet, BUFFER_SIZE);
		if (letters < 0 || (letters == 0 && sheet[0] == '\0'))
		{
			free (sheet);
			return (NULL);
		}
		order = ft_strjoin(order, sheet);
	}
	free (sheet);
	return (order);
}

char	*currentdish(char *order)
{
	unsigned int	i;
	char			*dish;

	i = 0;
	if (!*order)
		return (NULL);
	while (order[i] != '\0' && order[i] != '\n')
		i++;
	dish = ft_substr(order, 0, i + 1);
	return (dish);
}

char	*nextdishes(char *order)
{
	int		count;
	char	*neworder;

	count = 0;
	if (!ft_strchr(order, '\n'))
	{
		free (order);
		return (NULL);
	}
	while (order[count] != '\0' && order[count] != '\n')
		count++;
	neworder = ft_substr(order, count + 1, ft_strlen(order));
	free (order);
	return (neworder);
}

char	*get_next_line(int customer)
{
	static char	*order;
	char		*plate;

	if (customer < 0 || BUFFER_SIZE < 1)
		return (NULL);
	order = getorder(customer, order);
	if (!order)
		return (NULL);
	plate = currentdish(order);
	order = nextdishes(order);
	return (plate);
}

// int	main(void)
// {
// 	int		fd;
// 	int		i ;
// 	char	*str;

// 	i = 100;
// 	fd = open ("1.txt", O_RDONLY);
// 	while (i > 0)
// 	{
// 		str = get_next_line(fd);
// 		printf("%s\n", str);
// 		free (str);
// 		i--;
// 	}
// 	close (fd);
// 	// system("leaks a.out");
// 	return (0);
// }