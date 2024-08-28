/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 10:44:06 by marlonco          #+#    #+#             */
/*   Updated: 2024/08/28 16:34:07 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **array, int k)
{
	int	i;

	i = 0;
	while (i < k)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static int	ft_count(char const *s, char c)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			k++;
		i++;
	}
	return (k);
}

static char	**ft_array_malloc(char const *s, char c, t_split st)
{
	st.str = malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!st.str)
		return (0);
	while (s[st.i])
	{
		if (s[st.i] != c && s[st.i] != '\0')
		{
			st.j = 0;
			while (s[st.i + st.j] != c && s[st.i + st.j] != '\0')
				st.j++;
			st.str[st.k] = malloc(sizeof(char) * (st.j + 1));
			if (st.str[st.k] == NULL)
			{
				ft_free(st.str, st.k);
				return (NULL);
			}
			st.k++;
			st.i += st.j - 1;
		}
		st.i++;
	}
	st.str[st.k] = NULL;
	return (st.str);
}

static void	ft_fill_array_str(char const *s, char c, char **array)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] != c && s[i] != '\0')
		{
			j = 0;
			while (s[i + j] != c && s[i + j] != '\0')
			{
				array[k][j] = s[i + j];
				j++;
			}
			array[k][j] = '\0';
			i += j - 1;
			k++;
		}
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	t_split	st;

	if (s == NULL)
		return (NULL);
	st.i = 0;
	st.j = 0;
	st.k = 0;
	array = ft_array_malloc(s, c, st);
	if (array == NULL)
		return (NULL);
	ft_fill_array_str(s, c, array);
	return (array);
}

// static void	ft_free(char **word)
// {
// 	int	i;

// 	i = 0;
// 	while (word[i] != NULL)
// 	{
// 		free(word[i]);
// 		i++;
// 	}
// }

// static int	ft_wordcount(char const *s, char c)
// {
// 	int	i;
// 	int	wordcount;

// 	i = 0;
// 	wordcount = 0;
// 	while (s[i])
// 	{
// 		while (s[i] && s[i] == c)
// 			i++;
// 		if (s[i] != c && s[i])
// 			wordcount++;
// 		while (s[i] && s[i] != c)
// 			i++;
// 	}
// 	return (wordcount);
// }

// static int	ft_wordlen(char const *str, char c)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i] && str[i] != c)
// 		i++;
// 	return (i);
// }

// static char	*ft_fill_words(char const *str, char c)
// {
// 	int		i;
// 	int		len;
// 	char	*word;

// 	i = 0;
// 	len = ft_wordlen(str, c);
// 	word = malloc((len + 1) * sizeof(char));
// 	if (word == NULL)
// 		return (ft_free(&word), NULL);
// 	while (i < len)
// 	{
// 		word[i] = str[i];
// 		i++;
// 	}
// 	word[i] = '\0';
// 	return (word);
// }

// char	**ft_split(char const *s, char c)
// {
// 	int		i;
// 	int		j;
// 	char	**array;

// 	i = 0;
// 	j = 0;
// 	array = malloc((ft_wordcount(s, c) + 1) * sizeof(char *));
// 	if (array == NULL)
// 		return (NULL);
// 	while (s[i])
// 	{
// 		while (s[i] && s[i] == c)
// 			i++;
// 		if (s[i] != c)
// 		{
// 			array[j] = ft_fill_words(&s[i], c);
// 			if (array[j] == NULL)
// 				free(array);
// 			j++;
// 		}
// 		while (s[i] && s[i] != c)
// 			i++;
// 	}
// 	array[ft_wordcount(s, c)] = NULL;
// 	return (array);
// }

// int	main(void)
// {
// 	int		i;
// 	char	**array;
// 	char	str[] = "\t\t\t\t\thello!\t\t\t\t\t\t\t";
// 	char	c;

// 	i = 0;
// 	c = '\t';
// 	array = ft_split(str, c);
// 	while (i < 2)
// 	{
// 		printf("%s\n", array[i]);
// 		i++;
// 	}
// 	return (0);
// }
