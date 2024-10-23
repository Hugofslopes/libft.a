/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:43:08 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/10/23 11:02:45 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char		*h;
	const char	*n;
	size_t		i;

	if (!haystack || !needle)
		return (NULL);
	if (!needle[0])
		return ((char *)haystack);
	while (*haystack && len > 0)
	{
		n = needle;
		h = (char *)haystack;
		if (*haystack == *n)
		{
			i = 0;
			while (n[i] && haystack[i] == n[i] && (i < len))
				i++;
			if (!n[i])
				return (h);
		}
		haystack++;
		len--;
	}
	return (NULL);
}
