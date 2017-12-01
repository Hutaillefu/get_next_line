/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: htaillef <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/30 14:01:20 by htaillef     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/30 14:01:23 by htaillef    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*iterator;
	t_list	*res;

	iterator = lst;
	res = NULL;
	while (iterator)
	{
		ft_lst_push_back(&res, (*f)(iterator));
		iterator = iterator->next;
	}
	return (res);
}
