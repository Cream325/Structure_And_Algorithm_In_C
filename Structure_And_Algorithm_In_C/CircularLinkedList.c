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
	linkedListNode_t* newNode;
	LinkedList_Constructor(&newNode, newData);

	// Head가 null인 경우
	if ((*list)->headNode == NULL) {
		(*list)->headNode = newNode;
		(*list)->tailNode = (*list)->headNode;

		(*list)->headNode->nextNode = (*list)->tailNode;
		(*list)->tailNode->previousNode = (*list)->headNode;
		
		(*list)->headNode->previousNode = (*list)->tailNode;
		(*list)->tailNode->nextNode = (*list)->headNode;
		(*list)->length++;
		return;
	}

	// Head가 Tail과 같은 경우
	if ((*list)->headNode == (*list)->tailNode) {
		(*list)->headNode->nextNode = newNode;
		newNode->previousNode = (*list)->headNode;
	}
	else {
		(*list)->tailNode->nextNode = newNode;
		newNode->previousNode = (*list)->tailNode;
	}

	(*list)->tailNode = newNode;
	(*list)->headNode->previousNode = (*list)->tailNode;
	(*list)->tailNode->nextNode = (*list)->headNode;
	(*list)->length++;
}

void CLL_Insert(linkedList_t** list, ELEMENT_TYPE newData, int index) {
	// Head가 null인 경우. 인덱스가 length-1이상인 경우
	if ((*list)->headNode == NULL || index >= (*list)->length - 1) {
		CLL_Append(list, newData);
		return;
	}

	linkedListNode_t* newNode;
	LinkedList_Constructor(&newNode, newData);

	// 인덱스가 0이하인 경우
	if (index <= 0) {
		newNode->nextNode = (*list)->headNode;
		(*list)->headNode->previousNode = newNode;
		(*list)->headNode = newNode;

		(*list)->headNode->previousNode = (*list)->tailNode;
		(*list)->tailNode->nextNode = (*list)->headNode;
	}
	else {
		// 일반적인 경우
		linkedListNode_t* currentNode = CLL_Search((*list), index);
		currentNode->previousNode->nextNode = newNode;
		newNode->previousNode = currentNode->previousNode;
		newNode->nextNode = currentNode;
		currentNode->previousNode = newNode;
	}

	(*list)->length++;
}

linkedListNode_t* CLL_Search(linkedList_t* list, int index) {
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
	if((*list)->headNode == NULL)
		return;

	linkedListNode_t deletedNode;
	linkedListNode_t* tempNode;

	// Head가 Tail과 같을 경우
	if ((*list)->headNode == (*list)->tailNode) {
		tempNode = (*list)->headNode;
		(*list)->headNode = NULL;
		(*list)->tailNode = NULL;
	}
	else {
		// 인덱스가 0이하일 경우
		if (index <= 0) {
			tempNode = (*list)->headNode;
			(*list)->headNode->nextNode->previousNode = NULL;
			(*list)->headNode = (*list)->headNode->nextNode;

			(*list)->headNode->previousNode = (*list)->tailNode;
			(*list)->tailNode->nextNode = (*list)->headNode;
		}
		else {
			linkedListNode_t* currentNode = CLL_Search((*list), index);
			tempNode = currentNode;
			currentNode->previousNode->nextNode = currentNode->nextNode;

			// 인덱스가 length-1이상일 경우
			if (index >= (*list)->length - 1) {
				(*list)->tailNode = currentNode->previousNode;

				(*list)->headNode->previousNode = (*list)->tailNode;
				(*list)->tailNode->nextNode = (*list)->headNode;
			}
			else
				// 일반적인 경우
				currentNode->nextNode->previousNode = currentNode->previousNode;
		}
	}

	deletedNode = (*tempNode);
	LinkedList_Destructor(tempNode);
	(*list)->length--;

	return deletedNode;
}

void CLL_Traversal(linkedList_t* list) {
	linkedListNode_t* currentNode = list->headNode;

	if (currentNode == NULL)
		return;

	do {
		printf("%d ", currentNode->data);
		currentNode = currentNode->nextNode;
	} while (currentNode != list->headNode);
}

#pragma endregion