#include "LinkedList.h"

#pragma region LinkedListNode �Լ�

linkedListNode_t* LinkedList_Constructor(ELEMENT_TYPE newData) {
	// ��� ���� �Ҵ�
	linkedListNode_t* newNode = (linkedListNode_t*)malloc(sizeof(linkedListNode_t));

	// ��� ������ ����
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

#pragma region SinglyLinkedList �Լ�

linkedList_t* SLL_Constructor() {
	// ��ũ�� ����Ʈ ���� �Ҵ�
	linkedList_t* newList = (linkedList_t*)malloc(sizeof(linkedList_t));

	// ��ũ�� ����Ʈ ������ ����
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

	// ��尡 null�� ���
	if ((*list)->headNode == NULL) {
		(*list)->headNode = newNode;
		(*list)->tailNode = (*list)->headNode;
	}
	else {
		// ��� ������尡 null�� ���, �Ϲ����� ���
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

	// ��尡 null�� ���, �ε����� 0 ������ ���
	if ((*list)->headNode == NULL || index <= 0) {
		newNode->nextNode = (*list)->headNode;
		(*list)->headNode = newNode;
		(*list)->length++;
		return;
	}

	// �ε����� ����Ʈ �ִ� �ε��� �̻��� ��� (Append�� ������ ����)
	if (index >= (*list)->length - 1) {
		(*list)->tailNode->nextNode = newNode;
		(*list)->tailNode = (*list)->tailNode->nextNode;
		(*list)->length++;
		return;
	}

	// �Ϲ����� ���
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
		// ��带 ������ ���
		if ((*list)->headNode->nextNode == NULL || index <= 0) {
			linkedListNode_t* tempNode = (*list)->headNode;
			deletedNode = *tempNode;
			(*list)->headNode = (*list)->headNode->nextNode;
			LinkedList_Destructor(tempNode);
		}
		else {
			// �߰����, ������ ������ ���
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

// ���� ��ũ�� ����Ʈ - �켱 �ּ�ó��
/*
#pragma region DoublyLinkedList �Լ�

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
