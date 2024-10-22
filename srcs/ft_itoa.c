/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:14:29 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/10/22 17:52:25 by hfilipe-         ###   ########.fr       */
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
		nb = nb / 10;
		len++;
	}
	return (len);
}

char *n_negative(long j)
{
	char *str;
	int		i;

	j *=  -1;
	i = nbnbs(j);
	str = (char *)malloc((i + 2) * sizeof(char));
	if(!str)
		return (NULL);
	str[i] = '\0';
	while (j > 0)
	{
		str[--i] = '0' + (j % 10);
		j /= 10;
	}
	str[0] = '-';
	return (str);
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
	int		i;
	long	j;
	char	*str;	 

	j = n;
	if (n < 0)
		str = n_negative(j);
	else if (n == 0)
		str = n_zero();
	else
	{
		i = nbnbs(j) + 1;
		str = (char *)malloc(i * sizeof(char));
		if(!str)
			return (NULL);
		str[i--] = '\0';
		while (j > 0)
		{
			str[i--] = '0' + (j % 10);
			j /= 10;
		}
	}
	return (str);
}

// int main()
// {
// 	printf("%s", ft_itoa(1034));
// }
