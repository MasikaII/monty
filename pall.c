#include "monty.h"

void m_pall(stack_t **top, unsigned int number);


/**
 * m_pall - Prints the values of a stack_t linked list.
 * @top: A pointer to the top mode node of a stack_t linked list.
 * @number: The current working line number of a Monty bytecodes file.
 */
void m_pall(stack_t **top, unsigned int number)
{
	stack_t *tmp = (*top)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)number;
}
