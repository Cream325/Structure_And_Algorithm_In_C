#include <stdio.h>
#include "CustomStack.h"

int main(void) {
	linkedList_t* list;
	CLL_Constructor(&list);

	CLL_Append(&list, 1);
	CLL_Append(&list, 2);
	CLL_Append(&list, 3);
	CLL_Append(&list, 4);
	CLL_Append(&list, 5);

	CLL_Insert(&list, 10, 1);

	CLL_Traversal(list);

	CLL_Destructor(list);

	/*
	arrayStack_t* stack = ArrStack_Constructor(5);

	ArrStack_Push(&stack, 1);
	ArrStack_Push(&stack, 2);
	ArrStack_Push(&stack, 3);
	ArrStack_Push(&stack, 4);
	ArrStack_Push(&stack, 5);

	ArrStack_Destructor(stack);
	*/

	return 0;
}

// null pointer 또는 out of index에 대한 예외처리 필요
// 1. Error Code 정의
// 2. 각 Error Code에 대하여 예외처리