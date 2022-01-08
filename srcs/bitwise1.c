/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelfa <oabdelfa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 13:25:25 by oabdelfa          #+#    #+#             */
/*   Updated: 2022/01/08 13:26:18 by oabdelfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

uint8_t	test_bit_pos(uint16_t val, uint8_t pos)
{
	return ((val & 1 << pos) > 0);
}

uint16_t	set_bit_pos(uint16_t val, uint8_t pos)
{
	return (val | 1 << pos);
}

uint8_t	test_bit_msk(uint16_t value, uint16_t mask)
{
	return ((value & mask) > 0);
}

uint8_t	test_col_bitmap(uint16_t *value, size_t pos)
{
	uint16_t	mask;
	int			i;

	i = 0;
	mask = 1;
	mask <<= pos;
	while (i < WIDTH_UINT16)
	{
		if (test_bit_msk(value[i], mask))
			return (0);
		i++;
	}
	return (1);
}

uint16_t	msk_grp(uint8_t pos, uint8_t width)
{
	uint16_t	mask;

	if (width == 0)
		return (0);
	mask = 1;
	while (--width)
	{
		mask <<= 1;
		mask |= 1;
	}
	mask <<= pos;
	return (mask);
}
