/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halwahed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:20:37 by halwahed          #+#    #+#             */
/*   Updated: 2021/11/29 11:50:51 by halwahed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Allocates (with malloc(3)) and returns a copy of
’s1’ with the characters specified in ’set’ removed
from the beginning and the end of the string.*/
char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	char	*str;

	if (s1 == NULL)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1) != 0)
		s1++;
	len = ft_strlen(s1);
	while (len > 0 && *s1 && ft_strchr(set, s1[len - 1]) != 0)
		len--;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (0);
	ft_memcpy(str, s1, len);
	str[len] = '\0';
	return (str);
}
