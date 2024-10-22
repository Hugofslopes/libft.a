/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:25:49 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/10/22 16:09:07 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

int	safe_malloc (char ** new_string, int position, size_t size)
{
	int	i;

	i = 0;
	new_string[position] = malloc(size * sizeof(char));
	if (!new_string[position])
	{
		while (i < position)
		{	free(new_string[i]);
			i++;
		}
		free(new_string);
		return (1);
	}
	return (0);
}

int fill_string(char ** new_string, char const *s, char delimeter)
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
			if (safe_malloc(new_string, i , len + 1))
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
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**new_string;
	size_t	nr_words;

	if (!s)
		return (NULL);
	nr_words = count_words(s, c);
	new_string = malloc((nr_words + 1) * sizeof(char *));
	if (!new_string)
		return (NULL);
	if (fill_string(new_string, s, c))
	{	free(new_string);
		return (NULL);
	}
	return (new_string);
}
