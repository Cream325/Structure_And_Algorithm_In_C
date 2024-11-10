#include "LinkedList.h"

#pragma region DoublyLinkedList 함수

void DLL_Constructor(linkedList_t** list) {
	// 더블 링크드 리스트 동적 할당
	(*list) = (linkedList_t*)malloc(sizeof(linkedList_t));

	// 링크드 리스트 데이터 대입
	(*list)->headNode = NULL;
	(*list)->tailNode = NULL;
	(*list)->length = 0;

	//printf("DLL is Created\n");
}

void DLL_Destructor(linkedList_t* list) {
	for (int i = list->length - 1; i >= 0; i--) {
		DLL_Delete(&list, i);
	}

	free(list);
	//printf("DLL is Deleted\n");
}

void DLL_Append(linkedList_t** list, ELEMENT_TYPE newData) {
	DLL_Insert(list, newData, (*list)->length);
}

void DLL_Insert(linkedList_t** list, ELEMENT_TYPE newData, int index) {
	linkedListNode_t* newNode;
	LinkedList_Constructor(&newNode, newData);

	// Head가 null인 경우
	if ((*list)->headNode == NULL) {
		(*list)->headNode = newNode;
		(*list)->tailNode = (*list)->headNode;
	}
	else if (index <= 0) {
		// 인덱스가 0이하인 경우
		newNode->nextNode = (*list)->headNode;
		(*list)->headNode->previousNode = newNode;
		(*list)->headNode = newNode;
	}
	else if (index >= (*list)->length - 1) {
		// 인덱스가 length-1이상인 경우
		if ((*list)->headNode == (*list)->tailNode) {
			(*list)->headNode->nextNode = newNode;
			newNode->previousNode = (*list)->headNode;
		}
		else {
			(*list)->tailNode->nextNode = newNode;
			newNode->previousNode = (*list)->tailNode;
		}

		(*list)->tailNode = newNode;
	}
	else {
		// 일반적인 경우
		linkedListNode_t* currentNode = DLL_Search((*list), index);
		currentNode->previousNode->nextNode = newNode;
		newNode->previousNode = currentNode->previousNode;
		newNode->nextNode = currentNode;
		currentNode->previousNode = newNode;
	}

	(*list)->length++;
}

linkedListNode_t* DLL_Search(linkedList_t* list, int index) {
	if (list->headNode == NULL) return NULL;

	linkedListNode_t* currentNode = list->headNode;

	if (index <= list->length / 2) {
		while (currentNode->nextNode != NULL && --index >= 0) {
			currentNode = currentNode->nextNode;
		}
	}
	else {
		int maxIndex = list->length - 1;
		currentNode = list->tailNode;
		while (currentNode->previousNode != NULL && --maxIndex >= index) {
			currentNode = currentNode->previousNode;
		}
	}

	return currentNode;
}

linkedListNode_t DLL_Delete(linkedList_t** list, int index) {
	// Head가 null인 경우
	if((*list)->headNode == NULL) return;

	linkedListNode_t deletedNode;
	linkedListNode_t* tempNode;

	if ((*list)->headNode == (*list)->tailNode) {
		// Head와 Tail이 같을 경우
		tempNode = (*list)->headNode;
		(*list)->headNode = NULL;
		(*list)->tailNode = NULL;
	}
	else if (index <= 0) {
		// 인덱스가 0이하일 경우
		tempNode = (*list)->headNode;
		(*list)->headNode->nextNode->previousNode = NULL;
		(*list)->headNode = (*list)->headNode->nextNode;
	}
	else {
		// 인덱스가 length-1이상일 경우, 일반적인 경우
		linkedListNode_t* currentNode = DLL_Search((*list), index);
		tempNode = currentNode;
		currentNode->previousNode->nextNode = currentNode->nextNode;

		if (index >= (*list)->length - 1)
			(*list)->tailNode = currentNode->previousNode;
		else
			currentNode->nextNode->previousNode = currentNode->previousNode;
	}

	deletedNode = (*tempNode);
	LinkedList_Destructor(tempNode);
	(*list)->length--;

	return deletedNode;
}

void DLL_Traversal(linkedList_t* list) {
	if (list->headNode == NULL) return;

	linkedListNode_t* currentNode = list->headNode;

	do {
		printf("%d ", currentNode->data);
		currentNode = currentNode->nextNode;
	} while (currentNode != list->headNode && currentNode != NULL);
}

#pragma endregion