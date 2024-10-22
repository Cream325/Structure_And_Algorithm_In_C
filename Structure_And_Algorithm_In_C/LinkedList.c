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
		(*list)->tailNode = newNode;
	}
	else {
		// ��� ������尡 null�� ���, �Ϲ����� ���
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

	linkedListNode_t* newNode = LinkedList_Constructor(newData);

	// �ε����� 0 ������ ���
	if (index <= 0) {
		newNode->nextNode = (*list)->headNode;
		(*list)->headNode = newNode;
		(*list)->length++;
		return;
	}

	// �ε����� ����Ʈ �ִ� �ε��� �̻��� ��� (Append�� ������ ����)
	if (index >= (*list)->length - 1) {
		SLL_Append(list, newData);
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
			tempNode->nextNode = NULL;
			LinkedList_Destructor(tempNode);
		}
		else {
			// �߰����, ������ ������ ���
			index = index >= (*list)->length ? (*list)->length - 1 : index;
			linkedListNode_t* currentNode = SLL_Search(*list, index - 1);
			linkedListNode_t* tempNode = currentNode->nextNode;
			deletedNode = *tempNode;
			currentNode->nextNode = tempNode->nextNode;
			tempNode->nextNode = NULL;

			// ������ ������ ��, ������ ��ġ�� ����
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

#pragma region DoublyLinkedList �Լ�

linkedList_t* DLL_Constructor() {
	// ���� ��ũ�� ����Ʈ ���� �Ҵ�
	linkedList_t* newList = (linkedList_t*)malloc(sizeof(linkedList_t));

	// ��ũ�� ����Ʈ ������ ����
	newList->headNode = NULL;
	newList->tailNode = NULL;
	newList->length = 0;

	//printf("DLL is Created\n");

	return newList;
}

void DLL_Destructor(linkedList_t* list) {
	for (int i = list->length - 1; i >= 0; i--) {
		DLL_Delete(&list, i);
	}

	free(list);
	//printf("DLL is Deleted\n");
}

void DLL_Append(linkedList_t** list, ELEMENT_TYPE newData) {
	linkedListNode_t* newNode = LinkedList_Constructor(newData);

	// ��尡 null�� ���
	if ((*list)->headNode == NULL) {
		(*list)->headNode = newNode;
		(*list)->tailNode = (*list)->headNode;
	}
	else {
		//����� ������尡 null�� ���, �Ϲ����� ���
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
	// ��尡 null�� ���
	if ((*list)->headNode == NULL) {
		DLL_Append(list, newData);
		return;
	}

	linkedListNode_t* newNode = LinkedList_Constructor(newData);

	// �ε����� 0 ������ ���
	if (index <= 0) {
		newNode->nextNode = (*list)->headNode;
		(*list)->headNode->previousNode = newNode;
		(*list)->headNode = newNode;
		(*list)->length++;
		return;
	}
	
	// �ε����� ����Ʈ �ִ� �ε��� �̻��� ��� (Append�� ������ ����)
	if (index >= (*list)->length - 1) {
		DLL_Append(list, newData);
		return;
	}

	// �Ϲ����� ���
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
		// ��带 ������ ���
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

			// �߰���带 ������ ���
			if (currentNode->nextNode != NULL) {
				currentNode->previousNode->nextNode = currentNode->nextNode;
				currentNode->nextNode->previousNode = currentNode->previousNode;
			}
			else {
				// ������ ������ ���
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

#pragma region CircularLinkedList �Լ�

linkedList_t* CLL_Constructor(void) {
	// ��ȯ ��ũ�� ����Ʈ ���� �Ҵ�
	linkedList_t* newList = (linkedList_t*)malloc(sizeof(linkedList_t));

	// ��ũ�� ����Ʈ ������ ����
	newList->headNode = NULL;
	newList->tailNode = NULL;
	newList->length = 0;

	return newList;
}

void CLL_Destructor(linkedList_t* list) {
	for (int i = list->length - 1; i >= 0; i--) {
		CLL_Delete(&list, i);
	}

	free(list);
}

void CLL_Append(linkedList_t** list, ELEMENT_TYPE newData) {
	linkedListNode_t* newNode = LinkedList_Constructor(newData);

	// ��尡 null�� ���
	if ((*list)->headNode == NULL) {
		(*list)->headNode = newNode;
		(*list)->tailNode = (*list)->headNode;

		(*list)->headNode->nextNode = (*list)->tailNode;
		(*list)->tailNode->previousNode = (*list)->headNode;
	}
	else {
		// �Ϲ����� ���
		(*list)->tailNode->nextNode = newNode;
		newNode->previousNode = (*list)->tailNode;
		(*list)->tailNode = (*list)->tailNode->nextNode;
	}

	(*list)->headNode->previousNode = (*list)->tailNode;
	(*list)->tailNode->nextNode = (*list)->headNode;
	(*list)->length++;
}

// ���Կ� ������ ����. �����ʿ�
void CLL_Insert(linkedList_t** list, ELEMENT_TYPE newData, int index) {
	// ��尡 null�� ���
	if ((*list)->headNode == NULL) {
		CLL_Append(list, newData);
		return;
	}

	linkedListNode_t* newNode = LinkedList_Constructor(newData);

	// ��� ������尡 null�� ���, �ε����� 0������ ���
	if ((*list)->headNode->nextNode == NULL || index <= 0) {
		newNode->nextNode = (*list)->headNode;
		(*list)->headNode->previousNode = newNode;
		(*list)->headNode = newNode;
		(*list)->length++;
		return;
	}

	// �ε����� ����Ʈ �ִ� �ε��� �̻��� ��� (Append�� ������ ����)
	if (index >= (*list)->length - 1) {
		(*list)->tailNode->nextNode = newNode;
		newNode->previousNode = (*list)->tailNode;
		(*list)->tailNode = newNode;

		(*list)->tailNode->nextNode = (*list)->headNode;
		(*list)->headNode->previousNode = (*list)->tailNode;
		(*list)->length++;
		return;
	}

	// �Ϲ����� ���
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

linkedListNode_t CLL_Delete(linkedList_t** list, int index) {
	linkedListNode_t deletedNode;

	if ((*list)->headNode != NULL) {
		// ��带 ������ ���
		if ((*list)->headNode->nextNode == (*list)->tailNode || index <= 0) {
			linkedListNode_t* tempNode = (*list)->headNode;
			deletedNode = *tempNode;
			(*list)->tailNode->previousNode = (*list)->headNode->nextNode;
			(*list)->headNode = (*list)->headNode->nextNode;
			LinkedList_Destructor(tempNode);
		}
		else {
			index = index >= (*list)->length ? (*list)->length - 1 : index;
			linkedListNode_t* currentNode = CLL_Search(*list, index);

			// �߰���带 ������ ���
			if (currentNode->nextNode != NULL) {
				currentNode->previousNode->nextNode = currentNode->nextNode;
				currentNode->nextNode->previousNode = currentNode->previousNode;
			}
			else {
				// ������ ������ ���
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
