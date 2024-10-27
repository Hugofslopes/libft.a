/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 09:33:41 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/10/27 20:03:36 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_bytes;

	if (nmemb == 0 || size == 0)
		total_bytes = 1;
	total_bytes = nmemb * size;
	if (total_bytes / size != nmemb)
		return (NULL);
	ptr = malloc(total_bytes);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, total_bytes);
	return (ptr);
}
