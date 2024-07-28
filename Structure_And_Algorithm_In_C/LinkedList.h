#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode {
	ElementType Data;
	struct tagNode* NextNode;
	struct tagNode* PreviousNode;
} Node;

#pragma region 함수 선언

#pragma region 노드 함수
/// <summary>
/// 노드 생성
/// </summary>
/// <param name="newData"></param>
/// <returns>Node* newNode</returns>
Node* SLL_CreateNode(ElementType newData);

/// <summary>
/// 노드 소멸
/// </summary>
/// <param name="node"></param>
void SLL_DestroyNode(Node* node);
#pragma endregion

#pragma region SinglyLinkedList 함수

/// <summary>
/// 단순 링크드 리스트 - 단일 추가
/// </summary>
/// <param name="list"></param>
/// <param name="newData"></param>
void SLL_Append(Node** list, ElementType newData);

/// <summary>
/// 단순 링크드 리스트 - 단일 삽입
/// </summary>
/// <param name="list"></param>
/// <param name="newData"></param>
/// <param name="index"></param>
void SLL_Insert(Node** list, ElementType newData, int index);

/// <summary>
/// 단순 링크드 리스트 - 단일 검색
/// </summary>
/// <param name="list"></param>
/// <param name="index"></param>
/// <returns>Node* currentNode</returns>
Node* SLL_Search(Node* list, int index);

/// <summary>
/// 단순 링크드 리스트 - 단일 삭제
/// </summary>
/// <param name="list"></param>
/// <param name="index"></param>
void SLL_Delete(Node** list, int index);

/// <summary>
/// 단순 링크드 리스트 - 순회
/// </summary>
/// <param name="list"></param>
void SLL_Traversal(Node* list);

/// <summary>
/// 단순 링크드 리스트 - 리스트 길이
/// </summary>
/// <param name="list"></param>
/// <returns></returns>
int SLL_Length(Node* list);

#pragma endregion

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

#pragma endregion


#endif
