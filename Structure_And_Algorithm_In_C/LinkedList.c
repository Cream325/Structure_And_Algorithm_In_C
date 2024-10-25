#include "LinkedList.h"

#pragma region LinkedListNode 함수

void LinkedList_Constructor(linkedListNode_t** node, ELEMENT_TYPE newData) {
	// 노드 동적 할당
	(*node) = (linkedListNode_t*)malloc(sizeof(linkedListNode_t));

	// 노드 데이터 대입
	(*node)->data = newData;
	(*node)->nextNode = NULL;

	//printf("Node is Created\n");
}

void LinkedList_Destructor(linkedListNode_t* node) {
	free(node);
	//printf("Node is Deleted\n");
}
#pragma endregion

#pragma region SinglyLinkedList 함수

void SLL_Constructor(linkedList_t** list) {
	// 링크드 리스트 동적 할당
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
	linkedListNode_t* newNode;
	LinkedList_Constructor(&newNode, newData);

	// 헤드가 null인 경우
	if ((*list)->headNode == NULL) {
		(*list)->headNode = newNode;
		(*list)->tailNode = newNode;
	}
	else {
		// 헤드 다음노드가 null인 경우, 일반적인 경우
		if ((*list)->headNode->nextNode == NULL)
			(*list)->headNode->nextNode = newNode;
		else
			(*list)->tailNode->nextNode = newNode;

		(*list)->tailNode = newNode;
	}

	(*list)->length++;
}

void SLL_Insert(linkedList_t** list, ELEMENT_TYPE newData, int index) {
	if ((*list)->headNode == NULL) {
		SLL_Append(list, newData);
		return;
	}

	linkedListNode_t* newNode;
	LinkedList_Constructor(&newNode, newData);

	// 인덱스가 0 이하인 경우
	if (index <= 0) {
		newNode->nextNode = (*list)->headNode;
		(*list)->headNode = newNode;
		(*list)->length++;
		return;
	}

	// 인덱스가 리스트 최대 인덱스 이상인 경우 (Append와 연산이 같음)
	if (index >= (*list)->length - 1) {
		SLL_Append(list, newData);
		return;
	}

	// 일반적인 경우
	linkedListNode_t* currentNode = SLL_Search(*list, index - 1);
	linkedListNode_t* tempNode = currentNode->nextNode;
	currentNode->nextNode = newNode;
	newNode->nextNode = tempNode;
	(*list)->length++;
}

linkedListNode_t* SLL_Search(linkedList_t* list, int index) {
	linkedListNode_t* currentNode = list->headNode;

	if (currentNode != NULL) {
		while (currentNode->nextNode != NULL && --index >= 0) {
			currentNode = currentNode->nextNode;
		}
	}

	return currentNode;
}

linkedListNode_t SLL_Delete(linkedList_t** list, int index) {
	linkedListNode_t deletedNode;

	if ((*list)->headNode != NULL) {
		// 헤드를 삭제할 경우
		if ((*list)->headNode->nextNode == NULL || index <= 0) {
			linkedListNode_t* tempNode = (*list)->headNode;
			deletedNode = *tempNode;
			(*list)->headNode = (*list)->headNode->nextNode;
			tempNode->nextNode = NULL;
			LinkedList_Destructor(tempNode);
		}
		else {
			// 중간노드, 테일을 삭제할 경우
			index = index >= (*list)->length ? (*list)->length - 1 : index;
			linkedListNode_t* currentNode = SLL_Search(*list, index - 1);
			linkedListNode_t* tempNode = currentNode->nextNode;
			deletedNode = *tempNode;
			currentNode->nextNode = tempNode->nextNode;
			tempNode->nextNode = NULL;

			// 테일을 삭제할 시, 테일의 위치를 변경
			if (index == (*list)->length - 1)
				(*list)->tailNode = currentNode;

			LinkedList_Destructor(tempNode);
		}

		(*list)->length--;
	}

	return deletedNode;
}

void SLL_Traversal(linkedList_t* list) {
	linkedListNode_t* currentNode = list->headNode;

	while (currentNode != NULL) {
		printf("%d ", currentNode->data);
		currentNode = currentNode->nextNode;
	}
}

#pragma endregion

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
	linkedListNode_t* newNode;
	LinkedList_Constructor(&newNode, newData);

	// 헤드가 null인 경우
	if ((*list)->headNode == NULL) {
		(*list)->headNode = newNode;
		(*list)->tailNode = (*list)->headNode;
	}
	else {
		//헤드의 다음노드가 null인 경우, 일반적인 경우
		if ((*list)->headNode->nextNode == NULL) {
			(*list)->headNode->nextNode = newNode;
			newNode->previousNode = (*list)->headNode;
		}
		else {
			(*list)->tailNode->nextNode = newNode;
			newNode->previousNode = (*list)->tailNode;
		}

		(*list)->tailNode = newNode;
	}

	(*list)->length++;
}

void DLL_Insert(linkedList_t** list, ELEMENT_TYPE newData, int index) {
	// 헤드가 null인 경우
	if ((*list)->headNode == NULL) {
		DLL_Append(list, newData);
		return;
	}

	linkedListNode_t* newNode;
	LinkedList_Constructor(&newNode, newData);

	// 인덱스가 0 이하인 경우
	if (index <= 0) {
		newNode->nextNode = (*list)->headNode;
		(*list)->headNode->previousNode = newNode;
		(*list)->headNode = newNode;
		(*list)->length++;
		return;
	}
	
	// 인덱스가 리스트 최대 인덱스 이상인 경우 (Append와 연산이 같음)
	if (index >= (*list)->length - 1) {
		DLL_Append(list, newData);
		return;
	}

	// 일반적인 경우
	linkedListNode_t* currentNode = DLL_Search(*list, index);
	currentNode->previousNode->nextNode = newNode;
	newNode->previousNode = currentNode->previousNode;
	newNode->nextNode = currentNode;
	currentNode->previousNode = newNode;
	(*list)->length++;
}

linkedListNode_t* DLL_Search(linkedList_t* list, int index) {
	linkedListNode_t* currentNode = NULL;

	if (index <= list->length / 2) {
		currentNode = list->headNode;
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
	linkedListNode_t deletedNode;

	if ((*list)->headNode != NULL) {
		// 헤드를 삭제할 경우
		if ((*list)->headNode->nextNode == NULL || index <= 0) {
			linkedListNode_t* tempNode = (*list)->headNode;
			deletedNode = *tempNode;
			(*list)->headNode = (*list)->headNode->nextNode;
			tempNode->nextNode = NULL;
			LinkedList_Destructor(tempNode);
		}
		else {
			index = index >= (*list)->length ? (*list)->length - 1 : index;
			linkedListNode_t* currentNode = DLL_Search(*list, index);
			deletedNode = *currentNode;

			// 중간노드를 삭제할 경우
			if (currentNode->nextNode != NULL) {
				currentNode->previousNode->nextNode = currentNode->nextNode;
				currentNode->nextNode->previousNode = currentNode->previousNode;
			}
			else {
				// 테일을 삭제할 경우
				(*list)->tailNode = currentNode->previousNode;
				currentNode->previousNode->nextNode = NULL;
			}

			currentNode->nextNode = NULL;
			currentNode->previousNode = NULL;
			LinkedList_Destructor(currentNode);
		}

		(*list)->length--;
	}

	return deletedNode;
}

void DLL_Traversal(linkedList_t* list) {
	linkedListNode_t* currentNode = list->headNode;

	while (currentNode != NULL) {
		printf("%d ", currentNode->data);
		currentNode = currentNode->nextNode;
	}
}

#pragma endregion

#pragma region CircularLinkedList 함수

void CLL_Constructor(linkedList_t** list) {
	// 순환 링크드 리스트 동적 할당
	(*list) = (linkedList_t*)malloc(sizeof(linkedList_t));

	// 링크드 리스트 데이터 대입
	(*list)->headNode = NULL;
	(*list)->tailNode = NULL;
	(*list)->length = 0;
}

void CLL_Destructor(linkedList_t* list) {
	for (int i = list->length - 1; i >= 0; i--) {
		CLL_Delete(&list, i);
	}

	free(list);
}

void CLL_Append(linkedList_t** list, ELEMENT_TYPE newData) {
	linkedListNode_t* newNode;
	LinkedList_Constructor(&newNode, newData);

	// 헤드가 null인 경우
	if ((*list)->headNode == NULL) {
		(*list)->headNode = newNode;
		(*list)->tailNode = (*list)->headNode;

		(*list)->headNode->nextNode = (*list)->tailNode;
		(*list)->tailNode->previousNode = (*list)->headNode;
	}
	else {
		// 일반적인 경우
		(*list)->tailNode->nextNode = newNode;
		newNode->previousNode = (*list)->tailNode;
		(*list)->tailNode = newNode;
	}

	(*list)->headNode->previousNode = (*list)->tailNode;
	(*list)->tailNode->nextNode = (*list)->headNode;
	(*list)->length++;
}

// 삽입에 문제가 있음. 수정필요
void CLL_Insert(linkedList_t** list, ELEMENT_TYPE newData, int index) {
	// 헤드가 null인 경우
	if ((*list)->headNode == NULL) {
		CLL_Append(list, newData);
		return;
	}

	linkedListNode_t* newNode;
	LinkedList_Constructor(&newNode, newData);

	// 헤드 다음노드가 null인 경우, 인덱스가 0이하인 경우
	if ((*list)->headNode->nextNode == NULL || index <= 0) {
		newNode->nextNode = (*list)->headNode;
		(*list)->headNode->previousNode = newNode;
		(*list)->headNode = newNode;
		(*list)->length++;
		return;
	}

	// 인덱스가 리스트 최대 인덱스 이상인 경우 (Append와 연산이 같음)
	if (index >= (*list)->length - 1) {
		(*list)->tailNode->nextNode = newNode;
		newNode->previousNode = (*list)->tailNode;
		(*list)->tailNode = newNode;

		(*list)->tailNode->nextNode = (*list)->headNode;
		(*list)->headNode->previousNode = (*list)->tailNode;
		(*list)->length++;
		return;
	}

	// 일반적인 경우
	linkedListNode_t* currentNode = CLL_Search(*list, index);
	currentNode->previousNode->nextNode = newNode;
	newNode->previousNode = currentNode->previousNode;
	newNode->nextNode = currentNode;
	currentNode->previousNode = newNode;
	(*list)->length++;
}

linkedListNode_t* CLL_Search(linkedList_t* list, int index) {
	linkedListNode_t* currentNode;

	if (index <= list->length / 2) {
		currentNode = list->headNode;
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
	linkedListNode_t deletedNode;

	if ((*list)->headNode != NULL) {
		// 헤드를 삭제할 경우
		if ((*list)->headNode->nextNode == (*list)->tailNode || index <= 0) {
			linkedListNode_t* tempNode = (*list)->headNode;
			deletedNode = *tempNode;
			tempNode->nextNode = NULL;
			tempNode->previousNode = NULL;
			LinkedList_Destructor(tempNode);
		}
		else {
			index = index >= (*list)->length ? (*list)->length - 1 : index;
			linkedListNode_t* currentNode = CLL_Search(*list, index);

			// 중간노드를 삭제할 경우
			if (currentNode->nextNode != NULL) {
				currentNode->previousNode->nextNode = currentNode->nextNode;
				currentNode->nextNode->previousNode = currentNode->previousNode;
			}
			else {
				// 테일을 삭제할 경우
				(*list)->tailNode = currentNode->previousNode;
				currentNode->previousNode->nextNode = (*list)->headNode;
			}

			deletedNode = *currentNode;
		}
	}

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
