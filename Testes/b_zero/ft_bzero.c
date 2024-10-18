/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:55:24 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/10/17 14:12:32 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <libft.h>
#include <stdio.h>

void ft_bzero(void *ptr, size_t n)
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = (char *)ptr;
	while (i < n)
		str[i++] = '0'; //changed from '\0' to test
	str[i] = '\0';
printf("%s", str);
}