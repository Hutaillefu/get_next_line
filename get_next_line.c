/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: htaillef <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 17:04:25 by htaillef     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/30 18:03:56 by htaillef    ###    #+. /#+    ###.fr     */
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
	int		pos;
	char	*res;
	char	*stock_ret;

	if ((pos = index_of(*stock, '\n')) >= 0)
	{
		stock_ret = *stock;
		if (!(res = ft_strsub(*stock, 0, pos)) ||
				!(*stock = ft_strsub(*stock, pos + 1,
						ft_strlen(*stock) - pos + 1)))
			return (NULL);
		free(stock_ret);
		stock_ret = NULL;
		return (res);
	}
	return (NULL);
}

int		read_line(int fd, char **stock, char **line, char **res)
{
	char			buffer[BUFF_SIZE + 1];
	int				ret;
	char			*stock_ret;

	while ((ret = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[ret] = '\0';
		stock_ret = *stock;
		if (ret == -1 || !(*stock = ft_strjoin(*stock, buffer)))
			return (-1);
		ft_strdel(&stock_ret);
		if ((*res = process(stock)))
		{
			*line = *res;
			return (1);
		}
	}
	if (!(*res) && ft_strlen(*stock) > 0)
	{
		if (!(*line = ft_strdup(*stock)))
			return (-1);
		ft_strdel(stock);
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char		*stock;
	char			*res;

	if (fd < 0 || !(line))
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
		if (!(stock = ft_strdup("")))
			return (-1);
	return (read_line(fd, &stock, line, &res));
}
