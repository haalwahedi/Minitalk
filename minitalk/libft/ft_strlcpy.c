/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halwahed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 12:43:08 by halwahed          #+#    #+#             */
/*   Updated: 2021/10/12 13:38:58 by halwahed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	int				srclen;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
			if (i == dstsize)
			{
				i--;
				break ;
			}
		}
		dst[i] = '\0';
	}
	srclen = ft_strlen(src);
	return (srclen);
}
