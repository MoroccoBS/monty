#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: double pointer to the first node
 * @line_number: line number of the operation
 * Return: void
 */

void push(stack_t **stack, unsigned int line_number)
{
	/*char *operation = strtok(NULL, " \t\n");
	int value;
	stack_t *new_node;

	if (operation == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = parse_value(operation, line_number);
	new_node = create_new_node(value);
	update_stack(stack, new_node);*/
	stack_t *new_node = malloc(sizeof(stack_t));
	char *operation;
	int value;

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	operation = strtok(NULL, " \t\n");
	if (operation == NULL || stack == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* value = parse_value(operation, line_number);*/
	value = atoi(operation);
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (new_node->next != NULL)
		new_node->next->prev = new_node;
	*stack = new_node;
}

/**
 * pall - prints all values on the stack from the top
 * @stack: double pointer to the first node
 * @line_number: line number of the operation
 * Return: void
 */

void pall(stack_t **stack, unsigned int line_number)
{
	/** (void)(stack);
	printf("%d\n", line_number);
	stack_t *current = *stack;

	(void)(line_number);

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
	*/
	/*stack_t *tmp;

	(void)line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}*/
	stack_t *element = *stack;

	(void)(line_number);
	while (element != NULL)
	{
		printf("%d\n", element->n);
		element = element->next;
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
		fprintf(
			stderr, "L%u: can't swap stack has less than 2 elements\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
