#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
	void* data;
	struct Node* next;
}Node;
void Create_Node(Node** head, void* x);
void free_list(Node** head);
Node* find_node(Node* head, int target);