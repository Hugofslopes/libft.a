/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:07:02 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/10/17 15:15:30 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strlen(char *str);

size_t	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	size_t	srclen;

	srclen = ft_strlen(src);
	while (*src && --size)
		*dest++ = *src++;
	*dest = '\0';
	return (srclen);
}