#ifndef CUSTOMSTACK_H
#define CUSTOMSTACK_H

#include "LinkedList.h"

int top;
int arrStackCapacity;

typedef struct stack_ {
	ELEMENT_TYPE data;
} arrayStack_t;

#pragma region ArrayStack 함수

/// <summary>
/// 배열 기반 스택 - 생성자
/// </summary>
/// <param name="capacity"></param>
/// <returns></returns>
arrayStack_t* ArrStack_Constructor(int capacity);

/// <summary>
/// 배열 기반 스택 - 소멸자
/// </summary>
/// <param name="stack"></param>
void ArrStack_Destructor(arrayStack_t* stack);

/// <summary>
/// 배열 기반 스택 - 단일 추가
/// </summary>
/// <param name="newData"></param>
void ArrStack_Push(arrayStack_t** stack, ELEMENT_TYPE newData);

/// <summary>
/// 배열 기반 스택 - 단일 검색
/// </summary>
/// <param name="stack"></param>
/// <returns></returns>
ELEMENT_TYPE ArrStack_Peek(arrayStack_t* stack);

/// <summary>
/// 배열 기반 스택 - 단일 제거
/// </summary>
/// <param name="stack"></param>
/// <returns></returns>
ELEMENT_TYPE ArrStack_Pop(arrayStack_t** stack);

int ArrStack_IsEmpty();

int ArrStack_IsFull();

#pragma endregion


#endif