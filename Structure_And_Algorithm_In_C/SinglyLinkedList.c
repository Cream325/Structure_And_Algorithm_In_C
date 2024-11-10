#include "LinkedList.h"

#pragma region SinglyLinkedList �Լ�

void SLL_Constructor(linkedList_t** list) {
	// ���� ��ũ�� ����Ʈ ���� �Ҵ�
	(*list) = (linkedList_t*)malloc(sizeof(linkedList_t));

	// ��ũ�� ����Ʈ ������ ����
	(*list)->headNode = NULL;
	(*list)->tailNode = NULL;
	(*list)->length = 0;

	//printf("SLL is Created\n");
}

void SLL_Destructor(linkedList_t* list) {
	for(int i = list->length-1; i >= 0; i--) {
		SLL_Delete(&list, i);
	}

	free(list);
	//printf("SLL is Deleted\n");
}

void SLL_Append(linkedList_t** list, ELEMENT_TYPE newData) {
	SLL_Insert(list, newData, (*list)->length);
}

void SLL_Insert(linkedList_t** list, ELEMENT_TYPE newData, int index) {
	linkedListNode_t* newNode;
	LinkedList_Constructor(&newNode, newData);

	if ((*list)->headNode == NULL) {
		// Head�� null�� ���
		(*list)->headNode = newNode;
		(*list)->tailNode = (*list)->headNode;
	}
	else if (index <= 0) {
		// �ε����� 0������ ���
		newNode->nextNode = (*list)->headNode;
		(*list)->headNode = newNode;
	}
	else if (index >= (*list)->length - 1) {
		// �ε����� length-1�̻��� ���
		if ((*list)->headNode == (*list)->tailNode)
			(*list)->headNode->nextNode = newNode;
		else
			(*list)->tailNode->nextNode = newNode;

		(*list)->tailNode->nextNode = newNode;
	}
	else {
		// �Ϲ����� ���
		linkedListNode_t* currentNode = SLL_Search((*list), index - 1);
		linkedListNode_t* tempNode = currentNode->nextNode;
		currentNode->nextNode = newNode;
		newNode->nextNode = tempNode;
	}

	(*list)->length++;
}

linkedListNode_t* SLL_Search(linkedList_t* list, int index) {
	if (list->headNode == NULL) return NULL;
	
	linkedListNode_t* currentNode = list->headNode;

	while (currentNode->nextNode != NULL && --index >= 0) {
		currentNode = currentNode->nextNode;
	}

	return currentNode;
}

linkedListNode_t SLL_Delete(linkedList_t** list, int index) {
	// Head�� null�� ���
	if ((*list)->headNode == NULL) return;

	linkedListNode_t deletedNode;
	linkedListNode_t* tempNode;

	if ((*list)->headNode == (*list)->tailNode) {
		// Head�� Tail�� ���� ���
		tempNode = (*list)->headNode;
		(*list)->headNode = NULL;
		(*list)->tailNode = NULL;
	}
	else if (index <= 0) {
		// �ε����� 0������ ���
		tempNode = (*list)->headNode;
		(*list)->headNode = (*list)->headNode->nextNode;
	}
	else {
		// �ε����� length-1�̻��� ���, �Ϲ����� ���
		index = index >= (*list)->length - 1 ? (*list)->length - 1 : index;
		linkedListNode_t* currentNode = SLL_Search((*list), index - 1);
		tempNode = currentNode->nextNode;
		currentNode->nextNode = tempNode->nextNode;
		(*list)->tailNode = currentNode;
	}

	deletedNode = (*tempNode);
	LinkedList_Destructor(tempNode);
	(*list)->length--;
	
	return deletedNode;
}

void SLL_Traversal(linkedList_t* list) {
	if (list->headNode == NULL) return;

	linkedListNode_t* currentNode = list->headNode;

	do {
		printf("%d ", currentNode->data);
		currentNode = currentNode->nextNode;
	} while (currentNode != list->headNode && currentNode != NULL);
}

#pragma endregion