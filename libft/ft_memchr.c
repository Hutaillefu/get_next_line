/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: htaillef <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/30 14:02:21 by htaillef     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/30 14:02:23 by htaillef    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*iterator;
	size_t			i;

	iterator = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (iterator[i] == (unsigned char)c)
			return (&iterator[i]);
		i++;
	}
	return (NULL);
}
