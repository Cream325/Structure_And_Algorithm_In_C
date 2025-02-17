#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>

#include "runtimeError.h"

//����� ������ Ÿ��
#define ELEMENT_TYPE int

/// <summary>
/// ���� ����Ʈ ���
/// </summary>
typedef struct _lnkListNode {
	/// <summary>
	/// ���� ���
	/// </summary>
	struct _lnkListNode* next;

	/// <summary>
	/// ���� ���
	/// </summary>
	struct _lnkListNode* previous;

	/// <summary>
	/// ��� ������
	/// </summary>
	ELEMENT_TYPE value;
} lnkListNode_t;

/// <summary>
/// ���� ����Ʈ ��� ����
/// </summary>
typedef lnkListNode_t* lnkListNodeRef_t;

/// <summary>
/// ���� ����Ʈ
/// </summary>
typedef struct _lnkList {

	#pragma region Fields

	/// <summary>
	/// ��� ���
	/// </summary>
	lnkListNodeRef_t head;

	/// <summary>
	/// ���� ���
	/// </summary>
	lnkListNodeRef_t tail;

	/// <summary>
	/// ����
	/// </summary>
	size_t length;

	/// <summary>
	/// �� �޸� �Ҵ� ����
	/// </summary>
	bool isCreatedHeap;

	#pragma endregion

	#pragma region Function Pointers

	/// <summary>
	/// ���� �߰�
	/// </summary>
	err_t(*append)(struct _lnkList*, ELEMENT_TYPE);

	/// <summary>
	/// ��ü �߰�
	/// </summary>
	err_t(*appendAll)(struct _lnkList*, ELEMENT_TYPE*, size_t);

	/// <summary>
	/// ���� ����
	/// </summary>
	err_t(*insert)(struct _lnkList*, ELEMENT_TYPE, int);

	/// <summary>
	/// ���� �˻�
	/// </summary>
	err_t(*search)(lnkListNodeRef_t*, struct _lnkList*, int);

	/// <summary>
	/// ���� ����
	/// </summary>
	err_t(*remove)(lnkListNodeRef_t, struct _lnkList*, int);

	/// <summary>
	/// �ʱ�ȭ
	/// </summary>
	err_t(*clear)(struct _lnkList*);

	/// <summary>
	/// ��ȸ
	/// </summary>
	err_t(*traversal)(struct _lnkList*);

	#pragma endregion

} lnkList_t;

/// <summary>
/// ���� ����Ʈ ����
/// </summary>
typedef lnkList_t* lnkListRef_t;

#pragma region linkedListNode

/// <summary>
/// ���� ����Ʈ ��� ����(���� �޸�)
/// </summary>
/// <param name="outNode"></param>
/// <param name="value"></param>
/// <returns></returns>
err_t linkedListNode_newStack(lnkListNodeRef_t outNode, ELEMENT_TYPE value);

/// <summary>
/// ���� ����Ʈ ��� ����(�� �޸�)
/// </summary>
/// <param name="outNode"></param>
/// <param name="value"></param>
/// <returns></returns>
err_t linkedListNode_newHeap(lnkListNodeRef_t* outNode, ELEMENT_TYPE value);

/// <summary>
/// ���� ����Ʈ��� ����
/// </summary>
/// <param name="refNode"></param>
err_t linkedListNode_delete(lnkListNodeRef_t refNode);

#pragma endregion

#pragma region linkedList

#pragma region singly linkedList

/// <summary>
/// ���� ���� ����Ʈ ����(���� �޸�)
/// </summary>
/// <param name="outList"></param>
/// <returns></returns>
err_t linkedList_singly_newStack(lnkListRef_t outList);

/// <summary>
/// ���� ���� ����Ʈ ����(�� �޸�)
/// </summary>
/// <param name="outList"></param>
/// <returns></returns>
err_t linkedList_singly_newHeap(lnkListRef_t* outList);

#pragma endregion

#pragma region doubly linkedList

/// <summary>
/// ���� ���� ����Ʈ ����(���� �޸�)
/// </summary>
/// <param name="outList"></param>
/// <returns></returns>
err_t linkedList_doubly_newStack(lnkListRef_t outList);

/// <summary>
/// ���� ���� ����Ʈ ����(�� �޸�)
/// </summary>
/// <param name="outList"></param>
/// <returns></returns>
err_t linkedList_doubly_newHeap(lnkListRef_t* outList);

#pragma endregion

#pragma region circular linkedList

/// <summary>
/// ���� ���� ����Ʈ ����(���� �޸�)
/// </summary>
/// <param name="outList"></param>
/// <returns></returns>
err_t linkedList_circular_newStack(lnkListRef_t outList);

/// <summary>
/// ���� ���� ����Ʈ ����(�� �޸�)
/// </summary>
/// <param name="outList"></param>
/// <returns></returns>
err_t linkedList_circular_newHeap(lnkListRef_t* outList);

#pragma endregion

/// <summary>
/// ���� ����Ʈ ����
/// </summary>
/// <param name="refList"></param>
/// <returns></returns>
err_t linkedList_delete(lnkListRef_t refList);

/// <summary>
/// ���� ����Ʈ - ��ȸ
/// </summary>
/// <param name="refList"></param>
err_t linkedList_traversal(lnkListRef_t refList);

#pragma endregion

#endif