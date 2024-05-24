#include <stdio.h>
#include "LinkedList.h"

int main(void) {
	Node* list = NULL;

	// 값 추가
	for (int i = 1; i <= 5; i++) {
		SLL_Append(&list, i);
	}

	// 특정 값 삽입
	SLL_Insert(&list, 10, 0);
	SLL_Insert(&list, 100, 3);
	/* 결과값 이상, 수정 필요
	SLL_Insert(&list, 10, 5); */

	// 특정 값 검색
	Node* searchedNode = SLL_Search(list, 0);
	printf("%d\n", searchedNode->Data);

	// 특정 값 삭제
	SLL_Delete(&list, 0);

	// 리스트 출력
	SLL_Traversal(list);

	return 0;
}