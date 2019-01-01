/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 13:27:27 by scao              #+#    #+#             */
/*   Updated: 2018/12/09 13:28:16 by scao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_istrimspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	unsigned int	len;
	unsigned int	beg;
	unsigned int	end;
	char			*str;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	beg = 0;
	end = 0;
	str = (char *)s;
	while (ft_istrimspace(*str++))
		beg++;
	while (*str)
		str++;
	while (ft_istrimspace(*--str))
		end++;
	str = ft_strsub(s, beg, len - beg - end);
	return (str);
}
