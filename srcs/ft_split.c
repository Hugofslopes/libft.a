/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:25:49 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/10/23 10:51:36 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

int	safe_malloc (char ***new_string, int position, size_t size, size_t allocated_size)
{
	int	i;

	i = 0;
	if (position < 0 || position >= (int)allocated_size) 
        return (1);
	if (*new_string == NULL)
        return (1);
	(*new_string)[position] = malloc(size * sizeof(char));
	if (!(*new_string)[position])
	{
		while (i < position)
		{	free((*new_string)[i]);
			i++;
		}
		free(*new_string);
		return (1);
	}
	return (0);
}

int fill_string(char ** new_string, char const *s, char delimeter,  size_t allocated_size)
{
	size_t	len;
	int		i;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s == delimeter && *s)
			s++;
		while (*s != delimeter && *s)
		{
			len++;
			s++;
		}
		if (len)
			if (safe_malloc(&new_string, i , len + 1, allocated_size))
				return (1);
		ft_strlcpy(new_string[i], (char *)(s - len), len + 1);
		i++;
	}
	new_string[i] = NULL;
	return (0);
} 

size_t	count_words(char const *s, char delimeter)
{
	size_t	words;
	size_t	in_word;

	words = 0;
	in_word = 0;
	while (*s)
	{
		if(*s == delimeter)
			in_word = 0;
		else
		{
            if (in_word == 0) 
			{
				words++;
				in_word = 1;
			}
		}
	s++;
	}
	if (words == 0 && *s == '\0') 
        words = 1; 
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**new_string;
	size_t	nr_words;
	size_t allocated_size;

	if (!s)
		return (NULL);
	if (c == '\0')
	{
		if (!(new_string = malloc((ft_strlen(s)+ 1) * sizeof(char *))))
			return (NULL);
		new_string[0] = (char *)s + (ft_strlen(s)+ 1);
		return (new_string);
	}
	nr_words = count_words(s, c);
	allocated_size = nr_words + 1;
	if (!(new_string = malloc((nr_words + 1) * sizeof(char *))))
		return (NULL);
	if (fill_string(new_string, s, c, allocated_size))
	{	free(new_string);
		return (NULL);
	}
	return (new_string);
}
