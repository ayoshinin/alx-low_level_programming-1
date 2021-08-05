#include "lists.h"

/**
 * insert_nodeint_at_index - a function that inserts a new node at
 *                           a given position
 *
 * @head: pointer to the first node of the list
 * @idx: is the index of the list where the new node should be added
 * @n: element to add to the new node
 *
 * Return: NULL if anything fails or the address of the new node
*/
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *current;
	unsigned int index;

	new_node = malloc(sizeof(listint_t));
	if ((*head == NULL && idx != 0) || new_node == NULL)
		return (NULL);

	new_node->n = n; /* add our element to the new node*/

	if (idx == 0) /*if the index for new node is 0*/
	{
		/*first node will be moved to second node*/
		new_node->next = *head;
		/*new node will be placed as the first node*/
		*head = new_node;
		return (new_node);
	}

	if (idx != 0) /*if index where to add our new node is not 0*/
	{
		current = *head; /*place first node at current*/

		/*iterate list to node position idx - 2*/
		for (index = 0; index < idx - 1; index++)
			current = current->next;

		if (current == NULL)
			return (NULL);

		new_node->next = current->next; /*place current node after new node*/
		current->next = new_node;/*set the new node at index idx*/
		return (new_node);
	}

	return (NULL);
}