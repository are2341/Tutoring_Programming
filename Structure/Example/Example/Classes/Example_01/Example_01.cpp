#include "Example_01.h"
#include "../Global/Utility/Structure/CArrayList.h"

namespace EXAMPLE_01 {
	//! 배열 리스트를 초기화한다
	void InitArrayList(CArrayList<int> &a_rValueList, int a_nNumValues) {
		for(int i = 0; i < a_nNumValues; ++i) {
			a_rValueList.addValue(i + 1);
		}
	}

	//! 배열 리스트를 출력한다
	void PrintArrayList(const CArrayList<int> &a_rValueList) {
		for(int i = 0; i < a_rValueList.getCount(); ++i) {
			printf("%d, ", a_rValueList[i]);
		}

		printf("\n");
	}

	void Example_01(const int argc, const char ** args) {
		CArrayList<int> oValueList;
		InitArrayList(oValueList, 10);

		printf("===== 원본 요소 =====\n");
		PrintArrayList(oValueList);

		oValueList.insertValue(0, 100);

		printf("\n===== 데이터 삽입 후 =====\n");
		PrintArrayList(oValueList);

		oValueList.removeValue(5);

		printf("\n===== 데이터 제거 후 =====\n");
		PrintArrayList(oValueList);
	}
}
