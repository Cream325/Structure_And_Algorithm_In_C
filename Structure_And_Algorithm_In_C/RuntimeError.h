#ifndef RUNTIME_ERROR_H
#define RUNTIME_ERROR_H

#include <stdio.h>

typedef enum {
	Ok = 0,
	NullOfHeader = 1000,
	UnderflowedIndex = 1001,
	OverflowedIndex = 1002,
	EmptyOfStack = 2001,
	FullOfStack = 2002,
	EmptyOfQueue = 2003,
	FullOfQueue = 2004
} errorCode_t;

typedef struct {
	errorCode_t code;
	const char* errorMessage;
} runtimeError_t;

runtimeError_t create_runtimeError(errorCode_t code, const char* errorMessage);

#endif