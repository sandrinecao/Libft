/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:15:04 by scao              #+#    #+#             */
/*   Updated: 2018/12/07 18:18:00 by scao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_len(int n)
{
	int			len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char		*create_str(int len, int n, int neg, char *str)
{
	while (len >= 0)
	{
		str[len] = (n % 10) + 48;
		n /= 10;
		len--;
	}
	if (neg < 0)
		str[0] = '-';
	return (str);
}

char			*ft_itoa(int n)
{
	char		*str;
	int			len;
	int			neg;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = n;
	len = get_len(n);
	str = (char *)malloc(sizeof(*str) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	len--;
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (n < 0)
		n = -n;
	return (create_str(len, n, neg, str));
}
