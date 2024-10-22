/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:14:29 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/10/22 19:41:21 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <stdlib.h>

static	int	nbnbs(long nb)
{
	int	len;

	len = 0;
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char *n_zero(void){
	char * str;

	str = (char *)malloc(2 * sizeof(char));
	if(!str)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	size_t		i;
	long int	j;
	char		*str;	 

	if (n == 0)
		return (str = n_zero());
	j = n;
	i = nbnbs(n);
	if (n < 0)
	{
		j *= -1;
		i++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	*(str + i) = 0;
	while (i--)
	{
		*(str + i) = j % 10 + '0';
		j /= 10;
	}
	if (n < 0)
		*(str + 0) = '-';
	return (str);
}