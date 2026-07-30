#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
	int data;
	struct Node* next;
}Node;
void Create_Node(Node** head, int x);
void free_list(Node** head);
Node* find_node(Node* head, int target);