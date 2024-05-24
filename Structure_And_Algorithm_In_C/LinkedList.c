#include "LinkedList.h"

Node* LinkedList_CreateNode(ElementType newData) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->Data = newData;
	newNode->NextNode = NULL;

	return newNode;
}

void LinkedList_DestroyNode(Node* node) {
	free(node);
}

#pragma region SinglyLinkedList 함수

void SLL_Append(Node** list, ElementType newData) {
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
	}
}

void SLL_Insert(Node** list, ElementType newData, int index) {
	Node* newNode = LinkedList_CreateNode(newData);
	int length = SLL_Length(*list);

	if (index < 0) index = 0;
	else if (index >= (length - 1)) index = length - 1;

	if (index == 0) {
		newNode->NextNode = *list;
		*list = newNode;
	}
	else if (index == (length - 1)) {
		SLL_Append(list, newData);
		return;
	}
	else {
		Node* currentNode = SLL_Search(*list, index - 1);

		newNode->NextNode = currentNode->NextNode;
		currentNode->NextNode = newNode;
	}
}

Node* SLL_Search(Node* list, int index) {
	Node* currentNode = list;

	while ((currentNode != NULL) && (--index) >= 0) {
		currentNode = currentNode->NextNode;
	}

	return currentNode;
}

void SLL_Delete(Node** list, int index) {
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

void SLL_Traversal(Node* list) {
	Node* currentNode = list;

	while (currentNode != NULL) {
		printf("%d ", currentNode->Data);
		currentNode = currentNode->NextNode;
	}

	printf("\n");
}

int SLL_Length(Node* list) {
	int length = 0;
	Node* currentNode = list;

	while (currentNode != NULL) {
		currentNode = currentNode->NextNode;
		length++;
	}

	return length;
}

#pragma endregion

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
