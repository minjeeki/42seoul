/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 03:08:31 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/30 10:30:30 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_abs(int n)
{
	if (n < 0)
		return ((long long)n * -1);
	else
		return ((long long)n);
}

int	ft_digit_n(long long n)
{
	int	cnt;

	cnt = 1;
	if (n < 0)
	{
		n *= -1;
		cnt++;
	}
	while (n >= 10)
	{
		cnt++;
		n /= 10;
	}
	return (cnt);
}

char	*ft_itoa(int n)
{
	long long	abs_n;
	int			digit_n;
	char		*res;
	int			idx;

	abs_n = ft_abs(n);
	digit_n = ft_digit_n(n);
	res = (char *)malloc(digit_n + 1);
	idx = 0;
	if (!res)
		return (0);
	res[digit_n] = 0;
	digit_n--;
	if (abs_n != n)
	{
		res[idx] = '-';
		idx++;
	}
	while (digit_n >= idx)
	{
		res[digit_n] = '0' + abs_n % 10;
		abs_n /= 10;
		digit_n--;
	}
	return (res);
}
