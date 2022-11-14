/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:37:44 by jahlee            #+#    #+#             */
/*   Updated: 2022/11/14 18:58:57 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	cnt;

	cnt = 0;
	while (s[cnt])
		cnt++;
	return (cnt);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (i + 1 < dstsize && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}
char *ft_strdup(const char *s)
{
    size_t  size;
    char *  mem;

    size = ft_strlen(s);
    if (!(mem = malloc(sizeof(char) * (size + 1))))
        return (NULL);
	ft_strlcpy(mem, s, size + 1);
    return (mem);
}


int	main()
{
	char	str1[100] = "0123456789111111";
	char	str2[100] = "0123";

	printf("ft     : %s\n",ft_strdup(str1));
	printf("origin : %s\n",strdup(str1));

}