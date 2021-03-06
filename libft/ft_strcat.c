/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelfa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:44:38 by oabdelfa          #+#    #+#             */
/*   Updated: 2021/11/11 16:37:59 by oabdelfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int		i;
	size_t	st;

	st = ft_strlen(s1);
	i = 0;
	while (s2[i])
	{
		s1[st] = s2[i];
		st++;
		i++;
	}
	s1[st] = '\0';
	return (s1);
}
