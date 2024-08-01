#include "monty.h"

void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

int is_number(char *str)
{
	if (!str || *str == '\0')
	{
		return (0);
	}

	if (*str == '-' || *str == '+')
	{
		str++;
	}

	while (*str)
	{
		if (!isdigit(*str))
		{
			return (0);
		}
		str++;
	}

	return (1);
}
