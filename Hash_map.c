#include "Hash_map.h"
#include "linked_list.h"
int cmp_func(void* key1, void* key2)//gets pointers to veriable
{
	int* real1=(int*)key1;
	int* real2=(int*)key2;//converts to pointer intger
	if (*real1 == *real2)return 1;//return true if they are equal
	return 0;
}
int hash_func(void* key)//turns number into integer to insert into the hash map
{
	int* number = (int*)key;//converts pointer
	return *number;
}
void *print_func(void* key)
{
	int* real = (int*)key;//converts pointer
	printf("[%d]->", *real);//prints
}
Hashtable* create_hash(int size, int (*hash_func)(void*), int (*cmp_func)(void*, void*), void (*print_func)(void* key))//creates the hash map
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
	Hash->cmp_func = cmp_func;//saves the the return value of the hash function and the return value of the cmp function
	Hash->hash_func = hash_func;
	Hash->print_func = print_func;
	return Hash;
}
void insert_hash(Hashtable* hash, void* data)
{
	int num = hash->hash_func(data);//uses the hash function to convert the data to an integer type
	int res = num % hash->size;//uses mod(%)to know where should i insert it 
	Create_Node(&hash->arr[res], data);//and creates a new node in the right index list
}
Node* search_hash(Hashtable* hash, void* target)
{
	Node* curr = NULL;
	int num = hash->hash_func(target);//uses the hash function to convert the data to an integer type
	int res = num % hash->size;//uses mod(%)to know where should i insert it 
	curr = hash->arr[res];//using pointer for the right index locetion of our list in the array 
	while (curr != NULL)
	{
		if (hash->cmp_func(curr->data, target))//calling comp func to return 1(true) if we found the target
		{
			return curr;
		}
		curr = curr->next;
	}
	fprintf(stderr, "could not find a node\n");
	return NULL;
}
int remove_hash(Hashtable* hash, void* target)
{
	Node* curr = NULL;//pointers for current and previus
	Node* prev = NULL;
	Node* temp = NULL;//a temp pointer we use to free data without cousing seg faults
	int num = hash->hash_func(target);//uses the hash function to convert the data to an integer type
	int res = num % hash->size;//uses mod(%)to know where should i insert it 
	if (hash->arr[res] == NULL)return 0;//if the list in the res index is NULL the item does not exist in the list because if he is not in the res index he does not exist in the hash map 
	if (hash->cmp_func(hash->arr[res]->data , target))//if the target is the first item in the list
	{
		temp = hash->arr[res];//we save the data in a temp
		hash->arr[res] = hash->arr[res]->next;//we move foward the list 
		free(temp);//free the temp
		temp = NULL;
		return 1;//we found the item that we wanted to remove so we return 1
	}
	prev = hash->arr[res];
	curr = prev->next;
	while (curr != NULL)//if its not prev which is the first item its the second item so we run with the curr and use the prev to fix the list after we remove the target
	{
		if (hash->cmp_func(curr->data, target))
		{
			temp = curr;//we save the data
			prev->next = curr->next;//we move the next of preve to point where curr->next is pointing(we want to delete curr so we need to keep the list intact) 
			curr = curr->next;//now the item after curr is the new curr so we could delete him
			free(temp);
			temp = NULL;
			return 1;
		}
		prev = prev->next;//move both
		curr = curr->next;//move both so we could search for the target
	}
	return 0;
}
void print_hash(Hashtable* hash)
{
	int i;
	Node* curr = NULL;
	for (i = 0; i < hash->size; ++i)//runs on the linked list array
	{
		curr = hash->arr[i];//the start of a linked list on every array index
		while (curr != NULL)//runs on the list
		{
			hash->print_func(curr->data);//prints
			curr = curr->next;//moves
		}
		printf("\n");//after we finished with the linked list we go one line down and print the next list
	}
}
void free_hash(Hashtable* hash)
{
	int i;
	Node* next = NULL;
	Node* curr = NULL;
	for (i = 0; i < hash->size; ++i)//runs on the linked list array
	{
		curr = hash->arr[i];//the first item on the linked list on every arrays index starts from zero
		while (curr != NULL)
		{
			next = curr->next;//we save the next item
			free(curr);//we free the current one
			curr = next;//now the next item is the current one
		}
		hash->arr[i] = NULL;//we set the head to NULL
	}
	free(hash->arr);//we free the array
	hash->arr = NULL;
	free(hash);//we free the hash map
	hash = NULL;
}