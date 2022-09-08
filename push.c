#include "monty.h"

void m_push(stack_t **top, unsigned int number);


/**
 * m_push - Pushes a value to a stack_t linked list.
 * @top: A pointer to the top mode node of a stack_t linked list.
 * @number: The current working line number of a Monty bytecodes file.
 */
void m_push(stack_t **top, unsigned int number)
{
	stack_t *tmp, *new;
	int i;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		set_op_tok_error(malloc_error());
		return;
	}

	if (op_toks[1] == NULL)
	{
		set_op_tok_error(no_int_error(line_number));
		return;
	}

	for (i = 0; op_toks[1][i]; i++)
	{
		if (op_toks[1][i] == '-' && i == 0)
			continue;
		if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
		{
			set_op_tok_error(no_int_error(line_number));
			return;
		}
	}
	new->n = atoi(op_toks[1]);

	if (check_mode(*top) == STACK) /* STACK mode insert at front */
	{
		tmp = (*top)->next;
		new->prev = *top;
		new->next = tmp;
		if (tmp)
			tmp->prev = new;
		(*top)->next = new;
	}
	else /* QUEUE mode insert at end */
	{
		tmp = *top;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		new->next = NULL;
		tmp->next = new;
	}
}
