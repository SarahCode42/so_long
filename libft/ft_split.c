/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <jbensimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:47:43 by jbensimo          #+#    #+#             */
/*   Updated: 2025/02/18 21:14:49 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((i == 0 || s[i - 1] == c) && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

static char	*get_next_word(char const **s, char c)
{
	char	*word;
	size_t	i;

	i = 0;
	while (**s == c)
		(*s)++;
	while ((*s)[i] && (*s)[i] != c)
		i++;
	word = ft_substr(*s, 0, i);
	(*s) += i;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char		**result;
	size_t		i;
	size_t		words_count;

	if (!s)
		return (NULL);
	i = 0;
	words_count = count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (words_count + 1));
	if (!result)
		return (NULL);
	while (i < words_count)
	{
		result[i] = get_next_word(&s, c);
		if (!result[i])
		{
			while (i > 0)
				free(result[--i]);
			free (result);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}
/*
int	main(void)
{
	char **result = ft_split("----Hello tous le-monde---", '-');
	int i = 0;

	while (result && result[i]) // Parcours et impression des sous-chaînes
	{
		printf("Sous-chaîne %d : %s\n", i, result[i]);
		free(result[i]); // Libération des sous-chaînes au fur et à mesure
		i++;
	}
	free(result); // Libération du tableau principal
	return 0;
}
*/
