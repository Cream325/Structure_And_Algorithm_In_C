#include <stdio.h>
#include "LinkedList.h"

int main(void) {
	linkedList_t* list = SLL_Constructor();

	SLL_Append(&list, 1);
	SLL_Append(&list, 2);
	SLL_Append(&list, 3);
	SLL_Append(&list, 4);
	SLL_Append(&list, 5);
	SLL_Append(&list, 6);
	SLL_Append(&list, 7);
	SLL_Append(&list, 8);
	SLL_Append(&list, 9);
	SLL_Append(&list, 10);

	SLL_Traversal(list);

	SLL_Destructor(list);
	return 0;
}