#include "Example_05.h"
#include "../Global/Utility/Structure/CHashTable.h"

namespace EXAMPLE_05 {
	//! 해시 테이블을 초기화한다
	void InitHashTable(CHashTable<int> &a_rHashTable, int a_nNumValues) {
		for(int i = 0; i < a_nNumValues; ++i) {
			a_rHashTable.addValue(i + 1);
		}
	}

	//! 해시 테이블을 출력한다
	void PrintHashTable(const CHashTable<int> &a_rHashTable) {
		a_rHashTable.enumerate([=](const CLinkedList<int> &a_rValueList, int a_nIndex) -> void {
			printf("Index %d: ", a_nIndex);

			for(int i = 0; i < a_rValueList.getCount(); ++i) {
				printf("%d, ", a_rValueList[i]);
			}

			printf("\n");
		});
	}

	void Example_05(const int argc, const char ** args) {
		CHashTable<int> oHashTable;
		InitHashTable(oHashTable, 100);

		printf("===== 해시 테이블 요소 =====\n");
		PrintHashTable(oHashTable);

		int nValue = 0;

		std::cout << std::endl << "정수 입력 : ";
		std::cin >> nValue;

		printf("입력 값 포함 여부 : %d\n", oHashTable.isContains(nValue));
	}
}
