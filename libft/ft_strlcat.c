/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: htaillef <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/30 14:10:38 by htaillef     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/30 14:10:41 by htaillef    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dstlen;

	dstlen = ft_strlen(dst);
	if (size <= dstlen)
		return (ft_strlen(src) + size);
	ft_strncat(dst, src, size - dstlen - 1);
	return (ft_strlen(src) + dstlen);
}
