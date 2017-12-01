/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: htaillef <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/30 14:13:49 by htaillef     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/30 14:17:51 by htaillef    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	isblank(unsigned char c)
{
	return (c == '\n' || ft_isblank(c) == 1);
}

char		*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	y;
	size_t	len;
	size_t	z;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	while (isblank((unsigned char)s[i]))
		i++;
	if (i == len)
		return (ft_memalloc(0));
	y = len - 1;
	z = 0;
	while (s[y] && isblank((unsigned char)s[y]))
	{
		y--;
		z++;
	}
	return (ft_strsub(s, i, len - i - z));
}
