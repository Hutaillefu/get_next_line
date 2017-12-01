/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: htaillef <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/30 14:13:08 by htaillef     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/30 14:13:10 by htaillef    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		y;

	i = ft_strlen(s);
	y = i;
	while (i >= 0)
	{
		if (s[i] == c)
			return (char *)&s[i];
		i--;
	}
	if (c == '\0')
		return ((char *)&s[y]);
	return (NULL);
}
