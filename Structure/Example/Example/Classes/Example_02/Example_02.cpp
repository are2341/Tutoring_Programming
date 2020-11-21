#include "Example_02.h"
#include "../Global/Utility/Structure/CLinkedList.h"

namespace EXAMPLE_02 {
	//! 연결 리스트를 초기화한다
	void InitLinkedList(CLinkedList<int> &a_rValueList, int a_nNumValues) {
		for(int i = 0; i < a_nNumValues; ++i) {
			a_rValueList.addValue(i + 1);
		}
	}

	//! 연결 리스트를 출력한다
	void PrintLinkedList(const CLinkedList<int> &a_rValueList) {
		for(int i = 0; i < a_rValueList.getCount(); ++i) {
			printf("%d, ", a_rValueList[i]);
		}

		printf("\n");
	}

	void Example_02(const int argc, const char ** args) {
		CLinkedList<int> oValueList;
		InitLinkedList(oValueList, 10);

		printf("===== 원본 요소 =====\n");
		PrintLinkedList(oValueList);

		oValueList.insertValue(0, 100);

		printf("\n===== 데이터 삽입 후 =====\n");
		PrintLinkedList(oValueList);

		oValueList.removeValue(5);

		printf("\n===== 데이터 제거 후 =====\n");
		PrintLinkedList(oValueList);
	}
}
