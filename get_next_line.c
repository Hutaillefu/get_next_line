/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: htaillef <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 17:04:25 by htaillef     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/30 15:37:15 by htaillef    ###    #+. /#+    ###.fr     */
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

char	*process(char **stock, int *error)
{
	int		pos;
	char	*res;
	char	*stock_ret;

	if ((pos = index_of(*stock, '\n')) >= 0)
	{
		stock_ret = *stock;
		if (!(res = ft_strsub(*stock, 0, pos)) ||
				!(*stock = ft_strsub(*stock, pos + 1,
						ft_strlen(*stock) - pos + 1)))
		{
			*error = 1;
			return (NULL);
		}
		free(stock_ret);
		stock_ret = NULL;
		return (res);
	}
	return (NULL);
}

int		get_next_line(const int fd, char **line)
{
	int				ret;
	int				error;
	char			buffer[BUFF_SIZE + 1];
	static char		*stock;
	char			*stock_ret;
	char			*res;

	if (fd < 0 || !(line))
		return (-1);
	error = 0;
	if (stock)
	{
		if ((res = process(&stock, &error)))
		{
			*line = res;
			return (1);
		}
		else if (error)
			return (-1);
	}
	if (!stock)
		if (!(stock = ft_strdup("")))
			return (-1);
	while ((ret = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[ret] = '\0';
		stock_ret = stock;
		if (ret == -1 || !(stock = ft_strjoin(stock, buffer)))
			return (-1);
		free(stock_ret);
		stock_ret = NULL;
		error = 0;
		if ((res = process(&stock, &error)))
		{
			*line = res;
			return (1);
		}
		else if (error)
			return (-1);
	}
	if (!res && ft_strlen(stock) > 0)
	{
		if (!(*line = ft_strdup(stock)))
			return (-1);
		free(stock);
		stock = NULL;
		return (1);
	}
	return (0);
}
