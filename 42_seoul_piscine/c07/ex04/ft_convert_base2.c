/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 10:15:30 by jahlee            #+#    #+#             */
/*   Updated: 2022/09/10 18:22:22 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen1(char *str)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		str++;
		cnt++;
	}
	return (cnt);
}

int	check1(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen1(str) <= 1)
		return (0);
	while (str[i])
	{
		j = i + 1;
		if (str[i] == '+' || str[i] == '-')
			return (0);
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
			return (0);
		while (str[j])
		{
			if (str[j] == str[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	*is_white(char *s, int *minus)
{
	while ((*s >= 9 && *s <= 13) || *s == ' ')
		s++;
	while (*s == '-' || *s == '+')
	{
		if (*s == '-')
			*minus *= -1;
		s++;
	}
	return (s);
}

void	func(char *s, char *base, int *res)
{
	int	minus;
	int	i;
	int	base_len;

	base_len = ft_strlen1(base);
	minus = 1;
	s = is_white(s, &minus);
	while (*s)
	{
		i = -1;
		while (++i <= base_len)
		{
			if (base[i] == '\0')
				return ;
			if (*s == base[i])
			{
				*res = (*res) * base_len + minus * i;
				break ;
			}
		}
		s++;
	}
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_len;
	int	res;

	res = 0;
	base_len = ft_strlen1(base);
	if (check1(base))
	{
		func(str, base, &res);
		return (res);
	}
	else
		return (0);
}
