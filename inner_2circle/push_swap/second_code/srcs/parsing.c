/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 11:15:21 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/28 20:31:41 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_str_elem(char *str);
int	ft_count_total_elem(int argc, char *argv[]);
int	ft_convert_to_int(char *argv[], int *origin_arr);

int	ft_parsing(int argc, char *argv[], int **origin_arr)
{
	int	size_arr;

	size_arr = ft_count_total_elem(argc, argv);
	if (size_arr <= 0)
		return (-1);
	*origin_arr = (int *)malloc(size_arr * sizeof(int));
	if (*origin_arr == NULL)
		return (-1);
	if (ft_convert_to_int(argv, *origin_arr) == 1)
	{
		free(*origin_arr);
		return (-1);
	}
	return (size_arr);
}

int	ft_count_str_elem(char *str)
{
	int	idx;
	int	is_char;
	int	count;

	idx = 0;
	is_char = 0;
	if (str[idx] != ' ' && str[idx] != '\0')
		is_char = 1;
	count = 0;
	while (str[idx] != '\0')
	{
		if (is_char == 0 && str[idx] != ' ')
			is_char = 1;
		else if (is_char == 1 && str[idx] == ' ')
		{
			is_char = 0;
			count++;
		}
		idx++;
	}
	if (is_char == 1)
		count++;
	return (count);
}

int	ft_count_total_elem(int argc, char *argv[])
{
	int	idx;
	int	cnt_total;
	int	cnt_arg;

	idx = 1;
	cnt_total = 0;
	if (argc < 2)
		return (-1);
	while (argv[idx] != NULL)
	{
		cnt_arg = ft_count_str_elem(argv[idx]);
		cnt_total += cnt_arg;
		idx++;
	}
	return (cnt_total);
}

int	ft_convert_to_int(char *argv[], int *origin_arr)
{
	int		idx_argv;
	char	**arr_str;
	int		idx_str;
	int		idx_int;

	idx_argv = 1;
	idx_int = 0;
	while (argv[idx_argv] != NULL)
	{
		arr_str = ft_split(argv[idx_argv], ' ');
		if (arr_str == NULL)
			return (1);
		idx_str = 0;
		while (arr_str[idx_str] != NULL)
		{
			if (ft_safe_atoi(arr_str[idx_str], origin_arr, idx_int) == 1)
				return (ft_free_str_arr(arr_str));
			else
				idx_int++;
			idx_str++;
		}
		ft_free_str_arr(arr_str);
		idx_argv++;
	}
	return (0);
}
