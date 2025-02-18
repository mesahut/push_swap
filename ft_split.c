/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayilmaz <mayilmaz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:45:06 by mayilmaz          #+#    #+#             */
/*   Updated: 2025/02/18 03:14:51 by mayilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_split(char **f, int k)
{
	while (k >= 0)
	{
		free(f[k]);
		k--;
	}
	free(f);
}

static int	word_count(const char *s, char c)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (s[a] != '\0')
	{
		while (s[a] == c && s[a] != '\0')
			a++;
		if (s[a] != c && s[a] != '\0')
			b++;
		while (s[a] != c && s[a] != '\0')
			a++;
	}
	return (b);
}

static int	word_len(const char *s, char c)
{
	int	a;

	a = 0;
	while (s[a] && s[a] != c)
		a++;
	return (a);
}

static int	word_save(char **f, char const *s, char c, int i)
{
	int	b;
	int	k;

	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			b = word_len(&s[i], c);
			f[k] = (char *)malloc(sizeof(char) * (b + 1));
			if (!f[k])
			{
				free_split(f, k);
				return (1);
			}
			b = 0;
			while (s[i] && s[i] != c)
				f[k][b++] = s[i++];
			f[k++][b] = '\0';
		}
		else
			i++;
	}
	f[k] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**f;
	int		i;
	int		word;

	i = 0;
	word = word_count(s, c);
	if (!s || s[i] == '\0' || word == 0)
		return (NULL);
	f = (char **)malloc(sizeof(char *) * (word + 1));
	if (!f)
		return (NULL);
	word_save(f, s, c, i);
	return (f);
}
