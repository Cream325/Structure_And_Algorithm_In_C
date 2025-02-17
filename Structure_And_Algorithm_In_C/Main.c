#include <stdio.h>
#include "linkedList.h"

int main(void) {
	lnkList_t list;
	linkedList_doubly_newStack(&list);

	int arr[5] = { 1, 2, 3, 4, 5 };
	list.appendAll (&list, arr, 5);

	list.traversal(&list);

	linkedList_delete(&list);
	return 0;
}