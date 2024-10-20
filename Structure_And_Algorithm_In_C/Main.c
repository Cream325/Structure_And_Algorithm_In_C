#include <stdio.h>
#include "LinkedList.h"

int main(void) {
	linkedList_t* list = DLL_Constructor();

	DLL_Append(&list, 1);
	DLL_Append(&list, 2);
	DLL_Append(&list, 3);
	DLL_Append(&list, 4);
	DLL_Append(&list, 5);

	DLL_Insert(&list, 10, 0);

	DLL_Traversal(list);

	DLL_Destructor(list);
	return 0;
}