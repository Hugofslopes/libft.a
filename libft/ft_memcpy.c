/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:08:32 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/10/27 20:09:23 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	char			*d;
	char			*s;

	d = (char *)dst;
	s = (char *)src;
	i = 0;
	while (i++ < n)
		*d++ = *s++;
	return (dst);
}
