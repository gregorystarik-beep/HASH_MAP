#include "Hash_map.h"
#include "linked_list.h"
int cmp_func(void* key1, void* key2)//gets pointers to veriable
{
	int* real1=(int*)key1;
	int* real2=(int*)key2;//converts to pointer intger
	if (*real1 == *real2)return 1;//return true if they are equal
	return 0;
}
Hashtable* create_hash(int size, int (*hash_func)(void*), int (cmp_func)(void*, void*))//creates the hash map
{
	Hashtable* Hash = (Hashtable*)malloc(sizeof(Hashtable));//allocates the table
	if (Hash == NULL)return NULL;
	Hash->size = size;//saves the size of every array in the hash
	Hash->arr = (Node**)calloc(size, sizeof(Node*));//allocates memorey for the array with null pointer because it is a limked list
	if (Hash->arr == NULL)
	{
		free(Hash);
		Hash = NULL;
		return NULL;
	}
	return Hash;
}
