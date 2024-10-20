#include "LinkedList.h"

#pragma region LinkedListNode 함수

linkedListNode_t* LinkedList_Constructor(ELEMENT_TYPE newData) {
	// 노드 동적 할당
	linkedListNode_t* newNode = (linkedListNode_t*)malloc(sizeof(linkedListNode_t));

	// 노드 데이터 대입
	newNode->data = newData;
	newNode->nextNode= NULL;

	//printf("Node is Created\n");

	return newNode;
}

void LinkedList_Destructor(linkedListNode_t* node) {
	free(node);
	//printf("Node is Deleted\n");
}
#pragma endregion

#pragma region SinglyLinkedList 함수

linkedList_t* SLL_Constructor() {
	// 링크드 리스트 동적 할당
	linkedList_t* newList = (linkedList_t*)malloc(sizeof(linkedList_t));

	// 링크드 리스트 데이터 대입
	newList->headNode = NULL;
	newList->tailNode = NULL;
	newList->length = 0;

	//printf("SLL is Created\n");

	return newList;
}

void SLL_Destructor(linkedList_t* list) {
	for(int i = list->length-1; i >= 0; i--) {
		SLL_Delete(&list, i);
	}

	free(list);
	//printf("SLL is Deleted\n");
}

void SLL_Append(linkedList_t** list, ELEMENT_TYPE newData) {
	linkedListNode_t* newNode = LinkedList_Constructor(newData);

	// 헤드가 null인 경우
	if ((*list)->headNode == NULL) {
		(*list)->headNode = newNode;
		(*list)->tailNode = (*list)->headNode;
	}
	else {
		// 헤드 다음노드가 null인 경우, 일반적인 경우
		if ((*list)->headNode->nextNode == NULL)
			(*list)->headNode->nextNode = newNode;
		else
			(*list)->tailNode->nextNode = newNode;

		(*list)->tailNode = (*list)->tailNode->nextNode;
	}

	(*list)->length++;
}

void SLL_Insert(linkedList_t** list, ELEMENT_TYPE newData, int index) {
	linkedListNode_t* newNode = LinkedList_Constructor(newData);

	// 헤드가 null인 경우, 인덱스가 0 이하인 경우
	if ((*list)->headNode == NULL || index <= 0) {
		newNode->nextNode = (*list)->headNode;
		(*list)->headNode = newNode;
		(*list)->length++;
		return;
	}

	// 인덱스가 리스트 최대 인덱스 이상인 경우 (Append와 연산이 같음)
	if (index >= (*list)->length - 1) {
		(*list)->tailNode->nextNode = newNode;
		(*list)->tailNode = (*list)->tailNode->nextNode;
		(*list)->length++;
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
			LinkedList_Destructor(tempNode);
		}
		else {
			// 중간노드, 테일을 삭제할 경우
			index = index >= (*list)->length ? (*list)->length - 1 : index;
			linkedListNode_t* currentNode = SLL_Search(*list, index - 1);
			linkedListNode_t* tempNode = currentNode->nextNode;
			deletedNode = *tempNode;
			currentNode->nextNode = tempNode->nextNode;
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

// 이중 링크드 리스트 - 우선 주석처리
/*
#pragma region DoublyLinkedList 함수

void DLL_Append(Node** list, ElementType newData) {
	Node* newNode = LinkedList_CreateNode(newData);

	if ((*list) == NULL) {
		*list = newNode;
	}
	else {
		Node* tailNode = (*list);

		while (tailNode->NextNode != NULL) {
			tailNode = tailNode->NextNode;
		}

		tailNode->NextNode = newNode;
		newNode->PreviousNode = tailNode;
	}
}

void DLL_Insert(Node** list, ElementType newData, int index) {

}

Node* DLL_Search(Node* list, int index) {
	Node* currentNode = list;

	while (currentNode != NULL && (--index) >= 0) {
		currentNode = currentNode->NextNode;
	}

	return currentNode;
}

void DLL_Delete(Node** list, int index) {
	Node* deletedNode = NULL;

	if (index == 0) {
		deletedNode = *list;
		*list = (*list)->NextNode;
	}
	else {
		Node* currentNode = *list;

		while (currentNode != NULL && (--index) > 1) {
			currentNode = currentNode->NextNode;
		}

		deletedNode = currentNode->NextNode;
		currentNode->NextNode = currentNode->NextNode->NextNode;
	}

	LinkedList_DestroyNode(deletedNode);
}

void DLL_Traversal(Node* list) {
	Node* currentNode = list;

	while (currentNode != NULL) {
		printf("%d\n", currentNode->Data);
		currentNode = currentNode->NextNode;
	}

	printf("\n");
}

int DLL_Length(Node* list) {
	return 0;
}

#pragma endregion
*/
