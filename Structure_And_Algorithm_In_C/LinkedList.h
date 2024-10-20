#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

//����� ������ Ÿ��
#define ELEMENT_TYPE int

/// <summary>
/// ��ũ�� ����Ʈ ��� ����ü
/// </summary>
typedef struct linkedListNode_ {
	ELEMENT_TYPE data;
	struct linkedListNode_* nextNode;
	struct linkedListNode_* previousNode;
} linkedListNode_t;

/// <summary>
/// ��ũ�� ����Ʈ ����ü
/// </summary>
typedef struct linkedList_ {
	linkedListNode_t* headNode;
	linkedListNode_t* tailNode;
	int length;
} linkedList_t;

#pragma region �Լ� ����

#pragma region ��� �Լ�
/// <summary>
/// ��� ����
/// </summary>
/// <param name="newData"></param>
/// <returns>Node* newNode</returns>
linkedListNode_t* LinkedList_Constructor(ELEMENT_TYPE newData);

/// <summary>
/// ��� �Ҹ�
/// </summary>
/// <param name="node"></param>
void LinkedList_Destructor(linkedListNode_t* node);
#pragma endregion

#pragma region SinglyLinkedList �Լ�

/// <summary>
/// ���� ��ũ�� ����Ʈ - ������
/// </summary>
linkedList_t* SLL_Constructor(void);

/// <summary>
/// ���� ��ũ�� ����Ʈ - �Ҹ���
/// </summary>
/// <param name="list"></param>
void SLL_Destructor(linkedList_t* list);

/// <summary>
/// ���� ��ũ�� ����Ʈ - ���� �߰�
/// </summary>
/// <param name="list"></param>
/// <param name="newData"></param>
void SLL_Append(linkedList_t** list, ELEMENT_TYPE newData);

/// <summary>
/// ���� ��ũ�� ����Ʈ - ���� ����
/// </summary>
/// <param name="list"></param>
/// <param name="newData"></param>
/// <param name="index"></param>
void SLL_Insert(linkedList_t** list, ELEMENT_TYPE newData, int index);

/// <summary>
/// ���� ��ũ�� ����Ʈ - ���� �˻�
/// </summary>
/// <param name="list"></param>
/// <param name="index"></param>
/// <returns>Node* currentNode</returns>
linkedListNode_t* SLL_Search(linkedList_t* list, int index);

/// <summary>
/// ���� ��ũ�� ����Ʈ - ���� ����
/// </summary>
/// <param name="list"></param>
/// <param name="index"></param>
linkedListNode_t SLL_Delete(linkedList_t** list, int index);

/// <summary>
/// ���� ��ũ�� ����Ʈ - ��ȸ
/// </summary>
/// <param name="list"></param>
void SLL_Traversal(linkedList_t* list);

#pragma endregion

// ���� ��ũ�� ����Ʈ - �켱 �ּ�ó��
/* 
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
*/

#pragma endregion

#endif