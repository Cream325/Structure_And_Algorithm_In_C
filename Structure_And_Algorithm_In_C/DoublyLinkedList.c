#include "LinkedList.h"

#pragma region DoublyLinkedList �Լ�

void DLL_Constructor(linkedList_t** list) {
	// ���� ��ũ�� ����Ʈ ���� �Ҵ�
	(*list) = (linkedList_t*)malloc(sizeof(linkedList_t));

	// ��ũ�� ����Ʈ ������ ����
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

	// Head�� null�� ���
	if ((*list)->headNode == NULL) {
		(*list)->headNode = newNode;
		(*list)->tailNode = (*list)->headNode;
		(*list)->length++;
		return;
	}

	// Head�� Tail�� ���� ���
	if ((*list)->headNode == (*list)->tailNode) {
		(*list)->headNode->nextNode = newNode;
		newNode->previousNode = (*list)->headNode;
	}
	else {
		// �Ϲ����� ���
		(*list)->tailNode->nextNode = newNode;
		newNode->previousNode = (*list)->tailNode;
	}

	(*list)->tailNode = newNode;
	(*list)->length++;
}

void DLL_Insert(linkedList_t** list, ELEMENT_TYPE newData, int index) {
	// Head�� null�� ���, �ε����� length-1�̻��� ���
	if ((*list)->headNode == NULL || index >= (*list)->length - 1) {
		DLL_Append(list, newData);
		return;
	}

	linkedListNode_t* newNode;
	LinkedList_Constructor(&newNode, newData);

	// �ε����� 0������ ���
	if (index <= 0) {
		newNode->nextNode = (*list)->headNode;
		(*list)->headNode->previousNode = newNode;
		(*list)->headNode = newNode;
	}
	else {
		// �Ϲ����� ���
		linkedListNode_t* currentNode = DLL_Search((*list), index);
		currentNode->previousNode->nextNode = newNode;
		newNode->previousNode = currentNode->previousNode;
		newNode->nextNode = currentNode;
		currentNode->previousNode = newNode;
	}

	(*list)->length++;
}

linkedListNode_t* DLL_Search(linkedList_t* list, int index) {
	linkedListNode_t* currentNode = list->headNode;

	if (currentNode != NULL) {
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
	}

	return currentNode;
}

linkedListNode_t DLL_Delete(linkedList_t** list, int index) {
	// Head�� null�� ���
	if((*list)->headNode == NULL)
		return;

	linkedListNode_t deletedNode;
	linkedListNode_t* tempNode;

	// Head�� Tail�� ���� ���
	if ((*list)->headNode == (*list)->tailNode) {
		tempNode = (*list)->headNode;
		(*list)->headNode = NULL;
		(*list)->tailNode = NULL;
	}
	else {
		// �ε����� 0������ ���
		if (index <= 0) {
			tempNode = (*list)->headNode;
			(*list)->headNode->nextNode->previousNode = NULL;
			(*list)->headNode = (*list)->headNode->nextNode;
		}
		else {
			linkedListNode_t* currentNode = DLL_Search((*list), index);
			tempNode = currentNode;
			currentNode->previousNode->nextNode = currentNode->nextNode;

			// �ε����� length-1�̻��� ���
			if (index >= (*list)->length - 1)
				(*list)->tailNode = currentNode->previousNode;
			else
				// �Ϲ����� ���
				currentNode->nextNode->previousNode = currentNode->previousNode;
		}
	}

	deletedNode = (*tempNode);
	LinkedList_Destructor(tempNode);
	(*list)->length--;

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