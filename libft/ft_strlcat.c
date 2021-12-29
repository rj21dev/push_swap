/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:47:09 by rjada             #+#    #+#             */
/*   Updated: 2021/10/10 19:11:10 by rjada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dlen;

	dlen = ft_strlen(dst);
	i = dlen;
	j = 0;
	if (dlen < dstsize - 1 && dstsize > 0)
	{
		while (src[j] && dlen + j < dstsize - 1)
		{
			dst[i] = src[j];
			++i;
			++j;
		}
		dst[i] = 0;
	}
	if (dlen >= dstsize)
		dlen = dstsize;
	return (dlen + ft_strlen(src));
}
