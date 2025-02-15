#ifndef RUNTIME_ERROR_H
#define RUNTIME_ERROR_H

#include <stdint.h>
#include <stdbool.h>

// 에러 코드 목록

// 정상 동작
#define OK					0b0
// 포인터가 없음
#define POINTER_IS_NULL		0b1
// 할당 실패
#define FAILED_ALLOCATION	0b10
// 해제 실패
#define FAILED_FREE			0b100
// 잘못된 동작
#define INVALID_OPERATION	0b1000
// 알 수 없는 오류
#define UNEXCEPTED_ERROR	0b10000000

/// <summary>
/// 에러 타입
/// </summary>
typedef uint8_t err_t;

/// <summary>
/// 에러 메시지 출력
/// </summary>
/// <param name="errorCode">에러 코드</param>
void runtimeError_printError(err_t errorCode);

#endif