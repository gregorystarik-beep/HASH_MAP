#pragma once
#include "linked_list.h"
typedef struct Hashtable
{
	int size;
	Node** arr;
	int (*hash_func)(void* key);
	int (*cmp_func)(void* key1, void* key2);
}Hashtable;
Hashtable* create_hash(int size, int (*h_func)(void*), int (*c_func)(void*, void*));
int cmp_func(void* key1, void* key2);
int *hash_func(void* key);