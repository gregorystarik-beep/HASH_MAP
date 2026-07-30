#include "linked_list.h"
void Create_Node(Node** head, int x)//creates nodes for linked list
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	if (new_node == NULL)
	{
		fprintf(stderr, "faill\n");
		return;
	}
	new_node->data = x;
	new_node->next = *head;
	*head = new_node;
}
void free_list(Node** head)//frees linked list node by node
{
	Node* curr = NULL;
	Node* next_node = NULL;
	if (*head == NULL)return;
	curr = *head;
	while (curr != NULL)
	{
		next_node = curr->next;
		free(curr);
		curr = NULL;
		curr = next_node;
	}
	*head = NULL;
}
Node* find_node(Node* head, int target)//searches for a node and returns his adress
{
	Node* curr = head;
	while (curr != NULL)
	{
		if (curr->data == target)
		{
			return curr;
		}
		curr = curr->next;
	}
	return NULL;
}