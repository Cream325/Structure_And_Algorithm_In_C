#include "RuntimeError.h"

runtimeError_t create_runtimeError(errorCode_t code, const char* errorMessage) {
	runtimeError_t error;
	error.code = code;
	error.errorMessage = errorMessage;

	return error;
}