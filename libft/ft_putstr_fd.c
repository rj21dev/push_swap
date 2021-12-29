/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:18:47 by rjada             #+#    #+#             */
/*   Updated: 2021/10/10 19:09:40 by rjada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	printed;

	printed = 0;
	if (!s)
		return (printed);
	while (*s)
		printed += write(fd, s++, sizeof(char));
	return (printed);
}
