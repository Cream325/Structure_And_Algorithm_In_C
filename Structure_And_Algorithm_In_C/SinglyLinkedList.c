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
	if ((*list)->headNode == (*list)->tailNode)
		(*list)->headNode->nextNode = newNode;
	else
		// �Ϲ����� ���
		(*list)->tailNode->nextNode = newNode;

	(*list)->tailNode = newNode;
	(*list)->length++;

}

void SLL_Insert(linkedList_t** list, ELEMENT_TYPE newData, int index) {
	// Head�� null�� ���, �ε����� length-1�̻��� ���
	if ((*list)->headNode == NULL || index >= (*list)->length - 1) {
		SLL_Append(list, newData);
		return;
	}

	linkedListNode_t* newNode;
	LinkedList_Constructor(&newNode, newData);

	// �ε����� 0������ ���
	if (index <= 0) {
		newNode->nextNode = (*list)->headNode;
		(*list)->headNode = newNode;
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
	linkedListNode_t* currentNode = list->headNode;

	if (currentNode != NULL) {
		while (currentNode->nextNode != NULL && --index >= 0) {
			currentNode = currentNode->nextNode;
		}
	}

	return currentNode;
}

linkedListNode_t SLL_Delete(linkedList_t** list, int index) {
	// Head�� null�� ���
	if ((*list)->headNode == NULL)
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
			(*list)->headNode = (*list)->headNode->nextNode;
		}
		else {
			// �ε����� length-1�̻��� ���, �Ϲ����� ���
			linkedListNode_t* currentNode = SLL_Search((*list), index - 1);
			tempNode = currentNode->nextNode;
			currentNode->nextNode = tempNode->nextNode;
			(*list)->tailNode = currentNode;
		}
	}

	deletedNode = (*tempNode);
	LinkedList_Destructor(tempNode);
	(*list)->length--;
	
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