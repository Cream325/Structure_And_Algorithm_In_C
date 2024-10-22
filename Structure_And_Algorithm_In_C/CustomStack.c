#include "CustomStack.h"

#pragma region ArrayStack ÇÔ¼ö

arrayStack_t* ArrStack_Constructor(int capacity) {
	arrStackCapacity = capacity;
	arrayStack_t* newStack = (arrayStack_t*)malloc(sizeof(arrayStack_t) * capacity);

	newStack->data = NULL;
	top = 0;

	return newStack;
}

void ArrStack_Destructor(arrayStack_t* stack) {
	while (ArrStack_Pop(&stack) != NULL);
	free(stack);
}

void ArrStack_Push(arrayStack_t** stack, ELEMENT_TYPE newData) {
	if (!ArrStack_IsFull()) {
		(*stack)[top++].data = newData;
	}
}

ELEMENT_TYPE ArrStack_Peek(arrayStack_t* stack) {
	if (!ArrStack_IsEmpty()) {
		return stack[top].data;
	}

	return NULL;
}

ELEMENT_TYPE ArrStack_Pop(arrayStack_t** stack) {
	if (!ArrStack_IsEmpty()) {
		return (*stack)[top--].data;
	}

	return NULL;
}

int ArrStack_IsEmpty() {
	return top <= 0;
}

int ArrStack_IsFull() {
	return top >= arrStackCapacity;
}

#pragma endregion
