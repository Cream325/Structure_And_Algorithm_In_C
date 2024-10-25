#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

/* ����, �ٸ� ������ Ÿ�Ե� �� �� �ְ� �ٲ� �ʿ䰡 ����. (C#�� �ڵ��帧�� �����ϱ� ����) */
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
/// <param name="node"></param>
/// <param name="newData"></param>
void LinkedList_Constructor(linkedListNode_t** node, ELEMENT_TYPE newData);

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
void SLL_Constructor(linkedList_t** list);

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

#pragma region DoublyLinkedList �Լ�

/// <summary>
/// ���� ��ũ�� ����Ʈ - ������
/// </summary>
/// <param name=""></param>
/// <returns></returns>
void DLL_Constructor(linkedList_t** list);

/// <summary>
/// ���� ��ũ�� ����Ʈ - �Ҹ���
/// </summary>
/// <param name="list"></param>
void DLL_Destructor(linkedList_t* list);

/// <summary>
/// ���� ��ũ�� ����Ʈ - ���� �߰�
/// </summary>
/// <param name="list"></param>
/// <param name="newData"></param>
void DLL_Append(linkedList_t** list, ELEMENT_TYPE newData);

/// <summary>
/// ���� ��ũ�� ����Ʈ - ���� ����
/// </summary>
/// <param name="list"></param>
/// <param name="newData"></param>
/// <param name="index"></param>
void DLL_Insert(linkedList_t** list, ELEMENT_TYPE newData, int index);

/// <summary>
/// ���� ��ũ�� ����Ʈ - ���� �˻�
/// </summary>
/// <param name="list"></param>
/// <param name="index"></param>
/// <returns>Node* currentNode</returns>
linkedListNode_t* DLL_Search(linkedList_t* list, int index);

/// <summary>
/// ���� ��ũ�� ����Ʈ - ���� ����
/// </summary>
/// <param name="list"></param>
/// <param name="index"></param>
linkedListNode_t DLL_Delete(linkedList_t** list, int index);

/// <summary>
/// ���� ��ũ�� ����Ʈ - ��ȸ
/// </summary>
/// <param name="list"></param>
void DLL_Traversal(linkedList_t* list);

#pragma endregion

#pragma region CircularLinkedList �Լ�

/// <summary>
/// ��ȯ ��ũ�� ����Ʈ - ������
/// </summary>
/// <returns></returns>
void CLL_Constructor(linkedList_t** list);

/// <summary>
/// ��ȯ ��ũ�� ����Ʈ - �Ҹ���
/// </summary>
/// <param name="list"></param>
void CLL_Destructor(linkedList_t* list);

/// <summary>
/// ��ȯ ��ũ�� ����Ʈ - ���� �߰�
/// </summary>
/// <param name="list"></param>
/// <param name="newData"></param>
void CLL_Append(linkedList_t** list, ELEMENT_TYPE newData);

/// <summary>
/// ��ȯ ��ũ�� ����Ʈ - ���� ����
/// </summary>
/// <param name="list"></param>
/// <param name="newData"></param>
/// <param name="index"></param>
void CLL_Insert(linkedList_t** list, ELEMENT_TYPE newData, int index);

/// <summary>
/// ��ȯ ��ũ�� ����Ʈ - ���� �˻�
/// </summary>
/// <param name="list"></param>
/// <param name="index"></param>
/// <returns></returns>
linkedListNode_t* CLL_Search(linkedList_t* list, int index);

/// <summary>
/// ��ȯ ��ũ�� ����Ʈ - ���� ����
/// </summary>
/// <param name="list"></param>
/// <param name="index"></param>
/// <returns></returns>
linkedListNode_t CLL_Delete(linkedList_t** list, int index);

/// <summary>
/// ��ȯ ��ũ�� ����Ʈ - ��ȸ
/// </summary>
/// <param name="list"></param>
void CLL_Traversal(linkedList_t* list);

#pragma endregion

#pragma endregion

#endif