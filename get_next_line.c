/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: htaillef <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 17:04:25 by htaillef     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 18:56:55 by htaillef    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		index_of(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*process(char **stock)
{
	int	pos;
	char	*res;
	char	*stock_ret;

	if ((pos = index_of(*stock, '\n')) >= 0) // \n found
	{
		stock_ret = *stock;
		res = ft_strsub(*stock, 0, pos);
		*stock = ft_strsub(*stock, pos + 1, ft_strlen(*stock) - pos + 1);
		free(stock_ret);
		stock_ret = NULL;
		return (res);
	}
	return (NULL);
}

int	get_next_line(const int fd, char **line)
{
	int			ret;
	char			buffer[BUFF_SIZE + 1];
	static char		*stock;
	char			*stock_ret;
	char			*res;

	if (fd == -1)
		return (-1);

	if (stock)
	{
		if ((res = process(&stock)))
		{
			*line = res;
			return (1);
		}
	}

	if (!stock)
		stock = ft_strdup("");
	while ((ret = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[ret] = '\0';
		stock_ret = stock;
		stock = ft_strjoin(stock, buffer);
		free(stock_ret);
		stock_ret = NULL;
		if ((res = process(&stock)))
		{
			*line = res;
			return (1);
		}
	}

	return (0);
}
