/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:10:57 by ghwa              #+#    #+#             */
/*   Updated: 2023/08/15 16:56:55 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <limits.h>

char	*freeandreturn(char *cfree, char *creturn)
{
	free (cfree);
	return (creturn);
}

char	*getorder(int customer, char *order)
{
	char	*sheet;
	int		letters;

	if (!order)
		order = ft_strdup("");
	letters = 0;
	sheet = malloc(BUFFER_SIZE + 1);
	if (!sheet)
		return (NULL);
	while (!ft_strchr(order, '\n'))
	{
		letters = read(customer, sheet, BUFFER_SIZE);
		if (letters < 0 || (order[0] == '\0' && letters == 0))
		{
			if (order[0] == '\0' )
				free (order);
			return (freeandreturn(sheet, NULL));
		}
		sheet[letters] = '\0';
		order = ft_strjoin(order, sheet);
		if (letters < BUFFER_SIZE)
			break ;
	}
	return (freeandreturn(sheet, order));
}

char	*currentdish(char *order)
{
	unsigned int	i;
	char			*dish;

	i = 0;
	if (!*order)
		return (NULL);
	while (order[i] != '\n' && order[i] != '\0')
		i++;
	if (order[i] == '\n')
		i++;
	dish = ft_substr(order, 0, i);
	return (dish);
}

char	*nextdishes(char *order)
{
	int		letters;
	char	*neworder;

	letters = 0;
	if (!ft_strchr(order, '\n'))
		return (freeandreturn(order, NULL));
	while (order[letters] != '\0' && order[letters] != '\n')
		letters++;
	neworder = ft_substr(order, letters + 1, ft_strlen(order));
	return (freeandreturn(order, neworder));
}

char	*get_next_line(int customer)
{
	static char	*order[OPEN_MAX];
	char		*plate;

	if (customer < 0 || BUFFER_SIZE < 1)
		return (NULL);
	order[customer] = getorder(customer, order[customer]);
	if (!order[customer])
		return (NULL);
	else if (order[customer][0] == '\0')
		return (freeandreturn(order[customer], NULL));
	plate = currentdish(order[customer]);
	order[customer] = nextdishes(order[customer]);
	return (plate);
}

// int	main(void)
// {
// 	int		fd;
// 	int		i;
// 	char	*str;

// 	i = 2;
// 	fd = open ("3.txt", O_RDONLY);
// 	while (i > 0)
// 	{
// 		str = get_next_line(fd);
// 		printf("%s", str);
// 		free (str);
// 		i--;
// 	}
// 	close (fd);
// 	// system("leaks a.out");
// 	return (0);
// }
