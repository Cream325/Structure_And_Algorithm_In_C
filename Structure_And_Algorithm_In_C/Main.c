#include <stdio.h>
#include "LinkedList.h"

int main(void) {
	linkedList_t* list = DLL_Constructor();

	DLL_Append(&list, 1);
	DLL_Append(&list, 2);
	DLL_Append(&list, 3);
	DLL_Append(&list, 4);
	DLL_Append(&list, 5);
	DLL_Append(&list, 6);
	DLL_Append(&list, 7);
	DLL_Append(&list, 8);
	DLL_Append(&list, 9);
	DLL_Append(&list, 10);

	DLL_Traversal(list);

	DLL_Destructor(list);
	return 0;
}