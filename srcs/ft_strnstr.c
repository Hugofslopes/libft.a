/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:43:08 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/10/21 23:22:18 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char		*h;
    const char	*n;

    if (!haystack || !needle)
		return NULL;
    if (!needle[0])
		return (char *)haystack;
    while (*haystack && len > 0)
	{
		n = needle;
		h = (char *)haystack;
        if (*haystack == *n) 
		{
            size_t i = 0;
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
