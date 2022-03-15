/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halwahed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:17:04 by halwahed          #+#    #+#             */
/*   Updated: 2021/11/29 11:51:16 by halwahed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must be
ended by a NULL pointer.*/

static int	ft_word_count(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		count++;
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
	}
	return (count);
}

static int	ft_word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static char	*ft_strndup(char const *s, int len)
{
	char	*result;
	int		i;

	i = 0;
	result = (char *)malloc(sizeof (char) * (len + 1));
	while (i < len)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

static void	ft_free(char **s, int i)
{
	if (s == NULL)
	{
		while (i-- != 0)
			free(s[i]);
		free(s);
		return ;
	}
}

char	**ft_split(char const *s, char c)
{
	int		word_len;
	int		word_count;
	char	**result;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	word_count = ft_word_count(s, c);
	result = (char **)malloc(sizeof (char *) * (word_count + 1));
	if (result == NULL)
		return (0);
	while (i < word_count)
	{
		while (*s && *s == c)
			s++;
		word_len = ft_word_len(s, c);
		result[i] = ft_strndup(s, word_len);
		ft_free(result, i - 1);
		s = s + word_len;
		i++;
	}
	result[word_count] = 0;
	return (result);
}
