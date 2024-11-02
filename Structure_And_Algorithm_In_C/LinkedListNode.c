#include "LinkedList.h"

#pragma region LinkedListNode Functions

void LinkedList_Constructor(linkedListNode_t** node, ELEMENT_TYPE newData) {
	// ���� �Ҵ�
	(*node) = (linkedListNode_t*)malloc(sizeof(linkedListNode_t));

	// ��� ������ ����
	(*node)->data = newData;
	(*node)->nextNode = NULL;
	(*node)->previousNode = NULL;

	//printf("Node is Created\n");
}

void LinkedList_Destructor(linkedListNode_t* node) {
	node->nextNode = NULL;
	node->previousNode = NULL;

	// �޸� ����
	free(node);

	//printf("Node is Deleted\n");
}

#pragma endregion