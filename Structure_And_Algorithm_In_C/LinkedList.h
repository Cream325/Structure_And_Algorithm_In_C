#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

/* 추후, 다른 데이터 타입도 들어갈 수 있게 바꿀 필요가 있음. (C#과 코드흐름을 같이하기 위함) */
//노드의 데이터 타입
#define ELEMENT_TYPE int

/// <summary>
/// 링크드 리스트 노드 구조체
/// </summary>
typedef struct linkedListNode_ {
	ELEMENT_TYPE data;
	struct linkedListNode_* nextNode;
	struct linkedListNode_* previousNode;
} linkedListNode_t;

/// <summary>
/// 링크드 리스트 구조체
/// </summary>
typedef struct linkedList_ {
	linkedListNode_t* headNode;
	linkedListNode_t* tailNode;
	int length;
} linkedList_t;

#pragma region 함수 선언

#pragma region 노드 함수
/// <summary>
/// 노드 생성
/// </summary>
/// <param name="node"></param>
/// <param name="newData"></param>
void LinkedList_Constructor(linkedListNode_t** node, ELEMENT_TYPE newData);

/// <summary>
/// 노드 소멸
/// </summary>
/// <param name="node"></param>
void LinkedList_Destructor(linkedListNode_t* node);
#pragma endregion

#pragma region SinglyLinkedList 함수

/// <summary>
/// 단일 링크드 리스트 - 생성자
/// </summary>
void SLL_Constructor(linkedList_t** list);

/// <summary>
/// 단일 링크드 리스트 - 소멸자
/// </summary>
/// <param name="list"></param>
void SLL_Destructor(linkedList_t* list);

/// <summary>
/// 단일 링크드 리스트 - 단일 추가
/// </summary>
/// <param name="list"></param>
/// <param name="newData"></param>
void SLL_Append(linkedList_t** list, ELEMENT_TYPE newData);

/// <summary>
/// 단일 링크드 리스트 - 단일 삽입
/// </summary>
/// <param name="list"></param>
/// <param name="newData"></param>
/// <param name="index"></param>
void SLL_Insert(linkedList_t** list, ELEMENT_TYPE newData, int index);

/// <summary>
/// 단일 링크드 리스트 - 단일 검색
/// </summary>
/// <param name="list"></param>
/// <param name="index"></param>
/// <returns>Node* currentNode</returns>
linkedListNode_t* SLL_Search(linkedList_t* list, int index);

/// <summary>
/// 단일 링크드 리스트 - 단일 삭제
/// </summary>
/// <param name="list"></param>
/// <param name="index"></param>
linkedListNode_t SLL_Delete(linkedList_t** list, int index);

/// <summary>
/// 단일 링크드 리스트 - 순회
/// </summary>
/// <param name="list"></param>
void SLL_Traversal(linkedList_t* list);

#pragma endregion

#pragma region DoublyLinkedList 함수

/// <summary>
/// 이중 링크드 리스트 - 생성자
/// </summary>
/// <param name=""></param>
/// <returns></returns>
void DLL_Constructor(linkedList_t** list);

/// <summary>
/// 이중 링크드 리스트 - 소멸자
/// </summary>
/// <param name="list"></param>
void DLL_Destructor(linkedList_t* list);

/// <summary>
/// 이중 링크드 리스트 - 단일 추가
/// </summary>
/// <param name="list"></param>
/// <param name="newData"></param>
void DLL_Append(linkedList_t** list, ELEMENT_TYPE newData);

/// <summary>
/// 이중 링크드 리스트 - 단일 삽입
/// </summary>
/// <param name="list"></param>
/// <param name="newData"></param>
/// <param name="index"></param>
void DLL_Insert(linkedList_t** list, ELEMENT_TYPE newData, int index);

/// <summary>
/// 이중 링크드 리스트 - 단일 검색
/// </summary>
/// <param name="list"></param>
/// <param name="index"></param>
/// <returns>Node* currentNode</returns>
linkedListNode_t* DLL_Search(linkedList_t* list, int index);

/// <summary>
/// 이중 링크드 리스트 - 단일 삭제
/// </summary>
/// <param name="list"></param>
/// <param name="index"></param>
linkedListNode_t DLL_Delete(linkedList_t** list, int index);

/// <summary>
/// 이중 링크드 리스트 - 순회
/// </summary>
/// <param name="list"></param>
void DLL_Traversal(linkedList_t* list);

#pragma endregion

#pragma region CircularLinkedList 함수

/// <summary>
/// 순환 링크드 리스트 - 생성자
/// </summary>
/// <returns></returns>
void CLL_Constructor(linkedList_t** list);

/// <summary>
/// 순환 링크드 리스트 - 소멸자
/// </summary>
/// <param name="list"></param>
void CLL_Destructor(linkedList_t* list);

/// <summary>
/// 순환 링크드 리스트 - 단일 추가
/// </summary>
/// <param name="list"></param>
/// <param name="newData"></param>
void CLL_Append(linkedList_t** list, ELEMENT_TYPE newData);

/// <summary>
/// 순환 링크드 리스트 - 단일 삽입
/// </summary>
/// <param name="list"></param>
/// <param name="newData"></param>
/// <param name="index"></param>
void CLL_Insert(linkedList_t** list, ELEMENT_TYPE newData, int index);

/// <summary>
/// 순환 링크드 리스트 - 단일 검색
/// </summary>
/// <param name="list"></param>
/// <param name="index"></param>
/// <returns></returns>
linkedListNode_t* CLL_Search(linkedList_t* list, int index);

/// <summary>
/// 순환 링크드 리스트 - 단일 삭제
/// </summary>
/// <param name="list"></param>
/// <param name="index"></param>
/// <returns></returns>
linkedListNode_t CLL_Delete(linkedList_t** list, int index);

/// <summary>
/// 순환 링크드 리스트 - 순회
/// </summary>
/// <param name="list"></param>
void CLL_Traversal(linkedList_t* list);

#pragma endregion

#pragma endregion

#endif