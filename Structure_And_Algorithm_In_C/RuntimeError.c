#include "RuntimeError.h"

#include <stdio.h>

void runtimeError_printError(err_t errorCode) {
	if (!errorCode)
		printf("ErrorMessage: Ok.");

	else {
		// Null Pointer
		if (errorCode & POINTER_IS_NULL != 0)
			printf("ErrorMessage: Pointer is null.");
		// Failed Allocation
		else if (errorCode & FAILED_ALLOCATION != 0)
			printf("ErrorMessage: Memory allocation is failed.");
		// Failed Free
		else if (errorCode & FAILED_FREE != 0)
			printf("ErrorMessage: Memory free is failed.");
		// Invalid Operation
		else if (errorCode & INVALID_OPERATION != 0)
			printf("ErrorMessage: Operation is invalid.");
		// Unexcepted Error
		else
			printf("ErrorMessage: Unexcepted error.");
	}
}