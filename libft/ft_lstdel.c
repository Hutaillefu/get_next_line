/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: htaillef <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/30 14:00:43 by htaillef     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/30 14:00:47 by htaillef    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstdel_rec(t_list *alst, void (*del)(void *, size_t))
{
	if (alst->next)
		ft_lstdel_rec(alst->next, (*del));
	if (alst)
		ft_lstdelone(&alst, (*del));
}

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *iterator;

	iterator = *alst;
	ft_lstdel_rec(iterator, (*del));
	*alst = NULL;
}
