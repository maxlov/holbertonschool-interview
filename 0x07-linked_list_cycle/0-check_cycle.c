#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * check_cycle - checks if linked list is a palindrome.
 * @list: head of list
 * Return: 1 if cycle else 0
 */
int check_cycle(listint_t *list)
{
	listint_t *slow;
	listint_t *fast;

	slow = list;
	fast = list;

	while (slow && fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;

		if (fast == slow)
			return (1);
	}
	return (0);
}
