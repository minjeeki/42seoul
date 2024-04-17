#include "push_swap.h"

int ft_free_arr(int *arr)
{
    free(arr);
    return (1);
}

int ft_free_stack(t_deque *stack, int *arr)
{
    if (arr != NULL)
        free(arr);
    free(stack);
    return (1);
}

int ft_print_error()
{
    write(1, "Error\n", 7);
    return (1);
}