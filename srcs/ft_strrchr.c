/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:55:33 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/10/21 23:28:30 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*lc;
	
	lc = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
            lc = s;
        s++;
    }
	if (c == '\0')
		return (char *)s;
    return (char *)lc;
}
