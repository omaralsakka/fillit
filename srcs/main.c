/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelfa <oabdelfa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:51:19 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/08 13:32:06 by oabdelfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_lstdelcont(void *content, size_t content_size);

int	main(int argc, char **argv)
{
	t_list		*tmino_lst;
	size_t		size;
	uint16_t	bitmap[16];

	tmino_lst = NULL;
	ft_bzero(bitmap, sizeof(uint16_t) * 16);
	ft_checkargc(argc);
	ft_readtminos(argv[1], &tmino_lst);
	size = init_size(tmino_lst);
	solve(tmino_lst, tmino_lst, bitmap, &size);
	print_solution(tmino_lst, size);
	ft_lstdel(&tmino_lst, ft_lstdelcont);
	system("leaks fillit");
	return (0);
}

static void	ft_lstdelcont(void *content, size_t content_size)
{
	free(content);
	(void)content_size;
}
