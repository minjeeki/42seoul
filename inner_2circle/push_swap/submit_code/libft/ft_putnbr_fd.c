/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:32:19 by minjeeki          #+#    #+#             */
/*   Updated: 2023/10/28 20:47:19 by minjeeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_division_n(long long n)
{
	int	cnt;
	int	res;

	cnt = 0;
	if (n < 0)
		n *= -1;
	while (n >= 10)
	{
		cnt++;
		n /= 10;
	}
	res = 1;
	while (cnt > 0)
	{
		res *= 10;
		cnt--;
	}
	return (res);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	plus_n;
	int			division_n;
	char		print_char;

	if (n < 0)
	{
		write(fd, "-", 1);
		plus_n = (long long)n * -1;
	}
	else
		plus_n = (long long)n;
	division_n = ft_division_n(n);
	while (division_n >= 1)
	{
		print_char = (plus_n / division_n) + '0';
		ft_putchar_fd(print_char, fd);
		plus_n %= division_n;
		division_n /= 10;
	}
}
