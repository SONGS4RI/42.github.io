/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:37:44 by jahlee            #+#    #+#             */
/*   Updated: 2022/11/13 18:52:02 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;
	char	find;
	int		i;

	last = (char *)s;
	find = (char)c;
	i = strlen(s);
	while (i >= 0)
	{
		if (last[i] == find)
			return (last + i);
		i--;
	}
	return (0);
}

int	main()
{
	char	str1[100] = "abcdebcd";
	char	str2[4] = "123";

	printf("ft : %s\n",ft_strrchr(str1,'a'));
	printf("origin : %s\n",strrchr(str1,'a'));

}