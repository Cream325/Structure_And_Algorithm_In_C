#ifndef RUNTIME_ERROR_H
#define RUNTIME_ERROR_H

#include <stdint.h>
#include <stdbool.h>

// ���� �ڵ� ���

// ���� ����
#define OK					0b0
// �����Ͱ� ����
#define POINTER_IS_NULL		0b1
// �Ҵ� ����
#define FAILED_ALLOCATION	0b10
// ���� ����
#define FAILED_FREE			0b100
// �߸��� ����
#define INVALID_OPERATION	0b1000
// �� �� ���� ����
#define UNEXCEPTED_ERROR	0b10000000

/// <summary>
/// ���� Ÿ��
/// </summary>
typedef uint8_t err_t;

/// <summary>
/// ���� �޽��� ���
/// </summary>
/// <param name="errorCode">���� �ڵ�</param>
void runtimeError_printError(err_t errorCode);

#endif