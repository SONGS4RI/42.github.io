/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 17:45:45 by user              #+#    #+#             */
/*   Updated: 2022/09/04 22:03:25 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_atoi(char *str)
{
    int num;
    int minus;

    num =0;
    minus = 1;
    while(!(*str >= '1' && *str <= '9'))
    {
        if(*str == '-')
            minus = -1;
        str++;
    }
    while(*str && *str >= '1' && *str <= '9')
    {
        num = num*10 + minus*(*str - '0');
        str++;
    }
    
    return num;
}
