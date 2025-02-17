#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>

#include "runtimeError.h"

//노드의 데이터 타입
#define ELEMENT_TYPE int

/// <summary>
/// 연결 리스트 노드
/// </summary>
typedef struct _lnkListNode {
	/// <summary>
	/// 다음 노드
	/// </summary>
	struct _lnkListNode* next;

	/// <summary>
	/// 이전 노드
	/// </summary>
	struct _lnkListNode* previous;

	/// <summary>
	/// 노드 데이터
	/// </summary>
	ELEMENT_TYPE value;
} lnkListNode_t;

/// <summary>
/// 연결 리스트 노드 참조
/// </summary>
typedef lnkListNode_t* lnkListNodeRef_t;

/// <summary>
/// 연결 리스트
/// </summary>
typedef struct _lnkList {

	#pragma region Fields

	/// <summary>
	/// 헤드 노드
	/// </summary>
	lnkListNodeRef_t head;

	/// <summary>
	/// 테일 노드
	/// </summary>
	lnkListNodeRef_t tail;

	/// <summary>
	/// 길이
	/// </summary>
	size_t length;

	/// <summary>
	/// 힙 메모리 할당 여부
	/// </summary>
	bool isCreatedHeap;

	#pragma endregion

	#pragma region Function Pointers

	/// <summary>
	/// 단일 추가
	/// </summary>
	err_t(*append)(struct _lnkList*, ELEMENT_TYPE);

	/// <summary>
	/// 전체 추가
	/// </summary>
	err_t(*appendAll)(struct _lnkList*, ELEMENT_TYPE*, size_t);

	/// <summary>
	/// 단일 삽입
	/// </summary>
	err_t(*insert)(struct _lnkList*, ELEMENT_TYPE, int);

	/// <summary>
	/// 단일 검색
	/// </summary>
	err_t(*search)(lnkListNodeRef_t*, struct _lnkList*, int);

	/// <summary>
	/// 단일 삭제
	/// </summary>
	err_t(*remove)(lnkListNodeRef_t, struct _lnkList*, int);

	/// <summary>
	/// 초기화
	/// </summary>
	err_t(*clear)(struct _lnkList*);

	/// <summary>
	/// 순회
	/// </summary>
	err_t(*traversal)(struct _lnkList*);

	#pragma endregion

} lnkList_t;

/// <summary>
/// 연결 리스트 참조
/// </summary>
typedef lnkList_t* lnkListRef_t;

#pragma region linkedListNode

/// <summary>
/// 연결 리스트 노드 생성(스택 메모리)
/// </summary>
/// <param name="outNode"></param>
/// <param name="value"></param>
/// <returns></returns>
err_t linkedListNode_newStack(lnkListNodeRef_t outNode, ELEMENT_TYPE value);

/// <summary>
/// 연결 리스트 노드 생성(힙 메모리)
/// </summary>
/// <param name="outNode"></param>
/// <param name="value"></param>
/// <returns></returns>
err_t linkedListNode_newHeap(lnkListNodeRef_t* outNode, ELEMENT_TYPE value);

/// <summary>
/// 연결 리스트노드 해제
/// </summary>
/// <param name="refNode"></param>
err_t linkedListNode_delete(lnkListNodeRef_t refNode);

#pragma endregion

#pragma region linkedList

#pragma region singly linkedList

/// <summary>
/// 단일 연결 리스트 생성(스택 메모리)
/// </summary>
/// <param name="outList"></param>
/// <returns></returns>
err_t linkedList_singly_newStack(lnkListRef_t outList);

/// <summary>
/// 단일 연결 리스트 생성(힙 메모리)
/// </summary>
/// <param name="outList"></param>
/// <returns></returns>
err_t linkedList_singly_newHeap(lnkListRef_t* outList);

#pragma endregion

#pragma region doubly linkedList

/// <summary>
/// 이중 연결 리스트 생성(스택 메모리)
/// </summary>
/// <param name="outList"></param>
/// <returns></returns>
err_t linkedList_doubly_newStack(lnkListRef_t outList);

/// <summary>
/// 이중 연결 리스트 생성(힙 메모리)
/// </summary>
/// <param name="outList"></param>
/// <returns></returns>
err_t linkedList_doubly_newHeap(lnkListRef_t* outList);

#pragma endregion

#pragma region circular linkedList

/// <summary>
/// 원형 연결 리스트 생성(스택 메모리)
/// </summary>
/// <param name="outList"></param>
/// <returns></returns>
err_t linkedList_circular_newStack(lnkListRef_t outList);

/// <summary>
/// 원형 연결 리스트 생성(힙 메모리)
/// </summary>
/// <param name="outList"></param>
/// <returns></returns>
err_t linkedList_circular_newHeap(lnkListRef_t* outList);

#pragma endregion

/// <summary>
/// 연결 리스트 해제
/// </summary>
/// <param name="refList"></param>
/// <returns></returns>
err_t linkedList_delete(lnkListRef_t refList);

/// <summary>
/// 연결 리스트 - 순회
/// </summary>
/// <param name="refList"></param>
err_t linkedList_traversal(lnkListRef_t refList);

#pragma endregion

#endif