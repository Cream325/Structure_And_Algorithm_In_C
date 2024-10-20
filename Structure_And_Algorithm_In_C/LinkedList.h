#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

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
/// <param name="newData"></param>
/// <returns>Node* newNode</returns>
linkedListNode_t* LinkedList_Constructor(ELEMENT_TYPE newData);

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
linkedList_t* SLL_Constructor(void);

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

// 이중 링크드 리스트 - 우선 주석처리
/* 
#pragma region DoublyLinkedList 함수

/// <summary>
/// 이중 링크드 리스트 - 단일 추가
/// </summary>
/// <param name="list"></param>
/// <param name="newData"></param>
void SLL_Append(Node** list, ElementType newData);

/// <summary>
/// 이중 링크드 리스트 - 단일 삽입
/// </summary>
/// <param name="list"></param>
/// <param name="newData"></param>
/// <param name="index"></param>
void DLL_Insert(Node** list, ElementType newData, int index);

/// <summary>
/// 이중 링크드 리스트 - 단일 검색
/// </summary>
/// <param name="list"></param>
/// <param name="index"></param>
/// <returns>Node* currentNode</returns>
Node* DLL_Search(Node* list, int index);

/// <summary>
/// 이중 링크드 리스트 - 단일 삭제
/// </summary>
/// <param name="list"></param>
/// <param name="index"></param>
void DLL_Delete(Node** list, int index);

/// <summary>
/// 이중 링크드 리스트 - 순회
/// </summary>
/// <param name="list"></param>
void DLL_Traversal(Node* list);

/// <summary>
/// 이중 링크드 리스트 - 리스트 길이
/// </summary>
/// <param name="list"></param>
/// <returns></returns>
int DLL_Length(Node* list);

#pragma endregion
*/

#pragma endregion

#endif