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

#pragma region �Լ� ����

#pragma region ��� �Լ�
/// <summary>
/// ��� ����
/// </summary>
/// <param name="newData"></param>
/// <returns>Node* newNode</returns>
Node* SLL_CreateNode(ElementType newData);

/// <summary>
/// ��� �Ҹ�
/// </summary>
/// <param name="node"></param>
void SLL_DestroyNode(Node* node);
#pragma endregion

#pragma region SinglyLinkedList �Լ�

/// <summary>
/// �ܼ� ��ũ�� ����Ʈ - ���� �߰�
/// </summary>
/// <param name="list"></param>
/// <param name="newData"></param>
void SLL_Append(Node** list, ElementType newData);

/// <summary>
/// �ܼ� ��ũ�� ����Ʈ - ���� ����
/// </summary>
/// <param name="list"></param>
/// <param name="newData"></param>
/// <param name="index"></param>
void SLL_Insert(Node** list, ElementType newData, int index);

/// <summary>
/// �ܼ� ��ũ�� ����Ʈ - ���� �˻�
/// </summary>
/// <param name="list"></param>
/// <param name="index"></param>
/// <returns>Node* currentNode</returns>
Node* SLL_Search(Node* list, int index);

/// <summary>
/// �ܼ� ��ũ�� ����Ʈ - ���� ����
/// </summary>
/// <param name="list"></param>
/// <param name="index"></param>
void SLL_Delete(Node** list, int index);

/// <summary>
/// �ܼ� ��ũ�� ����Ʈ - ��ȸ
/// </summary>
/// <param name="list"></param>
void SLL_Traversal(Node* list);

/// <summary>
/// �ܼ� ��ũ�� ����Ʈ - ����Ʈ ����
/// </summary>
/// <param name="list"></param>
/// <returns></returns>
int SLL_Length(Node* list);

#pragma endregion

#pragma region DoublyLinkedList �Լ�

/// <summary>
/// ���� ��ũ�� ����Ʈ - ���� �߰�
/// </summary>
/// <param name="list"></param>
/// <param name="newData"></param>
void SLL_Append(Node** list, ElementType newData);

/// <summary>
/// ���� ��ũ�� ����Ʈ - ���� ����
/// </summary>
/// <param name="list"></param>
/// <param name="newData"></param>
/// <param name="index"></param>
void DLL_Insert(Node** list, ElementType newData, int index);

/// <summary>
/// ���� ��ũ�� ����Ʈ - ���� �˻�
/// </summary>
/// <param name="list"></param>
/// <param name="index"></param>
/// <returns>Node* currentNode</returns>
Node* DLL_Search(Node* list, int index);

/// <summary>
/// ���� ��ũ�� ����Ʈ - ���� ����
/// </summary>
/// <param name="list"></param>
/// <param name="index"></param>
void DLL_Delete(Node** list, int index);

/// <summary>
/// ���� ��ũ�� ����Ʈ - ��ȸ
/// </summary>
/// <param name="list"></param>
void DLL_Traversal(Node* list);

/// <summary>
/// ���� ��ũ�� ����Ʈ - ����Ʈ ����
/// </summary>
/// <param name="list"></param>
/// <returns></returns>
int DLL_Length(Node* list);

#pragma endregion

#pragma endregion


#endif
