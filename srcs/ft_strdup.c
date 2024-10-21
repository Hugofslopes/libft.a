/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:33:57 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/10/21 12:56:03 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*new_string;
	int		i;

	i = 0;
	new_string = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (new_string == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		new_string[i] = src[i];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
