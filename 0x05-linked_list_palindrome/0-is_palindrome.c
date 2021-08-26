#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - checks if linked list is a palindrome.
 * @head: head of linked list
 * Return: 1 if palindrome else 0
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow;
	listint_t *fast;

	slow = *head;
	fast = *head;

	int *storage;
	int index = 0;

	storage = malloc(sizeof(int) * 500);

	while (slow != NULL)
	{
		if (fast == NULL)
		{
			index--;
			if (storage[index] != slow->n)
				return (0);
		}
		else if (fast->next == NULL)
		{
			slow = slow->next;
			fast = fast->next;
			index--;
		}
		else
		{
			storage[index] = slow->n;
			index++;
			fast = fast->next->next;
		}
		slow = slow->next;
	}
	free(storage);
	return (1);
}
