/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:32:01 by rjada             #+#    #+#             */
/*   Updated: 2021/11/30 18:45:20 by rjada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*area;
	size_t	i;
	size_t	total;
	size_t	size_max;

	size_max = (size_t) - 1;
	if (size && count > size_max / size)
		return (NULL);
	total = count * size;
	area = malloc(total);
	if (!area)
		return (NULL);
	i = 0;
	while (i < total)
		((unsigned char *)area)[i++] = 0;
	return (area);
}
