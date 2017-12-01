/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: htaillef <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/30 14:01:38 by htaillef     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/30 14:01:40 by htaillef    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*tmp;

	tmp = ft_memalloc(sizeof(t_list));
	if (!tmp)
		return (NULL);
	tmp->next = NULL;
	if (!content)
	{
		tmp->content = NULL;
		tmp->content_size = 0;
	}
	else
	{
		tmp->content = ft_memalloc(content_size);
		ft_memcpy(tmp->content, content, content_size);
		ft_memcpy(&(tmp->content_size), &content_size, sizeof(content_size));
	}
	return (tmp);
}
