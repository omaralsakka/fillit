/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelfa <oabdelfa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:54:47 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/08 13:26:58 by oabdelfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		place_tmino(t_tmino *tmino, uint16_t *bitmap, size_t size);
static int		try_tmino(t_tmino *tmino, uint16_t *bitmap, size_t size);
static void		reset_pos(t_list *node);
static t_list	*del_tmino(t_list *node, uint16_t *bitmap, size_t size);

void	solve(t_list *head, t_list *lst, uint16_t *bitmap, size_t *size)
{
	t_tmino		*tmino;

	if (lst == NULL)
		return ;
	tmino = ((t_tmino *)(lst->content));
	if (try_tmino(tmino, bitmap, *size))
	{
		place_tmino(tmino, bitmap, *size);
		solve(head, lst->next, bitmap, size);
	}
	else
	{
		if (tmino->id == 0 && tmino->pos >= last_pos(tmino, *size))
		{
			(*size)++;
			ft_lstiter(head, reset_pos);
			ft_bzero(bitmap, sizeof(uint16_t) * 16);
		}
		else
		{
			reset_pos(lst);
			lst = del_tmino(lst_find_id(head, tmino->id - 1), bitmap, *size);
		}
		solve(head, lst, bitmap, size);
	}
}

static void	reset_pos(t_list *node)
{
	((t_tmino *)(node->content))->pos = 0;
}

/*
**	Use the tetrimino's 'row' and 'col' fields, to
**	write the 'bits' field to the bitmap.
*/
static void	place_tmino(t_tmino *tmino, uint16_t *bitmap, size_t size)
{
	size_t		bmap_row;
	size_t		bmap_col;
	size_t		tmino_idx;

	tmino_idx = 0;
	while (tmino_idx < WIDTH_UINT16)
	{
		bmap_row = (tmino->pos / size) + (tmino_idx / WIDTH_NIBBLE);
		bmap_col = (tmino->pos % size) + (tmino_idx % WIDTH_NIBBLE);
		if (test_bit_pos(tmino->bits, tmino_idx))
			bitmap[bmap_row] = set_bit_pos(bitmap[bmap_row], bmap_col);
		tmino_idx++;
	}
}

static t_list	*del_tmino(t_list *node, uint16_t *bitmap, size_t size)
{
	size_t		bmap_row;
	size_t		bmap_col;
	size_t		tmino_idx;
	t_tmino		*tmino;

	tmino_idx = 0;
	tmino = (t_tmino *)(node->content);
	while (tmino_idx < WIDTH_UINT16)
	{
		bmap_row = (tmino->pos / size) + (tmino_idx / WIDTH_NIBBLE);
		bmap_col = (tmino->pos % size) + (tmino_idx % WIDTH_NIBBLE);
		if (test_bit_pos(tmino->bits, tmino_idx))
			bitmap[bmap_row] = clear_bit_pos(bitmap[bmap_row], bmap_col);
		tmino_idx++;
	}
	tmino->pos++;
	return (node);
}

/*
**	Check if a tetrimino can be placed without any collision (with the bits
**	of other tetriminos or with the bitmap borders) at the coordinates given
**	by the 'row' and 'col' arguments.
**	Return '0' if the tetrimino can be placed; '1' otherwise.
*/
static int	try_tmino(t_tmino *tmino, uint16_t *bitmap, size_t size)
{
	uint16_t	tmino_bit;
	uint16_t	bmap_bit;
	uint16_t	tmino_idx;

	while (tmino->pos <= last_pos(tmino, size))
	{
		if (!check_right_side(tmino, size))
			tmino->pos = ((tmino->pos / size) + 1) * size;
		tmino_idx = 0;
		while (tmino_idx < WIDTH_UINT16)
		{
			tmino_bit = test_bit_pos(tmino->bits, tmino_idx);
			bmap_bit = test_bit_pos(bitmap[(tmino->pos / size) + \
				(tmino_idx / WIDTH_NIBBLE)], \
				(tmino->pos % size) + (tmino_idx % WIDTH_NIBBLE));
			if (tmino_bit && bmap_bit)
				break ;
			tmino_idx++;
		}
		if (tmino_idx == WIDTH_UINT16)
			return (1);
		tmino->pos++;
	}
	return (0);
}
