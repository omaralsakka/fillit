/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelfa <oabdelfa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:02:23 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/08 13:26:21 by oabdelfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

uint16_t	clear_bit_pos(uint16_t val, uint8_t pos)
{
	return (val & ~(1 << pos));
}

uint16_t	read_grp(uint16_t val, uint8_t pos, uint8_t width)
{
	return ((val & msk_grp(pos, width)) >> pos);
}

uint16_t	write_grp(uint16_t val, uint16_t grp, uint8_t pos, uint8_t width)
{
	return ((~msk_grp(width, pos) & val) | (grp << pos));
}
