/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:16:40 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/10/18 18:44:57 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, char *src, int nb)
{
	char	*p;

	p = dest;
	while (*p)
		p++;
	while (nb-- > 0 && *src)
		*p++ = *src++;
	*p = 0;
	return (dest);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	size;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	size = dstsize - dstlen - 1;
	if (dstsize <= dstlen)
		return (srclen + dstsize);
	ft_strncat(dst, (char *)src, size);
	return (dstlen + srclen);
}
