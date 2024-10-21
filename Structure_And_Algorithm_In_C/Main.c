#include <stdio.h>
#include "LinkedList.h"

int main(void) {
	linkedList_t* list = CLL_Constructor();

	CLL_Append(&list, 1);
	CLL_Append(&list, 2);
	CLL_Append(&list, 3);
	CLL_Append(&list, 4);
	CLL_Append(&list, 5);

	//CLL_Insert(&list, 10, 1);

	CLL_Traversal(list);

	CLL_Destructor(list);
	return 0;
}

// null pointer 또는 out of index에 대한 예외처리 필요
// 1. Error Code 정의
// 2. 각 Error Code에 대하여 예외처리