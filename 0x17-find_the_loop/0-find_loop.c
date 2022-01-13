#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * find_listint_loop - Finds a loop in a linked list.
 * @head: Head of linked list.
 * Return: Address of node where loop starts or NULL if no loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow, *fast;

	if (head == NULL || head->next == NULL)
		return (NULL);
	slow = head->next;
	fast = head->next->next;
	while (fast != slow)
	{
		if (fast->next == NULL || fast->next->next == NULL)
			return (NULL);
		fast = fast->next->next;
		slow = slow->next;
	}
	fast = head;
	while (fast != slow)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return (slow);
}
