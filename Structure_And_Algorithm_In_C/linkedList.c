#include "linkedList.h"

#pragma region linkedListNode

/// <summary>
/// 연결 리스트 노드 생성자
/// </summary>
/// <param name="refNode"></param>
/// <param name="value"></param>
/// <returns></returns>
static err_t linkedListNode_constructor(lnkListNodeRef_t refNode, ELEMENT_TYPE value);

/// <summary>
/// 연결 리스트 노드 소멸자
/// </summary>
/// <param name="refNode"></param>
/// <returns></returns>
static err_t linkedListNode_destructor(lnkListNodeRef_t refNode);

#pragma region static functions

#pragma region constructor & destructor

static err_t linkedListNode_constructor(lnkListNodeRef_t refNode, ELEMENT_TYPE value) {
	refNode->next = NULL;
	refNode->previous = NULL;
	refNode->value = value;

	return OK;
}

static err_t linkedListNode_destructor(lnkListNodeRef_t refNode) {
	refNode->next = NULL;
	refNode->previous = NULL;

	return OK;
}

#pragma endregion

#pragma endregion

#pragma region public functions

err_t linkedListNode_newStack(lnkListNodeRef_t* outNode, ELEMENT_TYPE value) {
	if (outNode == NULL) {
		return POINTER_IS_NULL;
	}

	linkedListNode_constructor(outNode, value);
	return OK;
}

err_t linkedListNode_newHeap(lnkListNodeRef_t* outNode, ELEMENT_TYPE value) {
	if (outNode == NULL) {
		return POINTER_IS_NULL;
	}

	*outNode = malloc(sizeof(lnkListNode_t));
	if (*outNode == NULL) {
		return FAILED_ALLOCATION;
	}

	linkedListNode_newStack(*outNode, value);
	return OK;
}

err_t linkedListNode_delete(lnkListNodeRef_t refNode) {
	if (refNode == NULL) {
		return POINTER_IS_NULL;
	}

	linkedListNode_destructor(refNode);
	free(refNode);
	return OK;
}

#pragma endregion

#pragma endregion

#pragma region linkedList

/// <summary>
/// 연결 리스트 생성자
/// </summary>
/// <param name="refList"></param>
/// <returns></returns>
static err_t linkedList_constructor(lnkListRef_t refList);

/// <summary>
/// 연결 리스트 소멸자
/// </summary>
/// <param name="refList"></param>
/// <returns></returns>
static err_t linkedList_destructor(lnkListRef_t refList);

/// <summary>
/// 연결 리스트 - 단일 추가
/// </summary>
/// <param name="refList"></param>
/// <param name="value"></param>
/// <returns></returns>
static err_t linkedList_append(lnkListRef_t refList, ELEMENT_TYPE value);

/// <summary>
/// 연결 리스트 - 전체 추가
/// </summary>
/// <param name="refList"></param>
/// <param name="values"></param>
/// <param name="length"></param>
/// <returns></returns>
static err_t linkedList_appendAll(lnkListRef_t refList, ELEMENT_TYPE* values, size_t length);

/// <summary>
/// 연결 리스트 - 초기화
/// </summary>
/// <param name="refList"></param>
/// <returns></returns>
static err_t linkedList_clear(lnkListRef_t refList);

/// <summary>
/// 연결 리스트 - 순회
/// </summary>
/// <param name="refList"></param>
/// <returns></returns>
static err_t linkedList_traversal(lnkListRef_t refList);

#pragma region static functions

#pragma region constructor & destructor

static err_t linkedList_constructor(lnkListRef_t refList) {
	refList->head = NULL;
	refList->tail = NULL;
	refList->length = 0;
	refList->isCreatedHeap = false;

	refList->append = linkedList_append;
	refList->appendAll = linkedList_appendAll;
	refList->clear = linkedList_clear;
	refList->traversal = linkedList_traversal;

	return OK;
}

static err_t linkedList_destructor(lnkListRef_t refList) {
	refList->head = NULL;
	refList->tail = NULL;

	refList->append = NULL;
	refList->appendAll = NULL;
	refList->insert = NULL;
	refList->search = NULL;
	refList->remove = NULL;
	refList->clear = NULL;

	return OK;
}

#pragma endregion

#pragma region member functions

#pragma region common

static err_t linkedList_append(lnkListRef_t refList, ELEMENT_TYPE value) {
	if (refList == NULL) {
		return POINTER_IS_NULL;
	}

	return refList->insert(refList, value, refList->length - 1);
}

static err_t linkedList_appendAll(lnkListRef_t refList, ELEMENT_TYPE* values, size_t length) {
	if (refList == NULL) {
		return POINTER_IS_NULL;
	}

	err_t errorCode;
	for (size_t i = 0; i < length; i++) {
		errorCode = refList->append(refList, values[i]);
		if(errorCode) return errorCode;
	}

	return OK;
}

static err_t linkedList_clear(lnkListRef_t refList) {
	if (refList == NULL) {
		return POINTER_IS_NULL;
	}

	lnkListNode_t _;
	int length = refList->length - 1;
	for (int i = length; i >= 0; i--) {
		refList->remove(&_, refList, i);
	}

	return OK;
}

static err_t linkedList_traversal(lnkListRef_t refList) {
	if (refList == NULL) {
		return POINTER_IS_NULL;
	}
	else if (refList->head == NULL) {
		return INVALID_OPERATION;
	}

	lnkListNodeRef_t current = refList->head;
	do {
		printf("%d ", current->value);
		current = current->next;
	} while (current != refList->head && current != NULL);
	printf("\n");

	return OK;
}

#pragma endregion

#pragma region singly

/// <summary>
/// 단일 연결 리스트 - 단일 삽입
/// </summary>
/// <param name="refList"></param>
/// <param name="value"></param>
/// <param name="index"></param>
/// <returns></returns>
static err_t linkedList_singly_insert(lnkListRef_t refList, ELEMENT_TYPE value, int index) {
	if (refList == NULL) {
		return POINTER_IS_NULL;
	}

	lnkListNodeRef_t newNode;
	linkedListNode_newHeap(&newNode, value);

	if (refList->head == NULL) {
		// Head가 null인 경우
		refList->head = newNode;
		refList->tail = refList->head;
	}
	else {
		if (index == 0 && refList->length > 1) {
			// 인덱스가 0일 경우
			newNode->next = refList->head;
			refList->head = newNode;
		}
		else if (index == refList->length - 1) {
			// 인덱스가 length-1일 경우
			if (refList->head == refList->tail)
				refList->head->next = newNode;
			else
				refList->tail->next = newNode;

			refList->tail = newNode;
		}
		else {
			// 일반적인 경우
			lnkListNodeRef_t current;
			refList->search(&current, refList, index - 1);
			lnkListNodeRef_t temp = current->next;
			current->next = newNode;
			newNode->next = temp;
		}
	}

	refList->length++;
	return OK;
}

/// <summary>
/// 단일 연결 리스트 - 단일 검색
/// </summary>
/// <param name="outNode"></param>
/// <param name="refList"></param>
/// <param name="index"></param>
/// <returns></returns>
static err_t linkedList_singly_search(lnkListNodeRef_t* outNode, lnkListRef_t refList, int index) {
	if (refList == NULL) {
		return POINTER_IS_NULL;
	}
	else if (refList->head == NULL) {
		return INVALID_OPERATION;
	}

	lnkListNodeRef_t current = refList->head;
	while (current->next != NULL && --index >= 0) {
		current = current->next;
	}

	*outNode = current;
	return OK;
}

/// <summary>
/// 단일 연결 리스트 - 단일 삭제
/// </summary>
/// <param name="outNode"></param>
/// <param name="refList"></param>
/// <param name="index"></param>
/// <returns></returns>
static err_t linkedList_singly_remove(lnkListNodeRef_t outNode, lnkListRef_t refList, int index) {
	if (refList == NULL) {
		return POINTER_IS_NULL;
	}
	else if (refList->head == NULL) {
		return INVALID_OPERATION;
	}

	lnkListNodeRef_t temp;

	if (refList->head == refList->tail) {
		// Head와 Tail이 같은 경우
		temp = refList->head;
		refList->head = NULL;
		refList->tail = NULL;
	}
	else if (index == 0) {
		// 인덱스가 0인 경우
		temp = refList->head;
		refList->head = refList->head->next;
	}
	else {
		// 인덱스가 length-1일 경우, 일반적인 경우
		lnkListNodeRef_t current;
		refList->search(&current, refList, index - 1);
		temp = current->next;
		current->next = temp->next;
		refList->tail = current;
	}

	*outNode = *temp;
	linkedListNode_delete(temp);
	refList->length--;

	return OK;
}

#pragma endregion

#pragma region doubly

/// <summary>
/// 이중 연결 리스트 - 단일 삽입
/// </summary>
/// <param name="refList"></param>
/// <param name="value"></param>
/// <param name="index"></param>
/// <returns></returns>
static err_t linkedList_doubly_insert(lnkListRef_t refList, ELEMENT_TYPE value, int index) {
	if (refList == NULL) {
		return POINTER_IS_NULL;
	}

	lnkListNodeRef_t newNode;
	linkedListNode_newHeap(&newNode, value);

	if (refList->head == NULL) {
		// Head가 null인 경우
		refList->head = newNode;
		refList->tail = refList->head;
	}
	else {
		if (index == 0 && refList->length > 1) {
			// 인덱스가 0일 경우
			newNode->next = refList->head;
			refList->head->previous = newNode;
			refList->head = newNode;
		}
		else if (index == refList->length - 1) {
			// 인덱스가 length-1일 경우
			if (refList->head == refList->tail) {
				refList->head->next = newNode;
				newNode->previous = refList->head;
			}
			else {
				refList->tail->next = newNode;
				newNode->previous = refList->tail;
			}

			refList->tail = newNode;
		}
		else {
			// 일반적인 경우
			lnkListNodeRef_t current;
			refList->search(&current, refList, index);
			newNode->previous = current->previous;
			newNode->next = current;
			current->previous = newNode;
		}
	}

	refList->length++;
	return OK;
}

/// <summary>
/// 이중 연결 리스트 - 단일 검색
/// </summary>
/// <param name="outNode"></param>
/// <param name="refList"></param>
/// <param name="index"></param>
/// <returns></returns>
static err_t linkedList_doubly_search(lnkListNodeRef_t* outNode, lnkListRef_t refList, int index) {
	if (refList == NULL) {
		return POINTER_IS_NULL;
	}
	else if (refList->head == NULL) {
		return INVALID_OPERATION;
	}

	lnkListNodeRef_t current = refList->head;
	if (index <= refList->length / 2) {
		while (current->next != NULL && --index >= 0) {
			current = current->next;
		}
	}
	else {
		int maxIndex = refList->length - 1;
		current = refList->tail;
		while (current->previous != NULL && --maxIndex >= index) {
			current = current->previous;
		}
	}

	*outNode = current;
	return OK;
}

/// <summary>
/// 이중 연결 리스트 - 단일 삭제
/// </summary>
/// <param name="outNode"></param>
/// <param name="refList"></param>
/// <param name="index"></param>
/// <returns></returns>
static err_t linkedList_doubly_remove(lnkListNodeRef_t outNode, lnkListRef_t refList, int index) {
	if (refList == NULL) {
		return POINTER_IS_NULL;
	}
	else if (refList->head == NULL) {
		return INVALID_OPERATION;
	}

	lnkListNodeRef_t temp;

	if (refList->head == refList->tail) {
		// Head와 Tail이 같은 경우
		temp = refList->head;
		refList->head = NULL;
		refList->tail = NULL;
	}
	else if (index == 0) {
		// 인덱스가 0인 경우
		temp = refList->head;
		refList->head->next->previous = NULL;
		refList->head = refList->head->next;
	}
	else {
		// 인덱스가 length-1일 경우, 일반적인 경우
		lnkListNodeRef_t current;
		refList->search(&current, refList, index);
		temp = current;
		current->previous->next = current->next;

		if (index >= refList->length - 1)
			refList->tail = current->previous;
		else
			current->next->previous = current->previous;
	}

	*outNode = *temp;
	linkedListNode_delete(temp);
	refList->length--;

	return OK;
}

#pragma endregion

#pragma region circular

/// <summary>
/// 원형 연결 리스트 - 단일 삽입
/// </summary>
/// <param name="refList"></param>
/// <param name="value"></param>
/// <param name="index"></param>
/// <returns></returns>
static err_t linkedList_circular_insert(lnkListRef_t refList, ELEMENT_TYPE value, int index) {
	if (refList == NULL) {
		return POINTER_IS_NULL;
	}

	lnkListNodeRef_t newNode;
	linkedListNode_newHeap(&newNode, value);

	if (refList->head == NULL) {
		// Head가 null인 경우
		refList->head = newNode;
		refList->tail = refList->head;

		refList->head->next = refList->tail;
		refList->tail->previous = refList->head;
	}
	else {
		if (index == 0 && refList->length > 1) {
			// 인덱스가 0일 경우
			newNode->next = refList->head;
			refList->head->previous = newNode;
			refList->head = newNode;
		}
		else if (index == refList->length - 1) {
			// 인덱스가 length-1일 경우
			if (refList->head == refList->tail) {
				refList->head->next = newNode;
				newNode->previous = refList->head;
			}
			else {
				refList->tail->next = newNode;
				newNode->previous = refList->tail;
			}

			refList->tail = newNode;
		}
		else {
			// 일반적인 경우
			lnkListNodeRef_t current;
			refList->search(&current, refList, index);
			newNode->previous = current->previous;
			newNode->next = current;
			current->previous = newNode;
		}
	}

	refList->head->previous = refList->tail;
	refList->tail->next = refList->head;
	refList->length++;
	return OK;
}

/// <summary>
/// 원형 연결 리스트 - 단일 검색
/// </summary>
/// <param name="outNode"></param>
/// <param name="refList"></param>
/// <param name="index"></param>
/// <returns></returns>
static err_t linkedList_circular_search(lnkListNodeRef_t* outNode, lnkListRef_t refList, int index) {
	if (refList == NULL) {
		return POINTER_IS_NULL;
	}
	else if (refList->head == NULL) {
		return INVALID_OPERATION;
	}

	lnkListNodeRef_t current = refList->head;
	if (index <= refList->length / 2) {
		while (current->next != refList->head && --index >= 0) {
			current = current->next;
		}
	}
	else {
		int maxIndex = refList->length - 1;
		current = refList->tail;
		while (current->previous != refList->tail && --maxIndex >= index) {
			current = current->previous;
		}
	}

	*outNode = current;
	return OK;
}

/// <summary>
/// 원형 연결 리스트 - 단일 삭제
/// </summary>
/// <param name="outNode"></param>
/// <param name="refList"></param>
/// <param name="index"></param>
/// <returns></returns>
static err_t linkedList_circular_remove(lnkListNodeRef_t outNode, lnkListRef_t refList, int index) {
	if (refList == NULL) {
		return POINTER_IS_NULL;
	}
	else if (refList->head == NULL) {
		return INVALID_OPERATION;
	}

	lnkListNodeRef_t temp;

	if (refList->head == refList->tail) {
		// Head와 Tail이 같은 경우
		temp = refList->head;
		refList->head = NULL;
		refList->tail = NULL;
	}
	else if (index == 0) {
		// 인덱스가 0인 경우
		temp = refList->head;
		refList->head->next->previous = NULL;
		refList->head = refList->head->next;
	}
	else {
		// 인덱스가 length-1일 경우, 일반적인 경우
		lnkListNodeRef_t current;
		refList->search(&current, refList, index);
		temp = current;
		current->previous->next = current->next;

		if (index >= refList->length - 1)
			refList->tail = current->previous;
		else
			current->next->previous = current->previous;
	}

	refList->head->previous = refList->tail;
	refList->tail->next = refList->head;
	*outNode = *temp;
	linkedListNode_delete(temp);
	refList->length--;

	return OK;
}

#pragma endregion

#pragma endregion

#pragma endregion

#pragma region public functions

err_t linkedList_delete(lnkListRef_t refList) {
	if (refList == NULL) {
		return POINTER_IS_NULL;
	}

	linkedList_destructor(refList);
	if (refList->isCreatedHeap)
		free(refList);
	return OK;
}

#pragma region singly linkedList

err_t linkedList_singly_newStack(lnkListRef_t outList) {
	if (outList == NULL) {
		return POINTER_IS_NULL;
	}

	outList->insert = linkedList_singly_insert;
	outList->search = linkedList_singly_search;
	outList->remove = linkedList_singly_remove;

	linkedList_constructor(outList);
	return OK;
}

err_t linkedList_singly_newHeap(lnkListRef_t* outList) {
	if (outList == NULL) {
		return POINTER_IS_NULL;
	}

	*outList = malloc(sizeof(lnkList_t));
	if (*outList == NULL) {
		return FAILED_ALLOCATION;
	}

	linkedList_singly_newStack(*outList);
	(*outList)->isCreatedHeap = true;
	return OK;
}

#pragma endregion

#pragma region doubly linkedList

err_t linkedList_doubly_newStack(lnkListRef_t outList) {
	if (outList == NULL) {
		return POINTER_IS_NULL;
	}

	outList->insert = linkedList_doubly_insert;
	outList->search = linkedList_doubly_search;
	outList->remove = linkedList_doubly_remove;

	linkedList_constructor(outList);
	return OK;
}

err_t linkedList_doubly_newHeap(lnkListRef_t* outList) {
	if (outList == NULL) {
		return POINTER_IS_NULL;
	}

	*outList = malloc(sizeof(lnkList_t));
	if (*outList == NULL) {
		return FAILED_ALLOCATION;
	}

	linkedList_doubly_newStack(*outList);
	(*outList)->isCreatedHeap = true;
	return OK;
}

#pragma endregion

#pragma region circular linkedList

err_t linkedList_circular_newStack(lnkListRef_t outList) {
	if (outList == NULL) {
		return POINTER_IS_NULL;
	}

	outList->insert = linkedList_circular_insert;
	outList->search = linkedList_circular_search;
	outList->remove = linkedList_circular_remove;

	linkedList_constructor(outList);
	return OK;
}

err_t linkedList_circular_newHeap(lnkListRef_t* outList) {
	if (outList == NULL) {
		return POINTER_IS_NULL;
	}

	*outList = malloc(sizeof(lnkList_t));
	if (*outList == NULL) {
		return FAILED_ALLOCATION;
	}

	linkedList_circular_newStack(*outList);
	(*outList)->isCreatedHeap = true;
	return OK;
}

#pragma endregion

#pragma endregion

#pragma endregion