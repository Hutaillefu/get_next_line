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

int		get_next_line(const int fd, char **line)
{
	char			*text;
	int				ret;
	char			buffer[BUFF_SIZE + 1];
	static char		*rest;
	int				pos;

	if (fd == -1)
		return (-1);

	text = ft_strdup("");
	rest = NULL;

	if (rest && (pos = index_of(rest, '\n') != -1))
	{
		text = ft_strjoin(text, ft_strsub(rest, 0, pos));
		rest = ft_strsub(rest, pos, ft_strlen(rest) - pos);
		*line = text;
		return (1);
	}

	while ((ret = read(fd, buffer, BUFF_SIZE)))
	{
		if (rest)
		{
			ft_strjoin(text, rest);
			free(rest);
			rest = NULL;
		}

		buffer[ret] = '\0';

		pos = index_of(buffer, '\n');

		if (pos != -1)
		{
			text = ft_strjoin(text, ft_strsub(buffer, 0, pos));
			printf("%s\n", text);
			rest = ft_strsub(buffer, pos, ft_strlen(buffer) - pos);
			*line = text;
			return (1);
		}
		else
		{
			text = ft_strjoin(text, buffer);
			printf("%s\n", text);
		}
	}

	*line = text;
	return (0);
}
