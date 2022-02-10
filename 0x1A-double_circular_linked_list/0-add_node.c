#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/**
 * _strlen - My implementation of strlen, gets length
 *
 * @str: The string to find length of
 *
 * Return: Length of string
 */
int _strlen(char *str)
{
	int i = 0;

	while (*(str + i))
		i++;
	return (i);
}

/**
 * _strdup - My implementation of strdup, duplicates string
 *
 * @str: The string to duplicate
 *
 * Return: string duplicated
 */
char *_strdup(char *str)
{
	int i, length;
	char *dup;

	length = _strlen(str);
	dup = malloc(sizeof(char) * length + 1);
	if (dup == NULL)
		return (NULL);
	for (i = 0; i < length; i++)
		dup[i] = str[i];
	dup[i] = '\0';
	return (dup);
}

/**
 * add_node_end - Adds node to end of doubly linked circular list
 *
 * @list: A pointer to the head of the linkd list
 * @str: The string to copy into the new node
 *
 * Return: Node added to end of list, or NULL on fail
 */
List *add_node_end(List **list, char *str)
{
	List *current, *new;

	new = malloc(sizeof(list));
	if (new == NULL)
		return (NULL);

	new->str = _strdup(str);
	if (new->str == NULL)
		return (NULL);

	current = *list;

	if (current == NULL)
	{
		*list = new;
		new->next = new;
		new->prev = new;
		return (new);
	}

	new->next = current;
	new->prev = current->prev;
	new->prev->next = new;
	current->prev = new;

	return (new);
}

/**
 * add_node_begin - Adds node to beginning of doubly linked circular list
 *
 * @list: A pointer to the head of the linkd list
 * @str: The string to copy into the new node
 *
 * Return: Node added to beginning of list, or NULL on fail
 */
List *add_node_begin(List **list, char *str)
{
	List *current, *new;

	new = malloc(sizeof(list));
	if (new == NULL)
		return (NULL);

	new->str = _strdup(str);
	if (new->str == NULL)
		return (NULL);

	current = *list;
	if (current == NULL)
	{
		*list = new;
		new->next = new;
		new->prev = new;
		return (new);
	}


	new->next = current;
	new->prev = current->prev;
	current->prev = new;
	new->prev->next = new;
	*list = new;

	return (new);
}
