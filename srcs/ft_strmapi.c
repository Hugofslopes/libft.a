/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:49:08 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/10/22 21:57:21 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{

	char	*str;
	size_t	i;

	i = 0;
	if (!(str = ft_strdup((char *)s)))
		return (NULL);
	while (str[i])
	{
		str[i] = (*f)(i, str[i]);
		i++;
	}
	return (str);
}