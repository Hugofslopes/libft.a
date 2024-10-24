/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:43:08 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/10/24 10:44:43 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char		*h;
	const char	*n;
	size_t		i;

	if (!big || !little)
		return (NULL);
	if (!little[0])
		return ((char *)big);
	while (*big && len > 0)
	{
		n = little;
		h = (char *)big;
		if (*big == *n)
		{
			i = 0;
			while (n[i] && big[i] == n[i] && (i < len))
				i++;
			if (!n[i])
				return (h);
		}
		big++;
		len--;
	}
	return (NULL);
}
