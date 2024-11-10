#include "LinkedList.h"

#pragma region CircularLinkedList 함수

void CLL_Constructor(linkedList_t** list) {
	// 순환 링크드 리스트 동적 할당
	(*list) = (linkedList_t*)malloc(sizeof(linkedList_t));

	// 링크드 리스트 데이터 대입
	(*list)->headNode = NULL;
	(*list)->tailNode = NULL;
	(*list)->length = 0;

	//printf("CLL is Created\n");
}

void CLL_Destructor(linkedList_t* list) {
	for (int i = list->length - 1; i >= 0; i--) {
		CLL_Delete(&list, i);
	}

	free(list);
	//printf("CLL is Deleted\n");
}

void CLL_Append(linkedList_t** list, ELEMENT_TYPE newData) {
	CLL_Insert(list, newData, (*list)->length);
}

void CLL_Insert(linkedList_t** list, ELEMENT_TYPE newData, int index) {
	linkedListNode_t* newNode;
	LinkedList_Constructor(&newNode, newData);

	if ((*list)->headNode == NULL) {
		// Head가 null인 경우
		(*list)->headNode = newNode;
		(*list)->tailNode = (*list)->headNode;

		(*list)->headNode->nextNode = (*list)->tailNode;
		(*list)->tailNode->previousNode = (*list)->headNode;
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
		linkedListNode_t* currentNode = CLL_Search((*list), index);
		currentNode->previousNode->nextNode = newNode;
		newNode->previousNode = currentNode->previousNode;
		newNode->nextNode = currentNode;
		currentNode->previousNode = newNode;
	}

	(*list)->headNode->previousNode = (*list)->tailNode;
	(*list)->tailNode->nextNode = (*list)->headNode;
	(*list)->length++;
}

linkedListNode_t* CLL_Search(linkedList_t* list, int index) {
	if (list->headNode == NULL) return NULL;

	linkedListNode_t* currentNode = list->headNode;

	if (index <= list->length / 2) {
		while (currentNode->nextNode != list->headNode && --index >= 0) {
			currentNode = currentNode->nextNode;
		}
	}
	else {
		int maxIndex = list->length - 1;
		currentNode = list->tailNode;
		while (currentNode->previousNode != list->tailNode && --maxIndex >= index) {
			currentNode = currentNode->previousNode;
		}
	}

	return currentNode;
}

linkedListNode_t CLL_Delete(linkedList_t** list, int index) {
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
		linkedListNode_t* currentNode = CLL_Search((*list), index);
		tempNode = currentNode;
		currentNode->previousNode->nextNode = currentNode->nextNode;

		if (index >= (*list)->length - 1)
			(*list)->tailNode = currentNode->previousNode;
		else
			currentNode->nextNode->previousNode = currentNode->previousNode;
	}

	(*list)->headNode->previousNode = (*list)->tailNode;
	(*list)->tailNode->nextNode = (*list)->headNode;
	deletedNode = (*tempNode);
	LinkedList_Destructor(tempNode);
	(*list)->length--;

	return deletedNode;
}

void CLL_Traversal(linkedList_t* list) {
	if (list->headNode == NULL) return;

	linkedListNode_t* currentNode = list->headNode;

	do {
		printf("%d ", currentNode->data);
		currentNode = currentNode->nextNode;
	} while (currentNode != list->headNode && currentNode != NULL);
}

#pragma endregion