#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "Hash_map.h"
int main()
{
	Hashtable* my_map = NULL;
	int i;
	int arr[] = { 6,8,9,10,12,17,15,19,25,30,45,70 };
	my_map = create_hash(5, hash_func, cmp_func, print_func);
	for (i = 0; i < 12; i++)
	{
		insert_hash(my_map, &arr[i]);
	}
	printf("before rermovel\n");
	print_hash(my_map);
	remove_hash(my_map, &(int){3});
	printf("after\n");
	print_hash(my_map);
	free_hash(my_map);
	my_map = NULL;
	return 0;
}
