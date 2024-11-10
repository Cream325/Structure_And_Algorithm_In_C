#include "LinkedList.h"

#pragma region SinglyLinkedList 함수

void SLL_Constructor(linkedList_t** list) {
	// 단일 링크드 리스트 동적 할당
	(*list) = (linkedList_t*)malloc(sizeof(linkedList_t));

	// 링크드 리스트 데이터 대입
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
		// Head가 null인 경우
		(*list)->headNode = newNode;
		(*list)->tailNode = (*list)->headNode;
	}
	else if (index <= 0) {
		// 인덱스가 0이하인 경우
		newNode->nextNode = (*list)->headNode;
		(*list)->headNode = newNode;
	}
	else if (index >= (*list)->length - 1) {
		// 인덱스가 length-1이상인 경우
		if ((*list)->headNode == (*list)->tailNode)
			(*list)->headNode->nextNode = newNode;
		else
			(*list)->tailNode->nextNode = newNode;

		(*list)->tailNode->nextNode = newNode;
	}
	else {
		// 일반적인 경우
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
	// Head가 null인 경우
	if ((*list)->headNode == NULL) return;

	linkedListNode_t deletedNode;
	linkedListNode_t* tempNode;

	if ((*list)->headNode == (*list)->tailNode) {
		// Head와 Tail이 같은 경우
		tempNode = (*list)->headNode;
		(*list)->headNode = NULL;
		(*list)->tailNode = NULL;
	}
	else if (index <= 0) {
		// 인덱스가 0이하일 경우
		tempNode = (*list)->headNode;
		(*list)->headNode = (*list)->headNode->nextNode;
	}
	else {
		// 인덱스가 length-1이상일 경우, 일반적인 경우
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