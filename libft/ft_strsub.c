/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzagura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 18:13:20 by gzagura           #+#    #+#             */
/*   Updated: 2017/12/12 18:13:23 by gzagura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	char	*sub_str;

	if (s == NULL)
		return (0);
	sub_str = ft_strnew(len - start);
	if (sub_str == NULL)
		return (0);
	j = 0;
	while (s[start] != '\0' && start < len)
	{
		sub_str[j] = (char)s[start];
		start++;
		j++;
	}
	return (sub_str);
}
