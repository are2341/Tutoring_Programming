#include "Example_05.h"
#include "../Global/Utility/Structure/CHashTable.h"

namespace EXAMPLE_05 {
	void Example_05(const int argc, const char ** args) {
		GLOBAL::CHashTable<int> oHashTable;

		for(int i = 0; i < 100; ++i) {
			oHashTable.AddValue(i + 1);
		}

		oHashTable.EnumerateTable([=](GLOBAL::CLinkedList<int> a_oValueList, int a_nIndex) -> void {
			printf("Slot %d: ", a_nIndex);

			for(int i = 0; i < a_oValueList.getCount(); ++i) {
				printf("%d, ", a_oValueList.getValue(i));
			}

			printf("\n");
		});

		int nValue = 0;
		
		std::cout << std::endl << "정수 입력 : ";
		std::cin >> nValue;

		printf("포함 여부 출력 : %d\n", oHashTable.IsContains(nValue));
	}
}
