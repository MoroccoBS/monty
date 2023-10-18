#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: double pointer to the first node
 * @line_number: line number of the operation
 * Return: void
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *operation = strtok(NULL, " \t\n");
	int value;
	stack_t *new_node;

	if (operation == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = parse_value(operation, line_number);
	new_node = create_new_node(value);
	update_stack(stack, new_node);
}

/**
 * pall - prints all values on the stack from the top
 * @stack: double pointer to the first node
 * @line_number: line number of the operation
 * Return: void
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)(line_number);

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint - prints the value at the top of the stack
 * @stack: double pointer to the first node
 * @line_number: line number of the operation
 * Return: void
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint if stack is empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes top element of stack
 * @stack: double pointer to the first node
 * @line_number: line number of the operation
 * Return: void
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop if stack is empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;

	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}

	free(temp);
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: double pointer to the first node
 * @line_number: line number of the operation
 * Return: void
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int temp = (*stack)->n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap stack has less than 2 elements\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
