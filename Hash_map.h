#pragma once
#include "linked_list.h"
typedef struct Hashtable
{
	int size;
	Node** arr;
	int (*hash_func)(void* key);
	int (*cmp_func)(void* key1, void* key2);
	void (*print_func)(void*key);
}Hashtable;
Hashtable* create_hash(int size, int (*hash_func)(void*), int (*cmp_func)(void*, void*),void(*print_func)(void*key));
int cmp_func(void* key1, void* key2);
int hash_func(void* key);
void *print_func(void* key);
void insert_hash(Hashtable* hash, void* data);
Node* search_hash(Hashtable* hash, void* target);
int remove_hash(Hashtable* hash, void* target);
void print_hash(Hashtable* hash);
void free_hash(Hashtable* hash);
