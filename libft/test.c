/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:37:44 by jahlee            #+#    #+#             */
/*   Updated: 2022/11/14 11:11:37 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_memcmp(const void *b1, const void *b2, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)b1;
	s2 = (unsigned char *)b2;
	i = 0;
	while (n--)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

char    *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	haystack_len;
	size_t	i;

	if (*needle == '\0')
		return ((char *)haystack);
	needle_len = strlen(needle);
	haystack_len = strlen(haystack);
	if (haystack_len < needle_len || len < needle_len)
		return (0);
	i = 0;
	while (*haystack && (i < len))
	{
		if (!ft_memcmp(haystack, needle, needle_len))
			return ((char *)haystack);
		haystack++;
        i++;
	}
	return (0);
}


int	main()
{
	char	str1[100] = "123456789";
	char	str2[100] = "7";

	printf("ft     : %s\n",ft_strnstr(str1,str2,7));
	// printf("origin : %d\n",strnstr(str1,str2,10));

}