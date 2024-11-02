#include "LinkedList.h"

#pragma region LinkedListNode Functions

void LinkedList_Constructor(linkedListNode_t** node, ELEMENT_TYPE newData) {
	// 동적 할당
	(*node) = (linkedListNode_t*)malloc(sizeof(linkedListNode_t));

	// 노드 데이터 대입
	(*node)->data = newData;
	(*node)->nextNode = NULL;
	(*node)->previousNode = NULL;

	//printf("Node is Created\n");
}

void LinkedList_Destructor(linkedListNode_t* node) {
	node->nextNode = NULL;
	node->previousNode = NULL;

	// 메모리 해제
	free(node);

	//printf("Node is Deleted\n");
}

#pragma endregion