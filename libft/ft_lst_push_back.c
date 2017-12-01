/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lst_push_back.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: htaillef <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/30 14:00:13 by htaillef     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/30 14:00:15 by htaillef    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_push_back(t_list **lst, t_list *new)
{
	t_list *iterator;

	if (!(*lst))
	{
		(*lst) = new;
		return ;
	}
	iterator = *lst;
	while (iterator->next)
		iterator = iterator->next;
	iterator->next = new;
}
